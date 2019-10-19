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

int test_my_str_size(void){
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    int size = my_str_size(&str);
    if(size != 12) return -1;
    return 0;
}

int test_my_str_capacity(void){
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    int cap = my_str_capacity(&str);
    if(cap != 13) return -1;
    return 0;
}

int test_my_str_empty(void){
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    int empty = my_str_empty(&str);
    if(empty != 0) return -1;
    return 0;
}

int test_my_str_getc(void){
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    int getC = my_str_getc(&str, 3);
    if(getC != 'l') return -1;
    return 0;
}

int test_my_str_putc(void){
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    my_str_putc(&str, 3, 'W');
    if(str.data[3] != 'W') return -1;
    return 0;
}

int test_my_str_cstr(void);






int test_my_str_pushback(void){
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    my_str_pushback(&str, 'W');
    if(str.data[12] != 'W') return -1;
    return 0;
}

int test_my_str_popback(void){
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    char pop = my_str_popback(&str);
    if(pop != '!') return -1;
    return 0;
}

int test_my_str_copy(void){
    my_str_t str1;
    my_str_t str2;
    my_str_create(&str1, 0);
    my_str_create(&str2, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str1, cstr, 13);

    my_str_copy(&str1, &str2, 1);

    for (int i = 0; i < str1.size_m; i++) {
        if (str1.data[i] != str2.data[i]) return -1;
    }
    return 0;
}

int test_my_str_clear(void){
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    my_str_clear(&str);
    if(str.size_m != 0) return -1;
    return 0;
}

int test_my_str_insert_c(void){
    my_str_t str;
    my_str_create(&str, 0);
    char *cstr = "Hello World!";
    my_str_from_cstr(&str, cstr, 13);
    my_str_insert_c(&str, '?', 2);
    if(str.data[2] != '?') return -1;
    return 0;
}

int test_my_str_insert(void){
    my_str_t str1;
    my_str_create(&str1, 0);
    char *cstr1 = "Hello World!";
    my_str_from_cstr(&str1, cstr1, 20);

    my_str_t str2;
    my_str_create(&str2, 0);
    char *cstr2 = "Great ";
    my_str_from_cstr(&str2, cstr2, 7);

    my_str_insert(&str1, &str2, 6);

    my_str_t str3;
    my_str_create(&str3, 0);
    char *cstr3 = "Hello Great World!";
    my_str_from_cstr(&str3, cstr3, 19);

    for (int i = 0; i < str1.size_m; i++) {
        if (str1.data[i] != str3.data[i]) return -1;
    }
    return 0;
}

int test_my_str_insert_cstr(void){
    my_str_t str1;
    my_str_create(&str1, 0);
    char *cstr1 = "Hello World!";
    my_str_from_cstr(&str1, cstr1, 20);

    char *cstr = "My ";

    my_str_insert_cstr(&str1, cstr, 6);

    my_str_t str3;
    my_str_create(&str3, 0);
    char *cstr3 = "Hello My World!";
    my_str_from_cstr(&str3, cstr3, 19);

    for (int i = 0; i < str1.size_m; i++) {
        if (str1.data[i] != str3.data[i]) return -1;
    }
    return 0;
}

int test_my_str_append(void){
    my_str_t str1;
    my_str_create(&str1, 0);
    char *cstr1 = "Hello World!";
    my_str_from_cstr(&str1, cstr1, 20);

    my_str_t str2;
    my_str_create(&str2, 0);
    char *cstr2 = " Bye!";
    my_str_from_cstr(&str2, cstr2, 6);

    my_str_append(&str1, &str2);

    my_str_t str3;
    my_str_create(&str3, 0);
    char *cstr3 = "Hello World! Bye!";
    my_str_from_cstr(&str3, cstr3, 19);

    for (int i = 0; i < str1.size_m; i++) {
        if (str1.data[i] != str3.data[i]) return -1;
    }
    return 0;
}

