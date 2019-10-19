#include <stdio.h>

#include "../cstring-library/cstring_library.c"
#include "func_examples.h"
#include <time.h>

int main(int argc, char* argv[])
{

    FILE* readF = fopen(argv[1], "r");
    FILE* writeF = fopen(argv[2], "w");

    if (!readF)
    {
        printf("Error: file cannot be open!");
        exit(1);
    }

    if (!writeF)
    {
        printf("Error: file cannot be open!");
        exit(1);
    }

    my_str_t str;

    if (my_str_create(&str, 256))
    {
        printf("Error: cannot create string!");
    }

    if (my_str_read_file(&str, readF))
    {
        printf("Cannot read such file!");
    }

    char ch;
    char ch_next;
    char ch_prev;
// ===========================================================================
    clock_t start = clock();
    for (size_t i = 0; i < str.size_m; i++)
    {

        ch_prev = my_str_getc(&str, i-1);
        ch = my_str_getc(&str, i);
        ch_next = my_str_getc(&str, i+1);
        if (ch == '.' || ch == ',' || ch == '!'
            || ch == '?' || ch == ':' || ch == ';' || ch == '-'
            || ch == '\'' || ch == '\"')
        {
            for (size_t j = 0; j < str.size_m - i - 1; j++)
            {
                str.data[i+j] = str.data[i+j+1];
            }
            my_str_popback(&str);
            i--;
        }
        if (ch >= 'A' && ch <= 'Z')
        {
            str.data[i] = ch -'A' + 'a';
        }
        if (ch == ' ')
        {

            if (ch_next == ' ')
            {

                for (size_t j = 0; j < str.size_m - i - 1; j++)
                {
                    str.data[i+j] = str.data[i+j+1];
                }
                my_str_popback(&str);
                i--;
            }
            if (ch_prev == ' ')
            {
                i -= 2;
            }
        }
    }

    my_str_shrink_to_fit(&str);

    clock_t finish = clock();

    double time_spent = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time: %.13f\n", time_spent);

    if (my_str_write_file(&str,writeF))
    {
        printf("Cannot write file!");
        return -1;
    }

    fclose(readF);
    fclose(writeF);
    my_str_free(&str);


    return 0;
}