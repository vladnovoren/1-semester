/**
 * @file
 * @brief Включает заголовочные файлы используемых библиотек и содержит объявления основных функций программы.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <locale.h>
#include <stdlib.h>

#define LEFT_SORTING   1
#define RIGHT_SORTING -1

/**
 * @brief Хранит информацию о строке.
 * str - Строка.
 * length - Длина строки.
*/
typedef struct Str{
	char *str;
	int length;
} Str;

/**
 * @brief Находит количество символов в файле.
 * @param f Указатель на файл, размер которого нужно найти.
 * @return Возвращает количество символов в файле. 
*/
int Size_Of_File(FILE *f);


/**
 * @brief Меняет определенные символы на другие указанные.
 * @param buff Буфер.
 * @param size Размер буфера.
 * @param from Символы, которые нужно поменять.
 * @param to Символы, на которые нужно поменять.
 * @return Возвращает количество измененных символов.
*/
int Change_Symbol(char *buff, int size, char from, char to);

 /**
  * @brief Делит буфер на строки и заполняет ими массив index.
  * @param buff Исходный буфер.
  * @param Index Массив для строк.
  * @param size Размер буфера.
  * @return Возвращает количество строк.
 */
int File_To_Index(FILE *f, char **buff, Str **index, int *size);

/**
 * @brief Записывает в буфер данные из файла.
 * @param f Файл для чтения.
 * @param buff Буфер.
 * @return Возвращает размер буфера. 
*/
int Write_To_Buff(FILE *f, char **buff);

/**
 * @brief Заполняет массив строками из буфера.
 * @param buff Буфер.
 * @param index Массив.
 * @param strcnt Количество строк.
*/
void Make_Index(char *buff, Str **index, int strcnt);

/**
 * @brief Проверяет, является ли символ русской или латинской буквой или цифрой или нет.
 * @param x Проверяемый символ.
 * @return 1, если является, иначе 0.
*/
int Is_Legit_Symb(unsigned char symb);

/**
 * @brief Определяет номер символа, с которого пойдет обработка строки, для определенного режима сортировки.
 * @param len Длина строки.
 * @param slider Режим сортировки.
 * @return len - 1, если сортировка справа, 0, если сортировка слева.
*/
int Start_Num(int len, int slider);

/**
 * @brief Сравнивает две строки.
 * @param Str1 Первая строка.
 * @param Str2 Вторая строка.
 * @param slider Режим сортировки.
 * @return 1, если Str1 > Str2; 0, если Str1 == Str2; -1, если Str1 < Str2.
*/
int Str_Comp(const Str *Str1, const Str *Str2, int slider);

/**
 * @brief Компоратор строк в режиме слева направо.
 * @param left_ptr Первая строка.
 * @param right_ptr Вторая строка.
 * @return 1, если left_ptr > right_ptr; 0, если left_ptr == right_ptr; -1, если left_ptr < right_ptr.
*/
int Str_Comp_Begin(const void *left_ptr, const void *right_ptr);

/**
 * @brief Компоратор строк в режиме слева направо.
 * @param left_ptr Первая строка.
 * @param right_ptr Вторая строка.
 * @return 1, если left_ptr > right_ptr; 0, если left_ptr == right_ptr; -1, если left_ptr < right_ptr.
*/
int Str_Comp_End(const void *left_ptr, const void *right_ptr);

/**
 * @brief Выводит отсортированный текст в файл.
 * @param fout Файл, в который производится вывод.
 * @param index Массив строк, из которого ведется запись.
 * @param strcnt Количество строк.
*/
void Output_Sorted_Text(FILE *fout, Str *index, int strcnt);

/**
 * @brief Выводит исходный текст в файл.
 * @param fout Файл, в который производится вывод.
 * @param buff Буфер, из которого идет вывод.
 * @param size Размер буфера.
*/
void Output_Original_Text(FILE *fout, char *buff, int size);

/**
 * @brief Находит минимум двух строк.
 * @param str1 Первая строка.
 * @param str2 Вторая строка.
 * @param comp Компаратор строк.
 * @return str1, если str1 < str2, иначе str2.
*/
Str Minimum(Str str1, Str str2, int (*comp) (const void *, const void *));

/**
 * @brief Находит максимум двух строк.
 * @param str1 Первая строка.
 * @param str2 Вторая строка.
 * @param comp Компаратор строк.
 * @return str1, если str1 > str2, иначе str2.
*/
Str Maximum(Str str1, Str str2, int (*comp) (const void *, const void *));

/**
 * @brief Находит среднюю среди трех строк.
 * @param str1 Первая строка.
 * @param str2 Вторая строка.
 * @param str3 Третья строка.
 * @param comp Компаратор.
 * @return Возвращает средню. из трех строк.
*/
Str Medium(Str str1, Str str2, Str str3, int (*comp)(const void *, const void *));

/**
 * @brief Меняет значения строк.
 * @param first Указатель на первую строку.
 * @param second Указатель на вторую строку.
*/
void Swap(Str *first, Str *second);

/**
 * @brief Сортирует массив строк методом быстрой сортировки.
 * @param array Массив строк.
 * @param left Левая граница массива.
 * @param right Правая граница массива.
 * @param comp Компаратор.
*/
void Quick_Sort(Str *array, int left, int right, int (*comp) (const void *, const void *));