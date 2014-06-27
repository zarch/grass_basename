#include <stdio.h>
#include <stdlib.h>

#include "basename.h"

/*!
 * \brief Test functions
 */
int main(){
    int i, j, n;
    const char *decimals_strings[4] = {"12345.6789", "12345.67", 
                                       "12345.", "12345"};
    const char *strings[4] = {"basename", "12345.6", 
                              "12345.", "12345"};
    int len_decimals_strings=4;
    size_t ndigits[] = {0, 2, 3, 4};
    int len_ndigits = 4;
    size_t ndecimals[] = {0, 1, 2, 3, 4};
    int len_ndecimals = 5;
    const char basename[] = "basename";
    const char SEP[] = "====================================================\n";
    double numbers[] = {12.34567890, 0.987654321};
    int len_numbers=2;
    char *result;

    printf(SEP);
    printf("\n\nTest G_get_num_decimals\n");
    for (i = 0; i < len_decimals_strings; i++){
        printf("Number of decimals in %s => %zu\n", 
               decimals_strings[i], 
               G_get_num_decimals(decimals_strings[i]));
    }

    printf(SEP);
    printf("\n\nTest G_double_to_basename_format\n");
    for (i = 0; i < len_ndigits; i++){
        for (j = 0; j < len_ndecimals; j++){
            for (n = 0; n < len_numbers; n++){
                result = G_double_to_basename_format(numbers[n], ndigits[i],
                                                     ndecimals[j]);
                printf("number: %10f, ndigits: %zu, ndecimals: %zu result => %s\n",
                       numbers[n], ndigits[i], ndecimals[j], result);
                free(result);
            }
            printf("\n");
        }
    }

    printf(SEP);
    printf("\n\nTest G_get_basename_separator\n");
    printf("The basename separator is: %s\n", G_get_basename_separator());

    printf(SEP);
    printf("\n\nG_join_basename_strings\n");
    printf("result join strings: %s\n**", G_join_basename_strings(strings, 4));

    printf(SEP);
    printf("\n\nTest G_get_format_name\n");
    for (i = 0; i < len_ndigits; i++){
        for (j = 0; j < len_ndecimals; j++){
            for (n = 0; n < len_numbers; n++){
                result = G_generate_basename(basename, numbers[n], ndigits[i], ndecimals[j]);
                printf("basename: %s, number: %10f, ndigits: %zu, decimals: %zu result => %s\n",
                        basename, numbers[n], ndigits[i], ndecimals[j], result);
                free(result);
            }
            printf("=======================================================\n");
        }
    }
    return 0;
}
