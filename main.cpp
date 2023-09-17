#include "strsfunc.h"
#include "struct_of_file.h"
#include "enter_file.h"

int main (){

    struct reading_from_file parameters_of_file = {};

    char file_name[] = "onegineugene.txt";

    parameters_of_file.file_name = file_name;

    read_file (&parameters_of_file);

    //read_sort_and_file_output (&parameters_of_file);//TODO разделение на считывание и запись

    return 0;
}
