/**
 * @file
 * Файл с включением заголовков нужных библиотек и объявлением функций.
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>

const double eps = 1e-6;///< Погрешность вычислений.

const int INF_SOL = -1;///< Бесконечное число корней.
const int  NO_SOL = 0;///< Нет корней.
const int ONE_SOL = 1;///< Один корень.
const int TWO_SOL = 2;///< Два корня.

/**
 * @brief Проверяет, является ли число нулем.
 * @param a Проверяемое число.
 * @return Возвращает 1, если a == 0, иначе 0.
*/
int Check_Zero(double a);

/**
 * @brief Вводит коэффициент.
 * @param a Указывает на переменную, в которой находится значение коэффициента.
 * @param coef Символьное обозначение коэффициента
*/
void Enter_Coefficient(double* a, char coef);

/**
 * @brief Решает квадратное уравнение.
 * @param a Коэффициент а.
 * @param b Коэффициент b.
 * @param c Коэффициент c.
 * @param x1 Указатель на первый корень.
 * @param x2 Указатель на второй корень.
*/
int Solve_Quade(double a, double b, double c, double* x1, double* x2);

/**
 * @brief Считает дискриминант.
 * @param a Коэффициент a.
 * @param b Коэффициент b.
 * @param c Коэффициент c.
 * @return Возвращает значение дискриминанта.
*/
double Discrim(double a, double b, double c);