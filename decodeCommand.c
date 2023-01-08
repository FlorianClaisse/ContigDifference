//
// Created by Florian Claisse on 08/01/2023.
//

#include <stdlib.h>
#include <string.h>

#include "Foundation/Directory.h"
#include "decodeCommand.h"

#define INPUTA "--inputA"
#define INPUTB "--inputB"
#define OUTPUT "--output"
#define REVERSE "--reverse"
#define COMMON "--common"

ProgrammeOption* init(cstring inputA, cstring inputB, cstring output, bool reverse, bool common) {
    if (!directoryExists(inputA)) { return NULL; }
    if (!directoryExists(inputB)) { return NULL; }
    if (!directoryExists(output) && createDirectory(output) == -1) { return NULL; }

    ProgrammeOption* programmeOption = malloc(sizeof(ProgrammeOption));
    ASSERT(programmeOption != NULL, "Impossible d'allouer de la mémoire.")

    return NULL;
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

}
