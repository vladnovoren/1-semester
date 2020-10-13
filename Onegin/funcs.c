/**
 * @file
 * @brief Содержит определение основных функций программы.
 */
#include "funcs.h"

int Size_Of_File(FILE *f){
    assert(f != 0);

    fseek(f, 0, SEEK_END);
    int size = ftell(f);

    fseek(f, 0, SEEK_SET);

    return size;
}

int Change_Symbol(char *buff, int size, char from, char to){
    int count = 0;

    for(int pos = 0; pos < size; pos++){
        if(buff[pos] == from){
            buff[pos] = to;
            count++;
        }
    }

    return count;
}

int File_To_Index(FILE *f, char **buff, Str **index, int *size){
    assert(f != NULL);
    assert(buff != NULL);
    assert(index != NULL);

    *size = Write_To_Buff(f, buff);

    int strcnt = Change_Symbol(*buff, *size, '\n', '\0');

    Make_Index(*buff, index, strcnt);

    return strcnt;
}

int Write_To_Buff(FILE *f, char **buff){
    assert(f != NULL);
    assert(buff != NULL);

    int size = Size_Of_File(f);

    *buff = (char *)calloc(size + 1, sizeof(char));
    fread(*buff, sizeof(char), size, f);

    assert(buff != 0);

    (*buff)[size] = '\n';
    if((*buff)[size - 1] != '\n') size++;

	fclose(f);
    return size;
}

void Make_Index(char *buff, Str **index, int strcnt){
    assert(buff != 0);

    *index = (Str *)calloc(strcnt, sizeof(Str));
    assert(index != 0);

    size_t begin_pos = 0;
    size_t pos = 0;

    for(int cur_num = 0; cur_num < strcnt; cur_num++){
        while(buff[pos] != '\0'){
            pos++;
        }

        (*index)[cur_num].str    = buff + begin_pos;
        (*index)[cur_num].length = pos  - begin_pos;

        pos++;
        begin_pos = pos;
    }
}

int Is_Legit_Symb(unsigned char symb){
    return (symb >= 192 && symb <= 255) //русская буква или нет.
    || symb >= 'a' && symb <= 'z' || symb >= 'A' && symb <= 'Z' || isdigit(symb); //английская буква или цифра или нет.
}

int Start_Num(int len, int slider){
    return (1 - slider) / 2 * (len - 1);
}


int Str_Comp(const Str *Str1, const Str *Str2, int slider){
    assert(Str1 != NULL);
    assert(Str2 != NULL);

    char *str1 = Str1->str;
    int   len1 = Str1->length;

    char *str2 = Str2->str;
    int   len2 = Str2->length;

    if(len1 == 0 && len2 == 0) return  0;
    if(len1 == 0)              return -1;
    if(len2 == 0)              return  1;

    int real_len1 = 0;
    int real_len2 = 0;

    int Start1 = Start_Num(len1, slider);
    int Start2 = Start_Num(len2, slider);

    for(int pos1 = Start1, pos2 = Start2; len1 && len2; pos1 += slider, pos2 += slider, len1--, len2--){
        while(len1 != 0 && !Is_Legit_Symb(str1[pos1])){
            pos1 += slider;
            len1--;
        }
        while(len2 != 0 && !Is_Legit_Symb(str2[pos2])){
            pos2 += slider;
            len2--;
        }
        if(len1 != 0)
            real_len1++;
        if(len2 != 0) 
            real_len2++;
        
        if(len1 ==0 || len2 == 0)
            break;
        

        if(str1[pos1] > str2[pos2])
            return 1;   

        if(str1[pos1] < str2[pos2])
            return -1;
    }

    return real_len1 - real_len2;
}

int Str_Comp_Begin(const void *left_ptr, const void *right_ptr){
    assert(left_ptr  != NULL);
    assert(right_ptr != NULL);

    Str  *left = (Str*)left_ptr;
    Str *right = (Str*)right_ptr;

    return Str_Comp(left, right, LEFT_SORTING);
}

int Str_Comp_End(const void *left_ptr, const void *right_ptr){
    assert(left_ptr  != NULL);
    assert(right_ptr != NULL);

    Str *left  = (Str*)left_ptr;
    Str *right = (Str*)right_ptr;

    return Str_Comp(left, right, RIGHT_SORTING);
}

void Output_Sorted_Text(FILE *fout, Str *index, int strcnt){
    assert(fout  != NULL);
    assert(index != NULL);

    for(int num = 0; num < strcnt; num++){
        fputs(index[num].str, fout);
        fputc('\n', fout);
    }
}

void Output_Original_Text(FILE *fout, char *buff, int size){
    assert(buff != NULL);
    assert(fout != NULL);

    for(int pos = 0; pos < size; pos++){
        if(buff[pos] != '\0')
            fputc(buff[pos], fout);
        else
            fputc('\n', fout);
    }
}

Str Minimum(Str str1, Str str2, int (*comp) (const void *, const void *)){
    return (comp(&str1, &str2) == 1) ? str1 : str2;
} 

Str Maximum(Str str1, Str str2, int (*comp) (const void *, const void *)){
    return (comp(&str1, &str2) == -1) ? str1 : str2;
}

Str Medium(Str str1, Str str2, Str str3, int (*comp)(const void *, const void *)){
    Str minimum = Minimum(Minimum(str1, str2, comp), str3, comp);
    Str maximum = Maximum(Maximum(str1, str2, comp), str3, comp);

    if(comp(&str1, &minimum) != -1 && comp(&maximum, &str1) != -1) return str1;
    if(comp(&str2, &minimum) != -1 && comp(&maximum, &str2) != -1) return str2;
    return str3;
}

void Swap(Str *first, Str *second){
    Str tmp = *first;
    *first = *second;
    *second = tmp;
}

void Quick_Sort(Str *array, int left, int right, int (*comp) (const void *, const void *)){
    Str pivot = Medium(array[left], array[right], array[(left + right) / 2], comp);
    
    int left_p = left, right_p = right;

    while(left_p <= right_p){
        while(comp(array + left_p, &pivot) < 0)
            left_p++;
        while(comp(array + right_p, &pivot) > 0)
            right_p--;
        if(left_p <= right_p){
            Swap(array + left_p, array + right_p);
            left_p++;
            right_p--;
        }
    }
    if(left < right_p)
        Quick_Sort(array, left, right_p, comp);
    if(right > left_p)
        Quick_Sort(array, left_p, right, comp);
}