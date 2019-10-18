#include <stdio.h>

#include "cstring-library/cstring_library.c"
#include "func_examples.h"

int main()
{

    FILE* readF = fopen("data/0.txt", "r");
    FILE* writeF = fopen("data/0.out", "w");

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
    for (size_t i = 0; i < str.size_m; i++)
    {

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
        }
    }



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