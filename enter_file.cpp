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
#include "struct_of_file.h"
#include "enter_file.h"

void read_file (struct reading_from_file* parameters_of_file){

    filesize(parameters_of_file);

    char* strings_of_file = (char *) calloc(parameters_of_file->filesize, sizeof(char));

    parameters_of_file->strings_of_the_file = strings_of_file;

    FILE *file = fopen(parameters_of_file->file_name, "r");

    assert(file != nullptr);

    fread(parameters_of_file->strings_of_the_file, (size_t) parameters_of_file->filesize, 1, file);

    fclose(file);

    counter_of_lines (parameters_of_file);

    printf("count of lines %u\n", parameters_of_file->count_of_lines_in_file);

    lines_in_file* array_of_strings_in_file = (lines_in_file*) calloc(parameters_of_file->count_of_lines_in_file, sizeof(lines_in_file));

    parameters_of_file->ptr_on_enter_in_strings = array_of_strings_in_file;

    fill_array_of_strings (parameters_of_file);
}



void fill_array_of_strings (struct reading_from_file* parameters_of_file){

    parameters_of_file->ptr_on_enter_in_strings->strings = parameters_of_file->strings_of_the_file;

    size_t first_string_lenght = my_strlen(parameters_of_file->strings_of_the_file);

    parameters_of_file->ptr_on_enter_in_strings->line_lenght = first_string_lenght;

    for (size_t i = 0; i < parameters_of_file->filesize; i++){

        if ((*(parameters_of_file->strings_of_the_file + i)) == '\n'){

            (parameters_of_file->ptr_on_enter_in_strings + (parameters_of_file->current_count_of_lines_in_file))->strings = (parameters_of_file->strings_of_the_file + i + 1);

            (parameters_of_file->ptr_on_enter_in_strings + (parameters_of_file->current_count_of_lines_in_file))->line_lenght = (size_t) (parameters_of_file->ptr_on_enter_in_strings + (parameters_of_file->current_count_of_lines_in_file))->strings
                                                                                                                                 - (size_t) (parameters_of_file->ptr_on_enter_in_strings + (parameters_of_file->current_count_of_lines_in_file) - 1)->strings - 1;

            (*(parameters_of_file->strings_of_the_file + i)) = '\0';

            (parameters_of_file->current_count_of_lines_in_file)++;
        }
    }
}







void filesize (struct reading_from_file* parameters_of_file){

    struct stat st = {};
    stat(parameters_of_file->file_name, &st);

    size_t size_of_file = st.st_size;

    parameters_of_file->filesize = size_of_file;
}


 /*
void read_text_from_tile (struct reading_from_file* parameters_of_file){

    FILE *file = fopen(parameters_of_file->file_name, "r");

    assert(file != nullptr);

    size_t aboba = fread(parameters_of_file->strings_of_the_file, (size_t) parameters_of_file->filesize, 1, file);

    printf("aboba %u\n", aboba);

    fclose(file);
}   */



/*void whitespace_hatching_and_replacing_on_0 (struct reading_from_file* parameters_of_file){

    *(parameters_of_file->ptr_on_enter_in_strings) = parameters_of_file->strings_of_the_file;

    for (size_t i = 0; i < parameters_of_file->filesize; i++){

        if ((*(parameters_of_file->strings_of_the_file + i)) == '\n'){

            (*(parameters_of_file->ptr_on_enter_in_strings + (parameters_of_file->current_count_of_lines_in_file)))->strings = (parameters_of_file->strings_of_the_file + i + 1);

            (parameters_of_file->current_count_of_lines_in_file)++;

            *(parameters_of_file->strings_of_the_file + i) = '\0';
        }
    }
}*/

void printer_of_file(struct reading_from_file* parameters_of_file){

    FILE *file_output = fopen("out.txt", "a+");

    assert(file_output != nullptr);

    for (size_t i = 0; i < parameters_of_file->count_of_lines_in_file; i++){

        fprintf(file_output, "%s\n", (parameters_of_file->ptr_on_enter_in_strings + i)->strings);
    }

    fclose(file_output);
}

void destruct_dynamic_elements (char** ptr_on_enter_in_strings, char* strings_of_file){

    free(strings_of_file);

    free(ptr_on_enter_in_strings);
}

/*void write_in_file(struct reading_from_file* parameters_of_file){

    FILE *file_output = fopen("out.txt", "a+");

    assert(file_output != nullptr);

    for (size_t i = 0; i < parameters_of_file->count_of_lines_in_file; i++){

        fprintf(file_output, "%s\n", *(parameters_of_file->ptr_on_enter_in_strings + i));//TODO  заменить \0 на \n
    }

    fclose(file_output);
} */

void counter_of_lines(struct reading_from_file* parameters_of_file){

    printf("%u\n",parameters_of_file->filesize);

    for (size_t i = 0; i < parameters_of_file->filesize; i++){

        if ((*(parameters_of_file->strings_of_the_file + i)) == '\n'){

            parameters_of_file->count_of_lines_in_file++;
        }
    }
}


/*void read_sort_and_file_output (struct reading_from_file* parameters_of_file){

    filesize(parameters_of_file);

    char* strings_of_file = (char *) calloc(parameters_of_file->filesize, sizeof(char));

    parameters_of_file->strings_of_the_file = strings_of_file;

    read_text_from_tile (parameters_of_file);

    counter_of_lines(parameters_of_file);

    char** ptr_on_enter_in_strings = (char **) calloc(parameters_of_file->count_of_lines_in_file, sizeof(char*));

    parameters_of_file->ptr_on_enter_in_strings = ptr_on_enter_in_strings;

    whitespace_hatching_and_replacing_on_0 (parameters_of_file);

    qsort(parameters_of_file->ptr_on_enter_in_strings, parameters_of_file->count_of_lines_in_file, sizeof(char*), my_strcmp_without_punctuation_Reversed);

    //printer_of_file(parameters_of_file);

    write_in_file(parameters_of_file);

    destruct_dynamic_elements(ptr_on_enter_in_strings, strings_of_file);

} */
