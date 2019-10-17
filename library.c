#include "library.h"

#include <stdlib.h>

#include <string.h>
#include <stdio.h>

int my_str_create(my_str_t *str, size_t buf_size){
//    create str object
//    return -1 if nothing given
    (*str).capacity_m = buf_size + 1;
    (*str).size_m = 0;
    (*str).data = (char *) calloc((*str).capacity_m, sizeof(char));

//    str->capacity_m = buf_size;
//    (*str).data = (char*) malloc(buf_size+1);


    if ((*str).data == NULL){
        return -1;
    }
    return 0;
}

void my_str_free(my_str_t *str){
//    Free memory by destroying str.
    free((str->data);
}

int my_str_from_cstr(my_str_t *str, const char *cstr, size_t buf_size){
//    Creates a buffer str of the specified size from the transmitted C-string
//    returns 0 - if everything is OK, -1 is not enough buffer size,
//    -2 is not able to allocate memory


}

size_t my_str_size(const my_str_t *str){
    if(str == NULL){
        return 0;
    }
    return (*str).size_m;
}

size_t my_str_capacity(const my_str_t *str){
    if(str == NULL){
        return 0;
    }
    return (*str).capacity_m;
}

int my_str_empty(const my_str_t *str){
//    Returns a Boolean whether str is empty:
//    ""?????????
    if(str == NULL){
        return 0;
    }
    return str->size_m == 0;

}

int my_str_getc(const my_str_t *str, size_t index){
//    Returns the character at the given index,
//    or -1 if you move beyond the str
    if(str == NULL){
        return -1;
    }
    if((index >= (*str).size_m) || (index < 0){
        return -1;
    }
    return (*str).data[index];
}

int my_str_putc(my_str_t *str, size_t index, char c){
//! Записує символ у вказану позиції (заміняючи той, що там був),
//! Повертає 0, якщо позиція в межах стрічки,
//! Поветає -1, не змінюючи її вмісту, якщо ні.
    if(str == NULL){
        return -1;
    }
    if((index >= (*str).size_m) || (index < 0){
        return -1;
    }
    (*str).data[index] = c;
    return 0;


}

//! Повернути вказівник на С-стрічку, еквівалентну str.
//! Вважатимемо, що змінювати цю С-стрічку заборонено.
//! Вважатимемо, що як тільки my_str_t змінено, цей вказівник
//! може стати некоректним.
//! Якщо в буфері було зарезервовано на байт більше за макс. розмір, можна
//! просто додати нульовий символ в кінці та повернути вказівник data.
const char *my_str_get_cstr(my_str_t *str){
    (*str).data[(*str).size_m + 1] = "\0";
    return (*str).data;
}


//! Додає символ в кінець.
//! Повертає 0, якщо успішно,
//! -1 -- якщо передано нульовий вказівник,
//! -2 -- помилка виділення додаткової пам'яті.
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

//! Викидає символ з кінця.
//! Повертає його, якщо успішно,
//! -1 -- якщо передано нульовий вказівник,
//! -2 -- якщо стрічка порожня.
int my_str_popback(my_str_t *str){
    if(str == NULL){
        return -1;
    }
    if( my_str_empty(str)){ //is empty
        return -2;
    }
    (*str).size_m--;
    return (*str).data[(*str).size_m];
}


//! Копіює стрічку. Якщо reserve == true,
//! то із тим же розміром буферу, що й вихідна,
//! інакше -- із буфером мінімального достатнього розміру.
//! (Старий вміст стрічки перед тим звільняє, за потреби).
//! Повертає 0, якщо успішно, різні від'ємні числа для діагностики
//! проблеми некоректних аргументів.
int my_str_copy(const my_str_t *from, my_str_t *to, int reserve){

}

void my_str_clear(my_str_t *str){
    (*str).size_m = 0;
}

//! Вставити символ у стрічку в заданій позиції, змістивши решту символів праворуч.
//! За потреби -- збільшує буфер.
//! У випадку помилки повертає різні від'ємні числа, якщо все ОК -- 0.
int my_str_insert_c(my_str_t *str, char c, size_t pos){
    if((*str).size_m <= pos){
        (*str).size_m;
    }
}

int my_str_insert(my_str_t *str, const my_str_t *from, size_t pos);

int my_str_insert_cstr(my_str_t *str, const char *from, size_t pos);

int my_str_append(my_str_t *str, const my_str_t *from);

int my_str_append_cstr(my_str_t *str, const char *from);

int my_str_substr(const my_str_t *from, my_str_t *to, size_t beg, size_t end);

int my_str_substr_cstr(const my_str_t *from, char *to, size_t beg, size_t end);


//! Збільшує буфер стрічки, із збереженням вмісту,
//! якщо новий розмір більший за попередній,
//! не робить нічого, якщо менший або рівний.
//! (Як показує практика, це -- корисний підхід).
//! Для збільшення виділяє новий буфер, копіює вміст
//! стрічки (size_m символів -- немає сенсу копіювати
//! решту буфера) із старого буфера та звільняє його.
//! У випадку помилки повертає різні від'ємні числа, якщо все ОК -- 0.
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

//    copy str
    memcpy(new_str, str->data, str->size_m);
    my_str_free(str);

    str->data = new_str;
    str->capacity_m = buf_size;
    return 0;

}

int my_str_shrink_to_fit(my_str_t *str);

int my_str_resize(my_str_t *str, size_t new_size, char sym);

size_t my_str_find(const my_str_t *str, const my_str_t *tofind, size_t from);

int my_str_cmp(const my_str_t *str1, const my_str_t *str2);

int my_str_cmp_cstr(const my_str_t *str1, const char *cstr2);

size_t my_str_find_c(const my_str_t *str, char tofind, size_t from);

size_t my_str_find_if(const my_str_t *str, int (*predicat)(int));

int my_str_read_file(my_str_t *str, FILE *file);

int my_str_read(my_str_t *str);

int my_str_write_file(const my_str_t *str, FILE *file);

int my_str_write(const my_str_t *str, FILE *file);

int my_str_read_file_delim(my_str_t *str, FILE *file, char delimiter);