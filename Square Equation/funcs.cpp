/**
 * @file
*/
#include "funcs.h"

bool checkZero(float a){
    return (fabs(a) < eps);
}

void enterCoefficient(float* a, char coef){
        while(true){
            printf("%c: ", coef);
            if(scanf("%g", a) != 1){
                printf("Incorrect value entered, please try again\n");
                fflush(stdin);
            }
            else
                break;
        }
}

int quadSolve(float a, float b, float c, float* x1, float* x2){
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
        float discrim = b * b - 4 * a * c;

        if(discrim < 0){
            return 0;
        }

        if(checkZero(discrim)){
            *x1 = *x2 = - b / (2 * a);
            return 1;
        }

        if(discrim > 0){
            float sqrt_discrim = sqrt(discrim);
            *x1 = ( - b + sqrt_discrim)/(2*a);
            *x2 = ( - b - sqrt_discrim)/(2*a);
            return 2;
        }
    }
    return -2;
}