#include "strsfunc.h"
#include "struct_of_file.h"
#include "enter_file.h"

int main (){

    struct reading_from_file parameters_of_file = {};

    char file_name[] = "onegineugene.txt";

    parameters_of_file.file_name = file_name;

    read_file (&parameters_of_file);

    sorting_and_outing_in_file (&parameters_of_file);

    destruct_dynamic_elements (&parameters_of_file);

    return 0;
}
