/**
 * @file
*/
#include "funcs.h"

int Check_Zero(double a){
    return (fabs(a) < eps);
}

double Discrim(double a, double b, double c){
    return b * b - 4 * a * c;
}

void Enter_Coefficient(double* a, char coef){
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

int Solve_Quade(double a, double b, double c, double* x1, double* x2){
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if(Check_Zero(a)){
        if(Check_Zero(b)){
            if(Check_Zero(c))
                return INF_SOL;
            else
                return NO_SOL;
        }
        else{//b!=0
            *x1 = *x2 = - c / b;
            return ONE_SOL;
        }
    }
    else{//a!=0
        double discrim = Discrim(a, b, c);

        if(discrim < 0)
            return NO_SOL;

        if(Check_Zero(discrim)){
            *x1 = *x2 = - b / (2 * a);
            return ONE_SOL;
        }

        if(discrim > 0){
            double sqrt_discrim = sqrt((double)discrim);
            *x1 = (-b + sqrt_discrim)/(2 * a);
            *x2 = (-b - sqrt_discrim)/(2 * a);
            return TWO_SOL;
        }
    }
    return -2;
}