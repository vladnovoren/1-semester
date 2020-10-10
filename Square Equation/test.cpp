/**
 * @file
 * Режим тестирования.
*/
#include "funcs.h"

/**
 * @brief Массив структур coef с набором тестовых данных.
 * @param a коэффициент а.
 * @param b коэффициент b.
 * @param c коэффициент с.
*/
struct Coefs{
    double a;
    double b;
    double c;
} Input_Set[] = {
    1.000000, 2.0000000, 1.000000,
    1.000000, 0.000000, 1.000000,
    2.000000, 1.000000, 3.000000,
    0.000000, 0.000000, 0.000000,
    0.000000, 0.000000, 1.000000,
    0.000000, 4.000000, 17.000000,
    3.500000, 2.300000, 4.400000,
    1.200000, 8.9000000, 1.000000,
    6.000000, 32.000000, 4.000000
};

double Right_Discrims[] = {0.000000, -4.000000, -23.000000, 0.000000, 0.000000, 16.000000, -56.310000, 74.410000, 928.000000};

/**
 * @brief Массив структур Ans с набором верных ответов.
 * @param count количество решений.
 * @param x1 первый корень.
 * @param x2 второй корень.
*/
struct Ans{
    int count;
    double x1;
    double x2;
} Right_Ans[] = {
    1, -1.000000, -1.000000,
    0, 0.000000, 0.000000,
    0, 0.000000, 0.000000,
    -1, 0.000000, 0.000000,
    0, 0.000000, 0.000000,
    1, -4.250000, -4.250000,
    0, 0.000000, 0.000000,
    2, -0.114115, -7.302551,
    2, -0.12807563, -5.20525770
};

/**
 * @brief Сверяет ответы функции Solve_Quade.
*/
void Check_Answers(){
    printf("\n==============================================================================\n");
    printf("\nChecking answers..\n");
    double x1 = 0, x2 = 0;
    int n_sol = 0;
    int is = 1;
    for(int num = 0; num < 9; num++){
        x1 = x2 = n_sol = 0;
        n_sol = Solve_Quade(Input_Set[num].a, Input_Set[num].b, Input_Set[num].c, &x1, &x2);
        if(n_sol != Right_Ans[num].count || !Check_Zero(Right_Ans[num].x1 - x1) || !Check_Zero(Right_Ans[num].x2 - x2)){
            is = 0;
            printf("Test №%d: wrong Answer\n", num + 1);
            printf("Input data:\n");
            printf("a = %.8lg\tb = %.8lg\tc = %.8lg\n", Input_Set[num].a, Input_Set[num].b, Input_Set[num].c);
            printf("Your answer:\nn_sol: %d;\tx1: %.8lg;\tx2: %.8lg\n", n_sol, x1, x2);
            printf("Right answer:\nn_sol: %d;\tx1: %.8lg;\tx2: %.8lg\n", Right_Ans[num].count, Right_Ans[num].x1, Right_Ans[num].x2);
        }
    }
    if(is)
        printf("All tests passed successfully\n");
    printf("\n==============================================================================\n");
}

/**
 * @brief Проверяет работу функции Discrim.
*/
void Check_Discrim(){
    printf("\n==============================================================================\n");
    printf("\nChecking discriminants..\n");
    int is = 1;

    for(int num = 0; num < 9; num++){
        double cur_discrim = Discrim(Input_Set[num].a, Input_Set[num].b, Input_Set[num].c);
        if(!Check_Zero(cur_discrim - Right_Discrims[num])){
            is = 0;
            printf("Test №%d: wrong discriminant\n", num + 1);
            printf("Input data:\n");
            printf("a = %.8lg\tb = %.8lg\tc = %.8lg\n", Input_Set[num].a, Input_Set[num].b, Input_Set[num].c);
            printf("Your discriminant:\n%.8lg\n", cur_discrim);
            printf("Right discrim:\n%.8lg\n", Right_Discrims[num]);
        }
    }
    if(is)
        printf("All tests passed successfully\n");
    printf("\n==============================================================================\n");
} 

/**
 * @brief Вызов тестов.
 * Для всех неверных ответов выведутся входные данные, результат программы и правильных ответ.
 * @param n_sol Количество решений
 * @param x1 Первый корень.
 * @param x2 Второй корень.
 * @param is Прнимает значение 1, если все ответы сошлись, иначе 0.
*/
int main(){
    Check_Discrim();
    Check_Answers();
    return 0;
}
