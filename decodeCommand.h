//
// Created by Florian Claisse on 08/01/2023.
//

#ifndef CONTIGDIFFERENCE_DECODECOMMAND_H
#define CONTIGDIFFERENCE_DECODECOMMAND_H

#include <stdbool.h>

#include "Foundation/typedef.h"

/**
 * La structure qui stocke toutes les options passé en ligne de commande.
 */
typedef struct {
    cstring pathA; // Le chemin vers le dossier A.
    cstring pathB; // Le chement vers le dossier B.
    cstring pathOutput; // Le chemin vers le dossier de sortie.
    ulong minimumSize; // La taille minimum des contigs a prendre en compte.
    bool reverse; // L'option reverse ou non.
    bool common; // L'option common ou non.
} ProgrammeOption;

/**
 * Decode la ligne de command donnée par l'utilisateur
 * @param argc Le nombre d'élément de la ligne de commande
 * @param argv Les éléments présent dans la ligne de commande.
 * @return Un pointeur si le decodage a fonctionné, NULL dans le cas contraire.
 */
ProgrammeOption* decodeCommand(int argc, cstring argv[]);

/**
 * Affichage le guide d'utilisation du programme.
 */
void usage(void);

#endif //CONTIGDIFFERENCE_DECODECOMMAND_H
