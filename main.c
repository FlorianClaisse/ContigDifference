#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "Foundation/directory.h"
#include "Foundation/Array/String/StringArray.h"
#include "decodeCommand.h"

// ./contigdiff --inputA /Users/... --inputB /Users/.. --output /Users/... --mininmum <value> [--reverse] [--common]

int main(int argc, const char* argv[]) {

    // Verifier la ligne de commande
    ProgrammeOption *programmeOption = decodeCommand(argc, argv);
    if (programmeOption == NULL) {
        usage();
        return EXIT_SUCCESS;
    }

    // Recuperer la liste de tous les fichiers .fasta dans les dossier A et B
    StringArray *filesA = findFiles(programmeOption->pathA, "fasta");
    StringArray *filesB = findFiles(programmeOption->pathB, "fasta");

    // Trouver tous les mots commun a A.


    return EXIT_SUCCESS;
}
