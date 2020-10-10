/**
 * @file
 * Файл с включением заголовков нужных библиотек и объявлением функций.
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>

const float eps = 1e-6; ///< Погрешность вычислений.

const int INF_SOL = -1;///< Бесконечное число корней.
const int  NO_SOL = 0;///< Нет корней.
const int ONE_SOL = 1;///< Один корень.
const int TWO_SOL = 2;///< Два корня.

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