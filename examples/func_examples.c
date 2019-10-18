#include <stdio.h>

#include "../cstring-library/cstring_library.c"
#include "func_examples.h"
//#include "main.c"

int test_my_str_create(void) {
    my_str_t str;
    my_str_create(&str, 1);
    if (str.data == NULL) return -1;
    return 0;
}

int test_my_str_from_cstr(void) {
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    for (int i = 0; i < str.size_m; i++) {
        if (str.data[i] != cstr[i]) return -1;
    }
    if (str.size_m != 12) return -2;
    if (str.capacity_m != 13) return -3;
    return 0;
}

int test_my_str_free(void) {
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    my_str_free(&str);
    if (str.data != NULL) return -1;
    return 0;
}

int main(void) {
    int test_my_str_create_result = test_my_str_create();
    int test_my_str_from_cstr_result = test_my_str_from_cstr();
    int test_my_str_free_result = test_my_str_free();
    printf("%d \n", test_my_str_create_result);
    printf("%d \n", test_my_str_from_cstr_result);
    printf("%d \n", test_my_str_free_result);
    return 0;
}
int main();