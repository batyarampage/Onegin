#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include "strsfunc.h"

size_t my_strlen (const char* str, size_t* curr_symb){

    size_t lenght = 0;

    while((*(str + *curr_symb) != '\n') && (*(str + *curr_symb) != '\0')){

        if (isalpha(*(str + *curr_symb))){

            lenght++;
        }

        (*curr_symb)++;
    }

    return lenght;
}



int my_strcmp_without_punctuation_Reversed (const void* strings1, const void* strings2){

    const char* str1 = (const char*) strings1;
    const char* str2 = (const char*) strings2;

    //printf("aboba\n");

    size_t len_of_str1 = 0;
    size_t len_of_str2 = 0;

    size_t len_of_str1_without_spec = my_strlen(str1, &len_of_str1);
    size_t len_of_str2_without_spec = my_strlen(str2, &len_of_str2);

    //printf("len_of_str1_without_spec %u\n",len_of_str1_without_spec);
    //printf("len_of_str2_without_spec %u\n",len_of_str2_without_spec);
    //printf("len_of_str1 %u\n",len_of_str1);
    //printf("len_of_str2 %u\n",len_of_str2);

    if (len_of_str1_without_spec > len_of_str2_without_spec){

        return 1;
    }

    else if (len_of_str1_without_spec < len_of_str2_without_spec){

        return -1;
    }

    else {

        size_t iterator_str1 = len_of_str1 - 1;
        size_t iterator_str2 = len_of_str2 - 1;

        while ((*(str1 + iterator_str1)) && (*(str2 + iterator_str2)) && (iterator_str1 > 0) && (iterator_str2 > 0)){

            while ((!isalpha(*(str1 + iterator_str1))) && (*(str1 + iterator_str1)) && (iterator_str1 > 0)){

                iterator_str1--;
            }

            while ((!isalpha(*(str2 + iterator_str2))) && (*(str2 + iterator_str2)) && (iterator_str2 > 0)){

                iterator_str2--;
            }

            int difference = (*(str1 + iterator_str1)) - (*(str2 + iterator_str2));

            //printf("*(str1) %c\n", *(str1 + iterator_str1));
            //printf("*(str2) %c\n", *(str2 + iterator_str2));
            //printf("----------------------------------\n");

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
}

int my_strcmp_without_punctuation_Direct (const void* strings1, const void* strings2){

    const char* str1 = *(const char* const*) strings1;
    const char* str2 = *(const char* const*) strings2;

    size_t len_of_str1 = 0;
    size_t len_of_str2 = 0;

    size_t len_of_str1_without_spec_symb = my_strlen(str1, &len_of_str1);
    size_t len_of_str2_without_spec_symb = my_strlen(str2, &len_of_str2);

    //printf("len_of_str1_without_spec %u\n",len_of_str1_without_spec);
    //printf("len_of_str2_without_spec %u\n",len_of_str2_without_spec);
    //printf("len_of_str1 %u\n",len_of_str1);
    //printf("len_of_str2 %u\n",len_of_str2);

    if (len_of_str1_without_spec_symb > len_of_str2_without_spec_symb){

        return 1;
    }

    else if (len_of_str1_without_spec_symb < len_of_str2_without_spec_symb){

        return -1;
    }

    else {

        size_t iterator_str1 = 0;
        size_t iterator_str2 = 0;

        while ((*(str1 + iterator_str1)) && (*(str2 + iterator_str2)) && (iterator_str1 < len_of_str1) && (iterator_str2 < len_of_str2)){

            while ((!isalpha(*(str1 + iterator_str1))) && (*(str1 + iterator_str1)) && (iterator_str1 < len_of_str1)){

                iterator_str1++;
            }

            while ((!isalpha(*(str2 + iterator_str2))) && (*(str2 + iterator_str2)) && (iterator_str2 < len_of_str2)){

                iterator_str2++;
            }

            int difference = (*(str1 + iterator_str1)) - (*(str2 + iterator_str2));

            //printf("*(str1) %c\n", *(str1 + iterator_str1));
            //printf("*(str2) %c\n", *(str2 + iterator_str2));
            //printf("----------------------------------\n");

            if (difference > 0){

                return 1;
            }

            if (difference < 0){

                return -1;
            }

            iterator_str1++;
            iterator_str2++;
        }


    }


}

int my_strcmp_with_punctuation_Direct (const void* strings1, const void* strings2){

    const char* str1 = *(const char* const*) strings1;
    const char* str2 = *(const char* const*) strings2;

    //size_t len_of_str1 = 0;
    //size_t len_of_str2 = 0;

    //size_t len_of_str1_without_spec_symb = my_strlen(str1, &len_of_str1);
    //size_t len_of_str2_without_spec_symb = my_strlen(str2, &len_of_str2);

    //printf("len_of_str1_without_spec %u\n",len_of_str1_without_spec_symb);
    //printf("len_of_str2_without_spec %u\n",len_of_str2_without_spec_symb);
    //printf("len_of_str1 %u\n",len_of_str1);
    //printf("len_of_str2 %u\n",len_of_str2);

    size_t iterator_str1 = 0;
    size_t iterator_str2 = 0;

    while ((*(str1 + iterator_str1)) && (*(str2 + iterator_str2))){

        int difference = (*(str1 + iterator_str1)) - (*(str2 + iterator_str2));

        if (difference > 0){

            return 1;
        }

        if (difference < 0){

            return -1;
        }

        iterator_str1++;
        iterator_str2++;
    }

    return 0;
}

int my_strcmp_with_punctuation_Reversed (const void* strings1, const void* strings2){

    const char* str1 = (const char*) strings1;
    const char* str2 = (const char*) strings2;

    size_t len_of_str1 = 0;
    size_t len_of_str2 = 0;

    size_t len_of_str1_without_spec = my_strlen(str1, &len_of_str1);
    size_t len_of_str2_without_spec = my_strlen(str2, &len_of_str2);

    size_t iterator_str1 = len_of_str1 - 1;
    size_t iterator_str2 = len_of_str2 - 1;

    printf("iter 1 bef %u\n", iterator_str1);
    printf("iter 2 bef %u\n", iterator_str2);

    while ((*(str1 + iterator_str1)) && (*(str2 + iterator_str2)) && (iterator_str1 > 0) && (iterator_str2 > 0)){

        int difference = (*(str1 + iterator_str1)) - (*(str2 + iterator_str2));

        if (difference > 0){

            return 1;
        }

        if (difference < 0){

            return -1;
        }

        iterator_str1--;
        iterator_str2--;
    }

    printf("iter 1 %u\n", iterator_str1);
    printf("iter 2 %u\n", iterator_str2);


    return 0;
}
