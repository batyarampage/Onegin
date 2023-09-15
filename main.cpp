#include "strsfunc.h"
#include "struct_of_file.h"
#include "enter_file.h"

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
