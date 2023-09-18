#ifndef enter_file
#define enter_file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include <ctype.h>
#include "strsfunc.h"
#include "struct_of_file.h"

void read_file (struct reading_from_file* parameters_of_file);

void fill_array_of_strings (struct reading_from_file* parameters_of_file);

void filesize (struct reading_from_file* parameters_of_file);

void printer_of_file(struct reading_from_file* parameters_of_file);

void counter_of_lines (struct reading_from_file* parameters_of_file);

void sorting_and_outing_in_file (struct reading_from_file* parameters_of_file);

void sorting_from_the_beginning_and_outing_to_file (struct reading_from_file* parameters_of_file);

void sorting_from_the_ending_and_outing_to_file (struct reading_from_file* parameters_of_file);

void no_sorting_and_outing_to_file(struct reading_from_file* parameters_of_file);

void destruct_dynamic_elements (struct reading_from_file* parameters_of_file);

#endif
