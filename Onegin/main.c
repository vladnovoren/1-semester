/**
 * @file
 * @brief Содержит код main'а.
*/
#include "funcs.h"

/**
 * @brief Описывает общий алгоритм программы
 * @param argc Количество аргументо командной строки, включая исполняющий файл
 * @param argv
 * argv[1] (первый аргумент после имени исполняющего файла) - должен содержать путь к файлу,
 * в котором хранится сортируемый текст
 * argv[2] (второй аргумент после имени исполняющего файла) - должен содержать путь к файлу,
 * в который выведется отсортированный двумя способами текст и его исходник.
*/
int main(int argc, const char *argv[]){
	
	printf("Hello! This is a line sorter of the novel by Alexander Pushkin \"Eugene Onegin\".\n");
	//если не указан файл вввода или файл вывода, просим пользователя запустить программу еще раз
	if(argc < 3){
		printf("Insufficient arguments passed when calling the program. Please try again.\n(First enter input file path, then enter output file path)\n");
		return 0;
	}
	
	//открытие файла для чтения по имени, переданному первым аргументом
	FILE *f = fopen(argv[1], "rb");
	if(f == NULL){
		printf("Error reading file \"%s\"\n", argv[1]);
		return 0;
	}
	//открытие файла для записи по имени, переданному вторым аргументом
	FILE *fout = fopen(argv[2] , "wb");
	if(f == NULL){
		printf("Error reading file \"%s\"\n", argv[2]);
		return 0;
	}

	char *buff = 0;
	
	//количество строк в исходном тексте
	int strcnt = 0;

	//количество символов в исходном тексте
	int size = 0;

	//вносим данные из файла в буфер, тк считывание данных с ПЗУ медленнее, чем с ОЗУ
	Read_Buff(f, &buff, &size, &strcnt);
	
	//объявление массива структур Str с данными о строках
	struct Str *index = 0;

	Make_Index( buff, &index, strcnt);

	//сортируем строки слева направо
	qsort(index, strcnt, sizeof(struct Str), (int (*)(const void*, const void*))Str_Comp_Begin);

	//выводим результат
	fputs("/* Left-to-right sorted lines */\n", fout);
	Output_Sorted_Text(index, strcnt, fout);
	fputs("/*............................*/\n\n", fout);

	//сортируем строки справа налево
	qsort(index, strcnt, sizeof(struct Str), (int (*)(const void*, const void*))Str_Comp_End);

	//выводим результат
	fputs("/* Right-to-left sorted lines */\n", fout);
	Output_Sorted_Text(index, strcnt, fout);
	fputs("/*............................*/\n\n", fout);

	//вывод оригинального текста
	fputs("/* Original text */\n", fout);
	Output_Original_Text(buff, size, fout);
	fputs("/*...............*/\n", fout);

	//закрываем файлы и освобождем динамическую память
	fclose(fout);
	free(buff);
	free(index);
	return 0;
}
