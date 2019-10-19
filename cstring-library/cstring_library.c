#include "cstring_library.h"

#include <stdlib.h>

#include <string.h>
#include <stdio.h>

int my_str_create(my_str_t *str, size_t buf_size){
    str->capacity_m = buf_size + 1;
    str->size_m = 0;

    str->data = (char*) malloc(str->capacity_m);

    if (str->data == NULL){
        return -1;
    }
    return 0;
}

void my_str_free(my_str_t *str){
    free(str->data);
    str->data = NULL;
}

int my_str_from_cstr(my_str_t *str, const char *cstr, size_t buf_size){
    size_t csize = 0;
    while (*(cstr + csize) != '\0') {
        csize += 1;
    }
    if (buf_size < csize) {
        return -1;
    }
    memcpy(str->data, cstr, csize);
    str->size_m = csize;
    str->capacity_m = csize + 1;
    return 0;
}

size_t my_str_size(const my_str_t *str){
    if(str == NULL){
        return 0;
    }
    return str->size_m;
}

size_t my_str_capacity(const my_str_t *str){
    if(str == NULL){
        return 0;
    }
    return str->capacity_m;
}

int my_str_empty(const my_str_t *str){
    if(str == NULL){
        return 0;
    }
    return str->size_m == 0;

}

int my_str_getc(const my_str_t *str, size_t index){
    if(str == NULL || (index >= (*str).size_m) || (index < 0)){
        return -1;
    }
    return (*str).data[index];
}

int my_str_putc(my_str_t *str, size_t index, char c){
    if(str == NULL || (index >= (*str).size_m) || (index < 0)){
        return -1;
    }
    (*str).data[index] = c;
    return 0;
}

const char *my_str_get_cstr(my_str_t *str){
    (*str).data[(*str).size_m + 1] = '\0';
    return (*str).data;
}

int my_str_pushback(my_str_t *str, char c){
    if(str == NULL){
        return -1;
    }
    if(my_str_reserve(str, (*str).size_m + 1) == -1){
        return -2;
    }
    (*str).data[(*str).size_m] = c;
    (*str).size_m++;
    return 0;
}

int my_str_popback(my_str_t *str){
    if(str == NULL){
        return -1;
    }
    if( my_str_empty(str)){
        return -2;
    }
    (*str).size_m--;
    return (*str).data[(*str).size_m];
}

int my_str_copy(const my_str_t *from, my_str_t *to, int reserve){
    if (from == NULL || to == NULL) {
        return -1;
    }
    if(reserve == 1){
        to->capacity_m = from->capacity_m;
    } else {
        to->capacity_m = from->size_m;
    }

    memcpy(to->data, from->data, to->capacity_m);

    to->size_m = from->size_m;
    return 0;
}

void my_str_clear(my_str_t *str){
    (*str).size_m = 0;
}

int my_str_insert_c(my_str_t *str, char c, size_t pos){
    if (str == NULL) {
        return -2;
    }
    if ((*str).size_m < pos) {
        return -1;
    }
    if (str->size_m == str->capacity_m) {
        my_str_reserve(str, str->capacity_m + 1);
    }
    memmove(str->data + pos + 1, str->data + pos, str->capacity_m);
    str->data[pos] = c;
    str->size_m++;
    return 0;
}

int my_str_insert(my_str_t *str, const my_str_t *from, size_t pos) {
    if(str == NULL || from == NULL){
        return -1;
    }
    if ((*str).size_m < pos) {
        return -2;
    }
    if (str->capacity_m < str->size_m + from->size_m) {
        my_str_reserve(str, str->size_m + from->size_m);
    }
    memmove(str->data + pos + from->size_m, str->data + pos, str->capacity_m);
    for (int i = pos; i < pos + from->size_m; i++) {
        str->data[i] = from->data[i-pos];
    }
    str->size_m += from->size_m;
    return 0;
}

int my_str_insert_cstr(my_str_t *str, const char *from, size_t pos){
    size_t cstr_size = 0;
    while (from[cstr_size] != '\0') cstr_size++;
    my_str_t cstr;
    my_str_create(&cstr, 0);
    my_str_from_cstr(&cstr, from, cstr_size);
    int fin = my_str_insert(str, &cstr, pos);
    return fin;
}

int my_str_append(my_str_t *str, const my_str_t *from) {
    return my_str_insert(str, from, str->size_m);
}

int my_str_append_cstr(my_str_t *str, const char *from){
    return my_str_insert_cstr(str, from, str->size_m);
}

int my_str_substr(const my_str_t *from, my_str_t *to, size_t beg, size_t end){
    if(beg < 0 || beg > from->size_m){
        return -1;
    }
    if(to->capacity_m < end - beg){
        my_str_reserve(to, end - beg + 1);
    }
    for(int i = beg; i < end; i++){
        to->data[i-beg] = from->data[i];
    }
    to->size_m = end - beg;
    return 0;
}

