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



struct reading_from_file {

    size_t filesize = 0;

    char* file_name = nullptr;

    char* strings_of_the_file = nullptr;

    char** ptr_on_enter_in_strings = nullptr;

    size_t count_of_lines_in_file = 1;

};


size_t my_strlen (const char* str, size_t* curr_symb);

void filesize (struct reading_from_file* parameters_of_file);

void read_text_from_tile (struct reading_from_file* parameters_of_file);

void whitespace_hatching_and_replacing_on_0 (struct reading_from_file* parameters_of_file);

void read_sort_and_file_output (struct reading_from_file* parameters_of_file);





void filesize (struct reading_from_file* parameters_of_file){

    struct stat st = {};
    stat(parameters_of_file->file_name, &st);

    size_t size_of_file = st.st_size;

    parameters_of_file->filesize = size_of_file;
}



void read_text_from_tile (struct reading_from_file* parameters_of_file){

    FILE *file = fopen(parameters_of_file->file_name, "r");

    printf("%s\n",parameters_of_file->file_name);

    fread(parameters_of_file->strings_of_the_file, (size_t) parameters_of_file->filesize, 1, file);

    fclose(file);
}



void whitespace_hatching_and_replacing_on_0 (struct reading_from_file* parameters_of_file){

    *(parameters_of_file->ptr_on_enter_in_strings) = parameters_of_file->strings_of_the_file;

    for (size_t i = 0; i < parameters_of_file->filesize; i++){

        if ((*(parameters_of_file->strings_of_the_file + i)) == '\n'){

            *(parameters_of_file->ptr_on_enter_in_strings + (parameters_of_file->count_of_lines_in_file)) = (parameters_of_file->strings_of_the_file + i + 1);

            (parameters_of_file->count_of_lines_in_file)++;

            *(parameters_of_file->strings_of_the_file + i) = '\0';
        }
    }
}

void printer_of_file(struct reading_from_file* parameters_of_file){

    for (size_t i = 0; i < parameters_of_file->count_of_lines_in_file; i++){

        printf("%s\n", *(parameters_of_file->ptr_on_enter_in_strings + i));
    }
}

void destruct_dynamic_elements (char** ptr_on_enter_in_strings, char* strings_of_file, size_t count_of_lines){

    free(strings_of_file);

    for (size_t i = 0; i < count_of_lines; i++){

        free(*(ptr_on_enter_in_strings + i));
    }

    free(ptr_on_enter_in_strings);
}

void read_sort_and_file_output (struct reading_from_file* parameters_of_file){

    filesize(parameters_of_file);

    char* strings_of_file = (char *) calloc(parameters_of_file->filesize, sizeof(char));

    parameters_of_file->strings_of_the_file = strings_of_file;

    read_text_from_tile (parameters_of_file);

    char** ptr_on_enter_in_strings = (char **) calloc(parameters_of_file->filesize, sizeof(char));

    parameters_of_file->ptr_on_enter_in_strings = ptr_on_enter_in_strings;

    whitespace_hatching_and_replacing_on_0 (parameters_of_file);

    qsort(parameters_of_file->ptr_on_enter_in_strings, parameters_of_file->count_of_lines_in_file, sizeof(char*), my_strcmp_without_punctuation_Direct);

    printer_of_file(parameters_of_file);

    destruct_dynamic_elements(ptr_on_enter_in_strings, strings_of_file, parameters_of_file->count_of_lines_in_file);

}





int main (){

    struct reading_from_file parameters_of_file = {};

    char file_name[] = "onegineugene.txt";

    parameters_of_file.file_name = file_name;

    read_sort_and_file_output (&parameters_of_file);

    /*char str1[] = "rampageless";
    char str2[] = "difference";
    char str3[] = "rampagelezs";
    char str4[] = "sjsdhfo";
    char str5[] = "zxc";

    char* strs[5] = {str1, str2, str3, str4, str5};*/

    //for (int i = 0; i<5;i++){
    //
    //    printf("%s\n", strs[i]);
    //}

    //qsort(strs,5, sizeof(char*),my_strcmp_with_punctuation_Reversed);

    //for (int i = 0; i<5;i++){
    //
    //    printf("%s\n", strs[i]);
    //}

    //printf("%d\n", my_strcmp_with_punctuation_Direct(str2,str3));

    return 0;
}
