//
// Created by Florian Claisse on 08/01/2023.
//

#include "StringArray.h"

#include <string.h>

#define INITIAL_CAPACITY 2

struct StringArray {
    ulong size;
    ulong currentIndex;
    string *array;
};

StringArray* SA_init() {
    StringArray *array = malloc(sizeof(StringArray));
    ASSERT(array != NULL, "Impossible d'allouer de la mémoire.")

    array->array = malloc(sizeof(string) * INITIAL_CAPACITY);
    ASSERT(array->array != NULL, "Impossible d'allouer de la mémoire.")

    array->size = INITIAL_CAPACITY;
    array->currentIndex = 0;

    return array;
}

void SA_free(StringArray *array) {
    for (ulong i = 0; i < array->currentIndex; i++) {
        free(array->array[i]);
    }
    free(array->array);
    free(array);
}

ulong SA_size(StringArray *array) { return array->size; }

ulong SA_count(StringArray *array) { return array->currentIndex; }

void SA_add(string element, StringArray *array) {
    if (array->currentIndex >= array->size) {
        // update size
        ulong size = array->size;
        string *newArray = malloc(sizeof(string) * (size * 2));
        ASSERT(newArray != NULL, "Impossible d'allouer de la mémoire.")
        for (ulong i = 0; i < array->currentIndex; i++) {
            newArray[i] = array->array[i];
        }
        free(array->array);
        array->array = newArray;
        array->size = size * 2;
    }

    string newValue = malloc(sizeof(char) * strlen(element) + 1);
    strcpy(newValue, element);
    array->array[array->currentIndex] = newValue;
    array->currentIndex++;
}

void SA_update(ulong index, string element, StringArray *array) {
    if (array == NULL || array->array == NULL || index >= array->currentIndex) {
        printf("RuntimeError: String Array index %lu is out of bounds, Accepted indices [0-%lu]\n", index, array->currentIndex - 1);
        exit(EXIT_FAILURE);
    }

    free(array->array[index]);
    string string1 = malloc(sizeof(char) * strlen(element) + 1);
    strcpy(string1, element);
    array->array[index] = string1;
}

string SA_get(ulong index, StringArray *array) {
    if (array == NULL || array->array == NULL || index >= array->currentIndex) {
        printf("RuntimeError: String Array index %lu is out of bounds, Accepted indices [0-%lu]\n", index, array->currentIndex - 1);
        exit(EXIT_FAILURE);
    }

    return array->array[index];
}

void SA_print(StringArray *array) {
    printf("[");
    for (ulong i = 0; i < array->currentIndex; i++) {
        if (i == 20 && array->currentIndex > 100) {
            i = array->currentIndex - 20;
            printf("... ");
        }
        printf("%s", array->array[i]);
        if (i != array->currentIndex - 1) { printf(", "); }
    }
    printf("]\n");
}