int my_str_substr_cstr(const my_str_t *from, char *to, size_t beg, size_t end){
    if(beg < 0 || beg > from->size_m){
        return -1;
    }
    for(int i = beg; i < end; i++){
        to[i-beg] = from->data[i];
    }
    return 0;
}

int my_str_reserve(my_str_t *str, size_t buf_size){
    if (str == NULL) {
        return -1;
    }
    if ((*str).size_m >= buf_size) {
        return 0;
    }
    char* new_str = (char*) malloc(buf_size + 1);
    if(new_str == NULL){
        return -2;
    }

    memcpy(new_str, str->data, str->size_m);
    my_str_free(str);

    str->data = new_str;
    str->capacity_m = buf_size + 1;
    return 0;
}

int my_str_shrink_to_fit(my_str_t *str) {
    if (str == NULL) {
        return -1;
    }
    char* new_str = (char*) malloc(str->size_m + 1);
    if(new_str == NULL){
        return -2;
    }

    memcpy(new_str, str->data, str->size_m);
    new_str[str->size_m] = '\0';
    my_str_free(str);

    str->data = new_str;
    str->capacity_m = str->size_m;
    return 0;
}

int my_str_resize(my_str_t *str, size_t new_size, char sym){
    if (new_size <= 0){
        return -1;
    }
    if (new_size <= str->size_m ){
        str->size_m = new_size;
        return 0;
    }
    if (new_size > str->size_m) {
        my_str_reserve(str, new_size);
        for (int i = str->size_m; i < new_size; i++) {
            str->data[i] = sym;
        }
        str->size_m = new_size;
    }
    return 0;
}

size_t my_str_find(const my_str_t *str, const my_str_t *tofind, size_t from){
    if(str == NULL || tofind == NULL || tofind->size_m > str->size_m || from > str->size_m){
        return -1;
    }
    for(int i = from; i < str->size_m; i++){
        for (int j = 0; j < tofind->size_m; j++) {
            if (str->data[i+j] == tofind->data[j]) {
                if (j + 1 == tofind->size_m) {
                    return i;
                }
                continue;
            } else {
                break;
            }
        }
    }
    return (size_t)(-1);
}

int my_str_cmp(const my_str_t *str1, const my_str_t *str2){
    if(str1->size_m < str2->size_m){
        return -1;
    } else if (str1->size_m > str2->size_m) {
        return 1;
    }
    for (int i = 0; i < str1->size_m; i++) {
        if (str1->data[i] == str2->data[i]) {
            continue;
        } else {
            if (str1->data[i] > str2->data[i]) {
                return 1;
            } else {
                return -1;
            }
        }
    }
    return 0;
}

int my_str_cmp_cstr(const my_str_t *str1, const char *cstr2){
    size_t cstr2_size = 0;
    while (cstr2[cstr2_size] != '\0') cstr2_size++;

    if (str1->size_m > cstr2_size)
        return 1;
    else if (str1->size_m < cstr2_size)
        return -1;
    else {
        for (int j = 0; j < str1->size_m; ++j) {
            if (str1->data[j] != cstr2[j])
                return -1;
        }
        return 0;
    }
}

size_t my_str_find_c(const my_str_t *str, char tofind, size_t from) {
    if (from > str->size_m) {
        return (size_t)(-1);
    }
    for (int i = from; i < str->size_m; i++) {
        if (str->data[i] == tofind) {
            return i;
        }
    }
    return (size_t)(-1);
}

size_t my_str_find_if(const my_str_t *str, int (*predicat)(int)){
    for (int j = 0; j < str->size_m; ++j) {
        if (predicat((int)str->data[j]))
            return j;
    }
    return (size_t) (-1);
}

int my_str_read_file(my_str_t *str, FILE *file){
    return my_str_read_file_delim(str, file, EOF);
}

int my_str_read(my_str_t *str){
    return my_str_read_file(str, stdin);
}

int my_str_write_file(const my_str_t *str, FILE *file){
    if (!file)
    {
        printf("No such file!\n");
        return -1;
    }

    if (!fputs((*str).data, file))
    {
        printf("Error:string cannot be written!");
    }

    return 0;
}

int my_str_write(const my_str_t *str){
    return my_str_write_file(str, stdout);
}

int my_str_read_file_delim(my_str_t *str, FILE *file, char delimiter){
    int numCh;
    str->size_m = 0;
    while ((numCh=fgetc(file)) != delimiter){
        if(my_str_pushback(str, (char) numCh) != 0){
            return -1;
        }
    }
    return 0;
}