int test_my_str_append_cstr(void){
    my_str_t str1;
    my_str_create(&str1, 0);
    char *cstr1 = "Hello World!";
    my_str_from_cstr(&str1, cstr1, 20);

    char *cstr = " Bye!";

    my_str_append_cstr(&str1, cstr);

    my_str_t str3;
    my_str_create(&str3, 0);
    char *cstr3 = "Hello World! Bye!";
    my_str_from_cstr(&str3, cstr3, 19);

    for (int i = 0; i < str1.size_m; i++) {
        if (str1.data[i] != str3.data[i]) return -1;
    }
    return 0;
}

int test_my_str_substr(void){
    my_str_t str1;
    my_str_create(&str1, 0);
    char *cstr1 = "Hello World!";
    my_str_from_cstr(&str1, cstr1, 20);

    my_str_t str2;
    my_str_create(&str2, 0);

    my_str_substr(&str1, &str2, 6, 11);

    my_str_t str3;
    my_str_create(&str3, 0);
    char *cstr3 = "World";
    my_str_from_cstr(&str3, cstr3, 19);

    for (int i = 0; i < str2.size_m; i++) {
        if (str2.data[i] != str3.data[i]) return -1;
    }
    return 0;
}

int test_my_str_substr_cstr(void){
    my_str_t str1;
    my_str_create(&str1, 0);
    char *cstr1 = "Hello World!";
    my_str_from_cstr(&str1, cstr1, 20);

    char cstr2[] = "abcde";

    my_str_substr_cstr(&str1, cstr2, 6, 11);

    char *cstr3 = "World";

    for (int i = 0; i < 5; i++) {
        if (cstr2[i] != cstr3[i]) return -1;
    }
    return 0;
}

int main(void) {
    int test_my_str_create_result = test_my_str_create();
    int test_my_str_from_cstr_result = test_my_str_from_cstr();
    int test_my_str_free_result = test_my_str_free();
    int test_my_str_size_result = test_my_str_size();
    int test_my_str_capacity_result = test_my_str_capacity();
    int test_my_str_empty_result = test_my_str_empty();
    int test_my_str_getc_result = test_my_str_getc();
    int test_my_str_putc_result = test_my_str_putc();
    int test_my_str_popback_result = test_my_str_popback();


    int test_my_str_pushback_result = test_my_str_pushback();
    int test_my_str_copy_result = test_my_str_copy();
    int test_my_str_clear_result = test_my_str_clear();
    int test_my_str_insert_c_result = test_my_str_insert_c();
    int test_my_str_insert_result = test_my_str_insert();
    int test_my_str_insert_cstr_result = test_my_str_insert_cstr();
    int test_my_str_append_result = test_my_str_append();
    int test_my_str_append_cstr_result = test_my_str_append_cstr();
    int test_my_str_substr_result = test_my_str_substr();
    int test_my_str_substr_cstr_result = test_my_str_substr_cstr();

    printf("%d \n", test_my_str_create_result);
    printf("%d \n", test_my_str_from_cstr_result);
    printf("%d \n", test_my_str_free_result);
    printf("%d \n", test_my_str_size_result);
    printf("%d \n", test_my_str_capacity_result);
    printf("%d \n", test_my_str_empty_result);
    printf("%d \n", test_my_str_getc_result);
    printf("%d \n", test_my_str_putc_result);

    printf("%d \n", test_my_str_pushback_result);
    printf("%d \n", test_my_str_popback_result);
    printf("%d \n", test_my_str_copy_result);
    printf("%d \n", test_my_str_clear_result);
    printf("%d \n", test_my_str_insert_c_result);
    printf("%d \n", test_my_str_insert_result);
    printf("%d \n", test_my_str_insert_cstr_result);
    printf("%d \n", test_my_str_append_result);
    printf("%d \n", test_my_str_append_cstr_result);
    printf("%d \n", test_my_str_substr_result);
    printf("%d \n", test_my_str_substr_cstr_result);



    return 0;
}
int main();