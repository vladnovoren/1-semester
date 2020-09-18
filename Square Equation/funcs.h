/**
 * @file
 * Файл с включением заголовков нужных библиотек и объявлением функций.
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>

const float eps = 1e-6; ///< Константа, равная погрешности вычислений.

const int INF_SOL_FLAG = -1;///< Константа, обозначающая бесконечное число корней.

/**
 * @brief Проверяет, является ли число нулем.
 * @param a Проверяемое число.
 * @return Возвращает 1, если a == 0, иначе 0.
*/
bool Check_Zero(float a);

/**
 * @brief Вводит коэффициент.
 * @param a Указывает на переменную, в которой находится значение коэффициента.
 * @param coef Символьное обозначение коэффициента
*/
void Enter_Coefficient(float* a, char coef);

/**
 * @brief Решает квадратное уравнение.
 * @param a Коэффициент а.
 * @param b Коэффициент b.
 * @param c Коэффициент c.
 * @param x1 Указатель на первый корень.
 * @param x2 Указатель на второй корень.
*/
int Solve_Quade(float a, float b, float c, float* x1, float* x2);