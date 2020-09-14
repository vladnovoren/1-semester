#include <stdio.h>
#include <math.h>
#include <assert.h>

const double eps = 1e-6;

double Input1[] = {



const int INF_SOL_FLAG = -1;

bool checkZero(double a){
    return a < eps && a + eps > 0;
}

void enterCoefficient(double* a, char coef){
        while(true){
            printf("%c: ", coef);
            if(scanf("%lg", a) != 1){
                printf("Incorrect value entered, please try again\n");
                fflush(stdin);
            }
            else
                break;
        }
}

int quadSolve(double a, double b, double c, double* x1, double* x2){
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if(checkZero(a)){
        if(checkZero(b)){
            if(checkZero(c)){
                return INF_SOL_FLAG;
            }
            else{
                return 0;
            }
        }
        else{//b!=0
            *x1 = *x2 = - c / b;
            return 1;
        }
    }
    else{//a!=0
        double discrim = b * b - 4 * a * c;

        if(discrim < 0){
            return 0;
        }

        if(checkZero(discrim)){
            *x1 = *x2 = - b / (2 * a);
            return 1;
        }

        if(discrim > 0){
            *x1 = ( - b - sqrt(discrim))/(2*a);
            *x2 = - b - *x1;
            return 2;
        }
    }
}


int main(){

    double x1 = 0, x2 = 0, a = 0, b = 0, c = 0;

    printf("Hello! This is quadratic equation solver\n");

    printf("Please enter coefficients:\n");

    enterCoefficient(&a, 'a');
    enterCoefficient(&b, 'b');
    enterCoefficient(&c, 'c');

    int nSolutions = quadSolve(a, b, c, &x1, &x2);

    switch(nSolutions){
        case INF_SOL_FLAG:
            printf("Infinite number of solutions\n");
            break;

        case 0:
            printf("No solutions :(\n");
            break;

        case 1:
            printf("One solution: %lg\n", x1);
            break;

        case 2:
            printf("Two solutions: %lg %lg\n", x1, x2);
            break;

        default:
            printf("Error in: main(): countSolution = %d\n", nSolutions);
            return 1;

    }

    return 0;
}
