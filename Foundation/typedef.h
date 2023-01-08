//
// Created by Florian Claisse on 08/01/2023.
//

#ifndef CONTIGDIFFERENCE_TYPEDEF_H
#define CONTIGDIFFERENCE_TYPEDEF_H

#include <stdlib.h>
#include <stdio.h>

#define ASSERT(expr, msg)                                           \
    do {                                                            \
        if (!(expr)) {                                              \
            printf("%s: %s (ligne: %d)\n", #expr, msg, __LINE__);    \
            abort();                                                \
        }                                                           \
    } while(0);

typedef char* string;
typedef const char* cstring;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

#endif //CONTIGDIFFERENCE_TYPEDEF_H
