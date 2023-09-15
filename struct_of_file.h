#ifndef struct_of_file
#define struct_of_file

struct reading_from_file {

    size_t filesize = 0;

    char* file_name = nullptr;

    char* strings_of_the_file = nullptr;

    char** ptr_on_enter_in_strings = nullptr;

    size_t count_of_lines_in_file = 1;
};

#endif
