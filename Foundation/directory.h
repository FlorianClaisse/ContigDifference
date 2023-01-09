//
// Created by Florian Claisse on 08/01/2023.
//

#ifndef CONTIGDIFFERENCE_DIRECTORY_H
#define CONTIGDIFFERENCE_DIRECTORY_H

#include <stdbool.h>

#include "Array/String/StringArray.h"
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

/**
 * Permet de recuperer l'extension d'un fichier sans le '.'
 * @param filename Le nom du fichier a considerer.
 * @return L'extension du fichier ou une chaine vide si l'extension n'est pas troouvé.
 */
cstring filenameExtension(cstring filename);

/**
 * Genere le chemin complet d'un fichier donnée
 * @param path Le chemin pour acceder au fichier
 * @param filename Le nom du fichier contenue dans le dossier
 * @return Le chemin complet du fichier
 */
string fileFullPath(cstring path, cstring filename);

/**
 * Dans un dossier, trouve tous les fichier avec l'extension specifié en parametre.
 * La valeur retourné est un tableau de chaine de caractére avec le chemin complet d'acces au fichier.
 * @param path Le chemin vers le dossier.
 * @param extension L'extension des fichiers a trouver.
 * @return Un tableau contenant les chemin absolu des fichiés trouvé.
 */
StringArray* findFiles(cstring path, cstring extension);

#endif //CONTIGDIFFERENCE_DIRECTORY_H
