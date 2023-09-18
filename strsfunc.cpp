#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "strsfunc.h"
#include "struct_of_file.h"

size_t my_strlen (const char* str){

    size_t curr_symb = 0;

    while(((*(str + curr_symb)) != '\n') && ((*(str + curr_symb)) != '\0')){

        curr_symb++;
    }

    return curr_symb;
}



int my_strcmp_without_punctuation_Reversed (const void* strings1, const void* strings2){

    const lines_in_file str1 = *(const lines_in_file*) strings1;
    const lines_in_file str2 = *(const lines_in_file*) strings2;

    size_t iterator_str1 = str1.line_lenght - 1;
    size_t iterator_str2 = str2.line_lenght - 1;

    while ((iterator_str1 > 0) && (iterator_str2 > 0)){

        while ((!isalpha(*(str1.strings + iterator_str1))) && (iterator_str1 > 0)){

            iterator_str1--;
        }

        while ((!isalpha(*(str2.strings + iterator_str2))) && (iterator_str2 > 0)){

            iterator_str2--;
        }

        int difference = (*(str1.strings + iterator_str1)) - (*(str2.strings + iterator_str2));

        if (difference > 0){

            return 1;
        }

        if (difference < 0){

            return -1;
        }

        iterator_str1--;
        iterator_str2--;
    }

    if (iterator_str1 > 0){

        return 1;
    }

    if (iterator_str2 > 0){

        return -1;
    }

    return 0;
}



int my_strcmp_without_punctuation_Direct (const void* strings1, const void* strings2){

    const lines_in_file str1 = *(const lines_in_file*) strings1;
    const lines_in_file str2 = *(const lines_in_file*) strings2;

    size_t len_of_str1 = str1.line_lenght;
    size_t len_of_str2 = str2.line_lenght;

    size_t iterator_str1 = 0;
    size_t iterator_str2 = 0;

    while ((iterator_str1 < len_of_str1) && (iterator_str2 < len_of_str2)){

        while ((!isalpha(*(str1.strings + iterator_str1))) && (iterator_str1 < len_of_str1)){

            iterator_str1++;
        }

        while ((!isalpha(*(str2.strings + iterator_str2))) && (iterator_str2 < len_of_str2)){

            iterator_str2++;
        }

        int difference = (*(str1.strings + iterator_str1)) - (*(str2.strings + iterator_str2));

        if (difference > 0){

            return 1;
        }

        if (difference < 0){

            return -1;
        }

        iterator_str1++;
        iterator_str2++;
    }

    return (*(str1.strings+iterator_str1)) - (*(str2.strings+iterator_str2));
}


int my_strcmp_with_punctuation_Direct (const void* strings1, const void* strings2){

    const lines_in_file str1 = *(const lines_in_file*) strings1;
    const lines_in_file str2 = *(const lines_in_file*) strings2;

    size_t len_of_str1 = str1.line_lenght;
    size_t len_of_str2 = str2.line_lenght;

    size_t iterator_str1 = 0;
    size_t iterator_str2 = 0;

    while ((iterator_str1 < len_of_str1) && (iterator_str2 < len_of_str2)){

        int difference = (*(str1.strings + iterator_str1)) - (*(str2.strings + iterator_str2));

        if (difference > 0){

            return 1;
        }

        if (difference < 0){

            return -1;
        }

        iterator_str1++;
        iterator_str2++;
    }

    if (iterator_str2 < len_of_str2){

        return -1;
    }

    if (iterator_str1 < len_of_str1){

        return 1;
    }

     return (*(str1.strings+iterator_str1)) - (*(str2.strings+iterator_str2));
}



int my_strcmp_with_punctuation_Reversed (const void* strings1, const void* strings2){

    const lines_in_file str1 = *(const lines_in_file*) strings1;
    const lines_in_file str2 = *(const lines_in_file*) strings2;

    size_t iterator_str1 = str1.line_lenght - 1;
    size_t iterator_str2 = str2.line_lenght - 1;

    while ((iterator_str1 > 0) && (iterator_str2 > 0)){

        int difference = (*(str1.strings + iterator_str1)) - (*(str2.strings + iterator_str2));

        if (difference > 0){

            return 1;
        }

        if (difference < 0){

            return -1;
        }

        iterator_str1--;
        iterator_str2--;
    }

    if (iterator_str1 > 0){

            return 1;
    }

    if (iterator_str2 > 0){

        return -1;
    }

    return 0;
}
