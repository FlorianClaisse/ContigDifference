//
// Created by Florian Claisse on 10/01/2023.
//

#ifndef CONTIGDIFFERENCE_STRING_H
#define CONTIGDIFFERENCE_STRING_H

#include "../typedef.h"

typedef struct String String;

String* String_init(cstring chaine);
void String_free(String *chaine);
ulong String_size(String *chaine);
cstring String_get(String *chaine);
void String_print(String *chaine);

#endif //CONTIGDIFFERENCE_STRING_H
