/**
 * @file
 * Исходный код main'a тестирующей функции.
*/
#include "funcs.h"

/**
 * @brief Массив структур coef с набором тестовых данных.
 * @param a коэффициент а.
 * @param b коэффициент b.
 * @param c коэффициент с.
*/
struct coefs{
    float a;
    float b;
    float c;
} input_set[] = {
    1, 2, 1,
    1, 0, 1,
    2, 1, 3,
    0, 0, 0,
    0, 0, 1,
    0, 4, 17,
    3.5, 2.3, 4.4,
    1.2, 8.9, 1,
    6, 32, 4.234
};

/**
 * @brief Массив структур ans с набором верных ответов.
 * @param count количество решений.
 * @param x1 первый корень.
 * @param x2 второй корень.
*/
struct ans{
    int count;
    float x1;
    float x2;
} right_ans[] = {
    1, -1, -1,
    0, 0, 0,
    0, 0, 0,
    -1, 0, 0,
    0, 0, 0,
    1, -4.25, -4.25,
    0, 0, 0,
    2, -0.114115, -7.302551,
    2, -0.135769, -5.197564
};

/**
 * @brief Вызов тестов.
 * Для всех неверных ответов выведутся входные данные, результат программы и правильных ответ.
 * @param nSol Количество решений
 * @param x1 Первый корень.
 * @param x2 Второй корень.
 * @param is Прнимает значение 1, если все ответы сошлись, иначе 0.
*/
int main(){
    float x1 = 0, x2 = 0;
    int nSol = 0;
    bool is = 1;
    for(int num = 0; num < 9; num++){
        x1 = x2 = nSol = 0;
        nSol = Solve_Quade(input_set[num].a, input_set[num].b, input_set[num].c, &x1, &x2);
        if(nSol != right_ans[num].count || !Check_Zero(right_ans[num].x1 - x1) || !Check_Zero(right_ans[num].x2 - x2)){
            is = 0;
            printf("Test №%d: wrong answer\n", num + 1);
            printf("Input data:\n");
            printf("a = %.8g\tb = %.8g\tc = %.8g\n", input_set[num].a, input_set[num].b, input_set[num].c);
            printf("Your answer:\nnSol: %d;\tx1: %.8g;\tx2: %.8g\n", nSol, x1, x2);
            printf("Right answer:\nnSol: %d;\tx1: %.8g;\tx2: %.8g\n", right_ans[num].count, right_ans[num].x1, right_ans[num].x2);
        }
    }
    if(is)
        printf("All tests passed successfully\n");
    return 0;
}
