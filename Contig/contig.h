#ifndef CONTIGDIFFERENCE_CONTIG_H
#define CONTIGDIFFERENCE_CONTIG_H

#include "Foundation/Array/String/StringArray.h"
#include "Foundation/typedef.h"

/**
 * Permet de trouver tous les mots commun a partie d'un fichier et d'une multitude d'autre fichiers.
 * @param allFiles Tous les fichiers.
 * @return La liste des mots commun trouvé.
*/
StringArray* findCommon(StringArray *allfiles);

#endif