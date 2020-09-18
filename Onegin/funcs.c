/**
 * @file
 * @brief Содержит определение основных функций программы.
 */
#include "funcs.h"

void Size_Of_File(FILE *f, int *size){
    assert(f != 0);
    assert(size != 0);
    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    fseek(f, 0, SEEK_SET);
}

void Read_Buff(FILE *f, char **buff, int *size, int *strcnt){
    assert(f != 0);
    Size_Of_File(f, size);
	*buff = (char *)calloc(*size + 2, sizeof(char));
    assert(buff != 0);
    **buff = '\0';
	fread(*buff, sizeof(char), *size, f);
    if((*buff)[*size - 1] != '\n') {
        (*buff)[*size] = '\n';
        (*size)++;
    }
	fclose(f);
    for(size_t pos = 0; pos < *size; pos++){
        if((*buff)[pos] == '\n'){
            (*buff)[pos] = '\0';
            (*strcnt)++;
        }
    }
}

void Make_Index(char *buff, struct Str **index, int strcnt){
    assert(buff != 0);
    *index = (struct Str *)calloc(strcnt, sizeof(struct Str));
    assert(index != 0);
    size_t begin_pos = 0;
    size_t pos = 0;
    for(int cur_num = 0; cur_num < strcnt; cur_num++){
        while(buff[pos] != '\0'){
            pos++;
        }
        (*index)[cur_num].str = buff + begin_pos;
        (*index)[cur_num].length = pos - begin_pos;
        pos++;
        begin_pos = pos;
    }
}

int Is_Legit_Symb(unsigned char x){
    return (x >= 192 && x <= 255) //русская буква или нет.
    || x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || isdigit(x); //английская буква или цифра или нет.
}

int Str_Comp_Begin(const struct Str *str1, const struct Str *str2){
    assert(str1 != 0);
    assert(str2 != 0);
    if(str1->length == 0 && str2->length == 0) return 0;
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
    return 0;
}

int Str_Comp_End(const struct Str *str1, const struct Str *str2){
    assert(str1 != 0);
    assert(str2 != 0);
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
    return 0;
}

void Output_Sorted_Text(struct Str *index, int strcnt, FILE *f)
{
    assert(index != 0);
    for(int num = 0; num < strcnt; num++){
        fputs(index[num].str, f);
        fputc('\n', f);
    }
}

void Output_Original_Text(char *buff, int size, FILE *fout){
    assert(buff != 0);
    assert(fout != 0);
    for(int pos = 0; pos < size; pos++){
        if(buff[pos] != '\0')
            fputc(buff[pos], fout);
        else
            fputc('\n', fout);
    }
}