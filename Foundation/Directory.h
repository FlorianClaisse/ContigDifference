//
// Created by Florian Claisse on 08/01/2023.
//

#ifndef CONTIGDIFFERENCE_DIRECTORY_H
#define CONTIGDIFFERENCE_DIRECTORY_H

#include <stdbool.h>

#include "typedef.h"

/**
 * Verifie si le dossier existe.
 * @param path Le chemin vers le dossier en question.
 * @return true si le dossier existe, false sinon.
 */
bool directoryExists(cstring path);

/**
 * Crée un dossier à l'emplacement indiqué
 * @param path Le chemin contenant le nom du dossier à créer.
 * @return 0 si le dossier a pu être crée, -1 sinon.
 */
int createDirectory(cstring path);

#endif //CONTIGDIFFERENCE_DIRECTORY_H
