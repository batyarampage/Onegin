#ifndef strsfunc
#define strsfunc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int my_strcmp_without_punctuation_Reversed (const void* strings1, const void* strings2);

int my_strcmp_without_punctuation_Direct (const void* strings1, const void* strings2);

int my_strcmp_with_punctuation_Direct (const void* strings1, const void* strings2);

int my_strcmp_with_punctuation_Reversed (const void* strings1, const void* strings2);

size_t my_strlen (const char* str);

#endif
