
#include <stdio.h>

#include "library/cstring_library.h"

int main(void)
{
    FILE* readf;

    if ((readf = fopen("data/0.txt", "r")) == NULL)
    {
        printf("File does not exist!");
        exit(1);
    }

    int textLen = 0;
    char ch;
    while ((ch = fgetc(readf)) != EOF)
    {
        textLen++;
    }
    fclose(readf);

    if ((readf = fopen("data/0.txt", "r")) == NULL)
    {
        printf("File does not exist!");
        exit(1);
    }
    char text[textLen];
    char modText[textLen];
    fread(text, sizeof(char), textLen, readf);

    fclose(readf);

    int i;
    for (i = 0; i < textLen; i++)
    {
        printf("%c\n", text[i]);
    }

    int j = 0;
    int flag = 0;
    int lenOut;
    for (i = 0; i < textLen; ++i)
    {
        if (j >= textLen)
        {
            lenOut = i;
            break;
        }
        if (text[j] >= 'A' && text[j] <= 'Z')
        {
            modText[i] = text[j] - 'A' + 'a';
            j++;
        }
        else if (text[j] >= 'a' && text[j] <= 'z')
        {
            modText[i] = text[j];
            j++;
        }
        else
        {
            while ((text[j] < 'A') || (text[j] > 'Z' && text[j] < 'a') || (text[j] >= 'z'))
            {
                if (text[j] == ' ') flag = 1;

                j++;
            }
            if (flag == 1)
            {
                flag = 0;
                modText[i] = ' ';
            }
        }


    }

    char outText[lenOut];
    for (j = 0; j < lenOut; j++)
    {
        outText[j] = modText[j];
    }
    FILE* writef;
    if ((writef = fopen("data/0.out", "w")) == NULL)
    {
        printf("File does not exist!");
        exit(1);
    }

    fwrite(outText, sizeof(char), j, writef);

    fclose(writef);


    /*my_str_t* text;
    my_str_create(text, 5);


    printf("%zu", (*text).capacity_m);

    my_str_free(text);*/

    return 0;
}
