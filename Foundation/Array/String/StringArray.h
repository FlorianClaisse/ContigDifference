//
// Created by Florian Claisse on 08/01/2023.
//

#ifndef CONTIGDIFFERENCE_STRINGARRAY_H
#define CONTIGDIFFERENCE_STRINGARRAY_H

#include "../../typedef.h"

typedef struct StringArray StringArray;

/**
 * Initiale un tableau de chaine de caractere.
 * @return Un pointeur vers le tableau nouvellement crée.
 */
StringArray* SA_init();

/**
 * Libère la mémoire du tableau.
 * @param array La tableau que l'on veut supprimer de la mémoire.
 */
void SA_free(StringArray *array);

/**
 * Permet de récupérer la taille maximum du tableau.
 * @param array Le tableau dont on veut connaitre la taille.
 * @return La taille du tableau en question.
 */
ulong SA_size(StringArray *array);

/**
 * Permet de récupérer le nombre d'élèment dans un tableau.
 * @param array Le tableau dont on veut connaitre le nombre d'élèment.
 * @return Le nombre d'élèment dans le tableau.
 */
ulong SA_count(StringArray *array);

/**
 * Ajout un élèment à la suite du dernier élément dans le tableau.
 * Si jamais la taille du tableau n'est pas suffisant, alors ça taille est doublé.
 * @param element L'élèment a ajouter dans le tableau.
 * @param array Le tableau ou l'on veut ajouter l'élèment.
 */
void SA_add(string element, StringArray *array);

/**
 * Change la valeur d'un élèment dans le tableau.
 * @param index La position de l'élèment que l'on veut changer.
 * @param element La nouvelle valeur a ajouter.
 * @param array Le tableau en question.
 */
void SA_update(ulong index, string element, StringArray *array);

/**
 * Permet de récupérer un élément dans un tableau.
 * @param index La position de l'élèment que l'on veut récupérer.
 * @param array Le tableau en question.
 * @return L'élèment trouvé, NULL si aucun élèment n'est trouvé a cette position.
 */
string SA_get(ulong index, StringArray *array);

/**
 * Affiche sur la sortie standard le contenue du tableau.
 * @param array Le tableau dont on veut afficher le contenue.
 */
void SA_print(StringArray *array);

#endif //CONTIGDIFFERENCE_STRINGARRAY_H
