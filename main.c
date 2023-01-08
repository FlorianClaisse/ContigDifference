#include <stdlib.h>

#include "decodeCommand.h"

// ./contigdiff --inputA /Users/... --inputB /Users/.. --output /Users/... [--reverse] [--common]

int main(int argc, const char* argv[]) {

    ProgrammeOption *programmeOption = decodeCommand(argc, argv);
    if (programmeOption == NULL) {
        usage();
        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}
