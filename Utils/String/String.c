//
// Created by Florian Claisse on 10/01/2023.
//

#include "String.h"

#include <string.h>

struct String {
    ulong size;
    string chaine;
};

String* String_init(cstring chaine) {
    String *new_string = malloc(sizeof(String));
    ASSERT(new_string != NULL, "Impossible d'allouer de la mémoire.")

    ulong chaine_size = strlen(chaine);
    string new_chaine = malloc(sizeof(char) * chaine_size + 1);
    ASSERT(new_chaine != NULL, "Impossible d'allouer de la mémoire.")

    strcpy(new_chaine, chaine);

    new_string->size = chaine_size;
    new_string->chaine = new_chaine;

    return new_string;
}

void String_free(String *chaine) {
    free(chaine->chaine);
    free(chaine);
}

ulong String_size(String *chaine) { return chaine->size; }

cstring String_get(String *chaine) { return chaine->chaine; }

void String_print(String *chaine) {
    printf("String{size: %lu, chaine: %s\n", chaine->size, chaine->chaine);
}