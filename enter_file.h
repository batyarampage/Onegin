#ifndef enter_file
#define enter_file

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

void filesize (struct reading_from_file* parameters_of_file);

void read_text_from_tile (struct reading_from_file* parameters_of_file);

void whitespace_hatching_and_replacing_on_0 (struct reading_from_file* parameters_of_file);

void printer_of_file(struct reading_from_file* parameters_of_file);

void destruct_dynamic_elements (char** ptr_on_enter_in_strings, char* strings_of_file, size_t count_of_lines);

void read_sort_and_file_output (struct reading_from_file* parameters_of_file);

#endif
