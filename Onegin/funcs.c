//описание функций 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>
#include "funcs.h"

int Read_Buff(FILE *f, char **buff, int *size, int *strcnt){
    fseek(f, 0, SEEK_END);
	*size = ftell(f);
	fseek(f, 0, SEEK_SET);//узнаем кол-во символов в файле
	*buff = (char *) calloc(*size + 2, sizeof(char));//выделение памяти для буфера
    **buff = '\0';
	fread(*buff, sizeof(char), *size, f);//чтение файла
    if((*buff)[*size - 1] != '\n') {
        (*buff)[*size] = '\n';
        (*size)++;
    }
	fclose(f);
    for(int i = 0; i < *size; i++){
        if((*buff)[i] == '\n'){
            (*buff)[i] = '\0';
            (*strcnt)++;
        }
    }
    
	return 0;
}

int Make_Index(char *buff, struct Str **index_ptr, int *size, int *strcnt){
    struct Str *index = (struct Str *)calloc(*strcnt, sizeof(struct Str));
    *index_ptr = index;
    int begin_pos = 0;
    int pos = 0;
    for(int cur_num = 0; cur_num < *strcnt; cur_num++){
        while(buff[pos] != '\0'){
            pos++;
        }
        index[cur_num].str = buff + begin_pos;
        index[cur_num].length = pos - begin_pos;
        pos++;
        begin_pos = pos;
    }
    return 0;
}

int Is_Legit_Symb(unsigned char x){
    return (x >= 192 && x <= 255) || x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || isdigit(x);
}

int Str_Comp_Begin(const struct Str *str1, const struct Str *str2){
    if(str1->length == 0) return -1;
    if(str2->length == 0) return 1;
    int real_length1 = 0;
    int real_length2 = 0;
    for(int pos1 = 0, pos2 = 0; pos1 < str1->length && pos2 < str2->length; pos1++, pos2++){
        while(pos1 < str1->length && !Is_Legit_Symb(str1->str[pos1])){
            pos1++;
        }
        while(pos2 < str2->length && !Is_Legit_Symb(str2->str[pos2])){
            pos2++;
        }
        if(pos1 >= str1->length || pos2 >= str2->length){
            break;
        }
        real_length1++;
        real_length2++;
        if(str1->str[pos1] > str2->str[pos2]){
            return 1;
        }
        if(str1->str[pos1] < str2->str[pos2]){
            return -1;
        }
    }
    if(real_length1 > real_length2){
        return 1;
    }
    if(real_length1 < real_length2){
        return -1;
    }
    if(real_length1 == real_length2){
        return 0;
    }
}

int Str_Comp_End(const struct Str *str1, const struct Str *str2){
    if(str1->length == 0) return -1;
    if(str2->length == 0) return 1;
    int real_length1 = 0;
    int real_length2 = 0;
    for(int pos1 = str1->length - 1, pos2 = str2->length - 1; pos1 >= 0 && pos2 >= 0; pos1--, pos2--){
        while(pos1 >= 0 && !Is_Legit_Symb(str1->str[pos1])){
            pos1--;
        }
        while(pos2 >= 0 && !Is_Legit_Symb(str2->str[pos2])){
            pos2--;
        }
        if(pos1 < 0 || pos2 < 0){
            break;
        }
        real_length1++;
        real_length2++;
        if(str1->str[pos1] > str2->str[pos2]){
            return 1;
        }
        if(str1->str[pos1] < str2->str[pos2]){
            return -1;
        }
    }
    if(real_length1 > real_length2){
        return 1;
    }
    if(real_length1 < real_length2){
        return -1;
    }
    if(real_length1 == real_length2){
        return 0;
    }
}

int Comparator_Begin(const void *a, const void *b){
    struct Str *A = (struct Str *)a;
    struct Str *B = (struct Str *)b;
    return Str_Comp_Begin(A, B);
}

int Comparator_End(const void *a, const void *b){
    struct Str *A = (struct Str *)a;
    struct Str *B = (struct Str *)b;
    return Str_Comp_End(A, B);
}

int Make_Index_Origin(int strcnt, struct Str *index, struct Str **index_first){
    *index_first = (struct Str*)calloc(strcnt, sizeof(struct Str));    
    for(int i = 0; i < strcnt; i++){
        (*index_first)[i].str = index[i].str;
        (*index_first)[i].length = index[i].length;
    }
    return 0;
}

int Output_Text(struct Str *index, int strcnt, FILE *f)
{
    for(int num = 0; num < strcnt; num++){
        fputs(index[num].str, f);
        fputc('\n', f);
    }
    return 0;
}