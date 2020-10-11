/**
 * @file
 * @brief Содержит код main'а.
*/
#include "funcs.h"

/**
 * @brief Описывает общий алгоритм программы\n
 * Открываются файлы для чтения (f) и записи (fout) в бинарном режиме по путям, переданным в коммандную строку.\n
 * Выделяется буфер buff, в который мы передаем текст с помощью функции Read_Buff.\n
 * В массиве указателей index по их адресам посредством функции Make_Index собирается информация о строках файла.\n
 * С помощью qsort мы сортируем строки, передавая параметром нужный компаратор Str_Comp_Begin либо Str_Comp_End
 * С помощью функций Output_Sorted_Text и Output_Original_Text выводим сортированный либо несортированный тексты
 * @param argc Количество аргументо командной строки, включая исполняющий файл
 * @param argv
 * argv[1] (первый аргумент после имени исполняющего файла) - должен содержать путь к файлу,
 * в котором хранится сортируемый текст\n
 * argv[2] (второй аргумент после имени исполняющего файла) - должен содержать путь к файлу,
 * в который выведется отсортированный двумя способами текст и его исходник.
*/
int main(int argc, const char *argv[]){
	
	printf("Hello! This is a line sorter of the novel by Alexander Pushkin \"Eugene Onegin\".\n");

	if(argc < 3){
		printf("Insufficient arguments passed when calling the program. Please try again.\n(First enter input file path, then enter output file path)\n");
		return 0;
	}
	
	FILE *f = fopen(argv[1], "rb");
	if(f == NULL){
		printf("Error reading file \"%s\"\n", argv[1]);
		return 0;
	}

	FILE *fout = fopen(argv[2] , "wb");
	if(f == NULL){
		printf("Error reading file \"%s\"\n", argv[2]);
		return 0;
	}

	char *buff = 0;
	
	int strcnt = 0;

	int size = 0;

	struct Str *index = 0;

	strcnt = File_To_Index(f, &buff, &index, &size);

	Quick_Sort(index, 0, strcnt - 1, Str_Comp_Begin);

	fputs("/* Left-to-right sorted lines */\n", fout);
	Output_Sorted_Text(fout, index, strcnt);
	fputs("/*............................*/\n\n", fout);


	Quick_Sort(index, 0, strcnt - 1, Str_Comp_End);

	fputs("/* Right-to-left sorted lines */\n", fout);
	Output_Sorted_Text(fout, index, strcnt);
	fputs("/*............................*/\n\n", fout);


	fputs("/* Original text */\n", fout);
	Output_Original_Text(fout, buff, size);
	fputs("/*...............*/\n", fout);

	fclose(fout);
	free(buff);
	free(index);
	return 0;
}
