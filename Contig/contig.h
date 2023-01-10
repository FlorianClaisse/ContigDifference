//
// Created by Florian Claisse on 10/01/2023.
//

#ifndef CONTIGDIFFERENCE_CONTIG_H
#define CONTIGDIFFERENCE_CONTIG_H

#include "../Utils/typedef.h"
#include "../Utils/String/String.h"

typedef struct {
    cstring id;
    String *chaine;
} Contig;

Contig** Contig_decoder(cstring file_path);

#endif //CONTIGDIFFERENCE_CONTIG_H
