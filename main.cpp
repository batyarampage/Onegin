#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>



size_t my_strlen (const char* str, size_t* curr_symb);

size_t filesize (char file_name[]);

void read_text_from_tile (size_t filesize, char file_name[], char* strings_of_file);

void whitespace_hatching_and_replacing_on_0 (char* strings_of_file, size_t curr_file_size,
                                             size_t curr_size_of_ptr_on_enter,char** ptr_on_enter_in_strings,
                                             size_t* curr_line);

int my_reversed_strcmp (const void* str1, const void* str2);

void my_qsort (char** data, size_t curr_strlen, size_t size_of_type, int (*comparator));



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

int my_reversed_strcmp (const void* strings1, const void* strings2){

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

        if ((*str1) > (*str2)){

            return 1;
        }

        if ((*str1) < (*str2)){

            return -1;
        }

        return 0;
    }
}

void my_qsort (char** data, size_t curr_strlen, size_t size_of_type, int (*comparator)){

    assert(data);



}


size_t filesize (char file_name[]){

    struct stat st = {};
    stat(file_name, &st);

    size_t size_of_file = st.st_size;

    printf("%u\n", size_of_file);

    return size_of_file;
}

void read_text_from_tile (size_t filesize, char file_name[], char* strings_of_file){

    FILE *file = fopen(file_name, "r");

    fread(strings_of_file, (size_t) filesize, 1, file);

    fclose(file);
}

void whitespace_hatching_and_replacing_on_0 (char* strings_of_file, size_t curr_file_size,
                                             size_t curr_size_of_ptr_on_enter,char** ptr_on_enter_in_strings,
                                             size_t* curr_line){

    assert(ptr_on_enter_in_strings != nullptr);
    assert(strings_of_file != nullptr);

    *ptr_on_enter_in_strings = strings_of_file;

    for (size_t i = 0; i < curr_file_size; i++){

        if ((*(strings_of_file + i)) == '\n'){

            /*if (curr_line + 1 >= *curr_size_of_ptr_on_enter){

                *curr_size_of_ptr_on_enter *= 2;

                ptr_on_enter_in_strings = (char**) realloc (ptr_on_enter_in_strings, (*curr_size_of_ptr_on_enter) * sizeof(char*));
            }*/

            *(ptr_on_enter_in_strings + (*curr_line)) = (strings_of_file + i + 1);

            (*curr_line)++;

            *(strings_of_file + i) = '\0';
        }
    }
}


int main (){

    char file_name[] = "onegin1.txt";
    size_t curr_file_size = filesize(file_name);

    char* strings_of_file = (char *) calloc(curr_file_size, sizeof(char));
    read_text_from_tile(curr_file_size, file_name,strings_of_file);

    char** ptr_on_enter_in_strings = (char **) calloc(curr_file_size, sizeof(char));

    size_t curr_line = 1;
    whitespace_hatching_and_replacing_on_0 (strings_of_file, curr_file_size,
                                            curr_file_size, ptr_on_enter_in_strings,
                                            &curr_line);





    for (size_t i = 0; i < curr_line; i++){

        printf("%s\n", *(ptr_on_enter_in_strings+i));
    }

    qsort(ptr_on_enter_in_strings, curr_line, sizeof(char*), my_reversed_strcmp);

    for (size_t i = 0; i < curr_line; i++){

        printf("%s\n", *(ptr_on_enter_in_strings+i));
    }


    free(strings_of_file);
    free(ptr_on_enter_in_strings);




    /*char str1[] = ",ramp,ageless,";
    char str2[] = "rampage,,,,,,,,,,,,,,,, ,,lesss,,";
    char str3[] = "vvver";
    char str4[] = "vertu";
    char str5[] = "sdfhsiuf";

    char* strs[5] = {str1, str2, str3, str4, str5};

    for (int i = 0; i < 5; i++){

        printf("%s\n", strs[i]);
    }

    printf("--------------------\n");

    qsort(strs, 5, sizeof(char*),my_reversed_strcmp);

    for (int i = 0; i < 5; i++){

        printf("%s\n", strs[i]);
    }*/




    //printf("%d", (long long) (str[0]+str[1]+str[2]+str[3]+str[4]+str[5]+str[6]+str[7] + str[8]));

    return 0;
}
