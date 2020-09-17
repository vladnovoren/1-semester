/**
 * @file
 * 
*/

#include "funcs.h"

/**
 * 
 */
int main(){

    float x1 = 0, x2 = 0, a = 0, b = 0, c = 0;

    printf("Hello! This is quadratic equation solver\n");

    printf("Please enter coefficients:\n");

    //вводим коэффициенты уравнение
    enterCoefficient(&a, 'a');
    enterCoefficient(&b, 'b');
    enterCoefficient(&c, 'c');

    //в nSolutions записываем количество корней уравнения ax^2 + bx + c = 0
    int nSolutions = quadSolve(a, b, c, &x1, &x2);

    //рассматриваются 
    switch(nSolutions){
        case INF_SOL_FLAG:
            printf("Infinite number of solutions\n");
            break;

        case 0:
            printf("No solutions oe:(\n");
            break;

        case 1:
            printf("One solution: %.6g\n", x1);
            break;

        case 2:
            printf("Two solutions: %.6g %.6g\n", x1, x2);
            break;

        default:
            printf("Error in: main(): countSolution = %d\n", nSolutions);
            return 1;

    }

    return 0;
}
