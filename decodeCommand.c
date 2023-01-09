//
// Created by Florian Claisse on 08/01/2023.
//

#include <stdlib.h>
#include <string.h>

#include "Foundation/directory.h"
#include "decodeCommand.h"

#define INPUTA "--inputA"
#define INPUTB "--inputB"
#define OUTPUT "--output"
#define REVERSE "--reverse"
#define COMMON "--common"

ProgrammeOption* init(cstring inputA, cstring inputB, cstring output, bool reverse, bool common) {
    if (!directoryExists(inputA)) {
        printf("Le dossier %s n'existe pas.\n", inputA);
        return NULL;
    }
    if (!directoryExists(inputB)) {
        printf("Le dossier %s n'existe pas.\n", inputB);
        return NULL;
    }
    if (!directoryExists(output) && createDirectory(output) == -1) {
        printf("Impossible de créer le dossier %s.\n", output);
        return NULL;
    }

    ProgrammeOption* programmeOption = malloc(sizeof(ProgrammeOption));
    ASSERT(programmeOption != NULL, "Impossible d'allouer de la mémoire.")

    programmeOption->pathA = inputA;
    programmeOption->pathB = inputB;
    programmeOption->pathOutput = output;
    programmeOption->reverse = reverse;
    programmeOption->common = common;

    return programmeOption;
}

ProgrammeOption* decodeCommand(int argc, cstring argv[]) {
    // ./contigdiff --inputA /Users/... --inputB /Users/.. --output /Users/... [--reverse] [--common]

    if (argc < 7 || argc > 9) { return NULL; }

    if (strcmp(argv[1], INPUTA) != 0) { return NULL; }
    if (strcmp(argv[3], INPUTB) != 0) { return NULL; }
    if (strcmp(argv[5], OUTPUT) != 0) { return NULL; }

    bool common = false;
    bool reverse = false;

    if (argc >= 8) {
        // check --common and --reverse
        if (strcmp(argv[7], REVERSE) == 0) { reverse = true; }
        else if (strcmp(argv[7], COMMON) == 0) { common = true; }
        else { return NULL; }

        if (argc == 9) {
            if (strcmp(argv[8], REVERSE) == 0 && !reverse) { reverse = true; }
            else if (strcmp(argv[8], COMMON) == 0 && !common) { common = true; }
            else { return NULL; }
        }
    }

    return init(argv[2], argv[4], argv[6], reverse, common);
}

void usage() {
    printf("NAME\n");
    printf("\tContigDifference\n");
    printf("\nSYNOPSIS\n");
    printf("\tContigDifference %s <path> %s <path> %s <path> [%s] [%s]\n", INPUTA, INPUTB, OUTPUT, REVERSE, COMMON);
    printf("\nDESCRIPTION\n");
    printf("\t%s <path>\t\tLe chemin vers le dossier A.\n", INPUTA);
    printf("\n\t%s <path>\t\tLe chemin vers le dossier B.\n", INPUTB);
    printf("\n\t%s <path>\t\tLe chemin vers le dossier de sortie celui-ci peut ne pas exister il sera crée.\n", OUTPUT);
    printf("\n\t%s\t\tCette option permet d'appliquer le programme une seconde fois en inversant l'ordre des dossier A et B\n", REVERSE);
    printf("\n\t%s\t\tCette option permet de spécifier que l'on veut les chaines commune présente dans tous le dossier A.\n", COMMON);
}
