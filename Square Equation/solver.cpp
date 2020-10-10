/**
 * @file
 * Решение уравнений в обычном режиме.
*/

#include "funcs.h"

/**
 * @brief Точка входа в программу.
 * @param x1 первый корень.
 * @param x2 второй корень.
 * @param a коэффициент а.
 * @param b коэффициент b.
 * @param c коэффициент c.
 */
int main(){

    double a = 0, b = 0, c = 0,
               x1 = 0, x2 = 0;

    printf("Hello! This is quadratic equation solver\n");

    printf("Please enter coefficients:\n");

    //вводим коэффициенты уравнение
    Enter_Coefficient(&a, 'a');
    Enter_Coefficient(&b, 'b');
    Enter_Coefficient(&c, 'c');

    //в nSolutions записываем количество корней уравнения ax^2 + bx + c = 0
    int n_solutions = Solve_Quade(a, b, c, &x1, &x2);

    //рассматриваются 
    switch(n_solutions){
        case INF_SOL:
            printf("Infinite number of solutions\n");
            break;

        case NO_SOL:
            printf("No solutions oe:(\n");
            break;

        case ONE_SOL:
            printf("One solution: %.6g\n", x1);
            break;

        case TWO_SOL:
            printf("Two solutions: %.6g %.6g\n", x1, x2);
            break;

        default:
            printf("Error in: main(): n_solution = %d\n", n_solutions);
            return 1;

    }

    return 0;
}
