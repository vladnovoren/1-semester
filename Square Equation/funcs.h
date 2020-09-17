/**
 * @file
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>

const float eps = 1e-6;

const int INF_SOL_FLAG = -1;

bool checkZero(float a);

void enterCoefficient(float* a, char coef);

int quadSolve(float a, float b, float c, float* x1, float* x2);