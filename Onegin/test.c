#include "funcs.h"

#define part "\n===========================================\n\n"

Str strings[] = {
    "123", 3,
    "ded", 3,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "shmarmockmimum", 14
};

int comp_begin_ans[] = {0, -1, -1, -1, -1, 1, 1, 0, 0, 1, -1, 1, 1, 0, 0, 1, -1, 1, 1, -1, -1, 0, -1, 1, 1, 1, 1, 1, 0, 1, -1, -1, -1, -1, -1, 0};

int comp_end_ans[] = {0, -1, -1, -1, -1, 1, 1, 0, -1, -1, -1, 1, 1, 1, 0, -1, -1, 1, 1, 1, 1, 0, -1, 1, 1, 1, 1, 1, 0, 1, -1, -1, -1, -1, -1, 0};

Str medium_begin_ans[] = {
    "123", 3,
    "ded", 3,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "ded", 3,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,   
    "ded", 3,
    "ded", 3,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "ded", 3,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,
    "     ", 5
};

Str medium_end_ans[] = {
    "123", 3,
    "ded", 3,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "ded", 3,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,
    "ded", 3,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,
    "callocvium", 10,
    "mallocvium", 10,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,
    "mallocvium", 10,
    "     ", 5,
    "     ", 5,
    "     ", 5
};

Str sort_left_ans[] = {
    "     ", 5,
    "123", 3,
    "callocvium", 10,
    "ded", 3,
    "dedline", 7,
    "mallocvium", 10
};

Str sort_right_ans[] = {
    "     ", 5,
    "123", 3,
    "ded", 3,
    "dedline", 7,
    "callocvium", 10,
    "mallocvium", 10
};

void Test_Comp_Begin(){
    printf(part);
    printf("Checking begin comparator..\n");
    int is = 1;
    for(int pos1 = 0; pos1 < 6; pos1++){
        for(int pos2 = 0; pos2 < 6; pos2++){
            int cur_ans = Str_Comp_Begin(strings + pos1, strings + pos2);
            if(cur_ans != comp_begin_ans[6 * pos1 + pos2]){
                is = 0;
                printf("Test №%d: wrong answer.\n", 6 * pos1 + pos2);
                printf("Your answer:\n%d\nRight answer:\n%d\n", cur_ans, comp_begin_ans[6 * pos1 + pos2]);
            }
        }
    }
    if(is)
        printf("All testes passed successfully!\n");
    printf(part);
}

void Test_Comp_End(){
    printf(part);
    printf("Checking end comparator..\n");
    int is = 1;
    for(int pos1 = 0; pos1 < 6; pos1++){
        for(int pos2 = 0; pos2 < 6; pos2++){
            int cur_ans = Str_Comp_End(strings + pos1, strings + pos2);
            if(cur_ans != comp_end_ans[6 * pos1 + pos2]){
                is = 0;
                printf("Test №%d: wrong answer.\n", 6 * pos1 + pos2);
                printf("Your answer:\n%d\nRight answer:\n%d\n", cur_ans, comp_end_ans[6 * pos1 + pos2]);
            }
        }
    }
    if(is)
        printf("All testes passed successfully!\n");
    printf(part);
}

void Test_Medium_Begin(){
    printf(part);
    printf("Checking medium begin..\n");
    int is = 1;
    int pos = 0;
    for(int pos1 = 0; pos1 < 6; pos1++){
        for(int pos2 = pos1; pos2 < 6; pos2++){
            for(int pos3 = pos2; pos3 < 6; pos3++, pos++){
                Str cur_ans = Medium(strings[pos1], strings[pos2], strings[pos3], Str_Comp_Begin);
                if(Str_Comp_Begin(&cur_ans, medium_begin_ans + pos) != 0){
                    is = 0;
                    printf("Test №%d: wrong answer.\n", pos);
                    printf("Your answer:\n%s\nRight answer:\n%s\n", cur_ans.str, medium_begin_ans[pos].str);
                }
            }
        }
    }
    if(is)
        printf("All testes passed successfully!\n");
    printf(part);
}

void Test_Medium_End(){
    printf(part);
    printf("Checking medium end..\n");
    int is = 1;
    int pos = 0;
    for(int pos1 = 0; pos1 < 6; pos1++){
        for(int pos2 = pos1; pos2 < 6; pos2++){
            for(int pos3 = pos2; pos3 < 6; pos3++, pos++){
                Str cur_ans = Medium(strings[pos1], strings[pos2], strings[pos3], Str_Comp_End);
                if(Str_Comp_End(&cur_ans, medium_end_ans + pos) != 0){
                    is = 0;
                    printf("Test №%d: wrong answer.\n", pos);
                    printf("Your answer:\n%s\nRight answer:\n%s\n", cur_ans.str, medium_end_ans[pos].str);
                }
            }
        }
    }
    if(is)
        printf("All testes passed successfully!\n");
    printf(part);
}

void Check_Sort_Begin(){
    printf(part);
    printf("Checking sort begin..\n");
    int is = 1;
    Quick_Sort(strings, 0, 5, Str_Comp_Begin);
    for(int pos = 0; pos < 6; pos++){
        if(Str_Comp_Begin(strings + pos, sort_left_ans + pos) != 0)
            is = 0;
    }
    if(is)
        printf("All testes passed successfully!\n");
    else{
        printf("Wrong answer.\n");

        printf("Your answer:\n");
        for(int pos = 0; pos < 6; pos++)
            printf("%s\n", strings[pos].str);
        
        printf("Right answer:\n");
        for(int pos = 0; pos < 6; pos++)
            printf("%s\n", sort_left_ans[pos].str);
    }
    
    printf(part);
}

void Check_Sort_End(){
    printf(part);
    printf("Checking sort end..\n");
    int is = 1;
    Quick_Sort(strings, 0, 5, Str_Comp_End);
    for(int pos = 0; pos < 6; pos++){
        if(Str_Comp_End(&strings[pos].str, sort_right_ans + pos) != 0)
            is = 0;
    }
    if(is)
        printf("All testes passed successfully!\n");
    else{
        printf("Wrong answer.\n");

        printf("Your answer:\n");
        for(int pos = 0; pos < 6; pos++)
            printf("%s\n", strings[pos].str);
        
        printf("Right answer:\n");
        for(int pos = 0; pos < 6; pos++)
            printf("%s\n", sort_right_ans[pos].str);
    }
    
    printf(part);
}

int main(){
    Test_Comp_Begin();
    Test_Comp_End();
    Test_Medium_Begin();
    Test_Medium_End();
    Check_Sort_Begin();
    Check_Sort_End();
    return 0;
}