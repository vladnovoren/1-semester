//заголовочный файл

//Str - структура для хранения информации о строке
//str - строка, length - её длина
struct Str{
	char *str;
	int length;
};

//Read_Buff производит считывание символов из указателя f файла input.txt в буфер buff
// и возвращает в size кол-во символов в файле, а в strcnt кол-во строк в файле
int Read_Buff(FILE *f, char **buff, int *size, int *strcnt);

//Make_Index заполняет массив структур index данными о строках
int Make_Index(char *buff, struct Str **index, int *size, int *strcnt);

//Is_Legit_Symb возвращает 1, если x является русской/латинской буквой или цифрой, иначе возвращает 0
int Is_Legit_Symb(unsigned char x);

//Str_Comp_Begin сравнивает строки str1 и str2 СЛЕВА НАПРАВО и возвращает:
// 1, если str1 > str2
// 0, если str1 == str2
//-1, если str2 < str1
int Str_Comp_Begin(const struct Str *str1, const struct Str *str2);

//Str_Comp_End сравнивает строки str1 и str2 СПРАВА НАЛЕВО и возвращает:
// 1, если str1 > str2
// 0, если str1 == str2
//-1, если str2 < str1
int Str_Comp_End(const struct Str *str1, const struct Str *str2);

//Компоратор, возвращаюший 
// 1, если a > b
// 0, если a == b
//-1, если a < b
//Предназначен для сравнивания строк СЛЕВА НАПРАВО
int Comparator_Begin(const void *a, const void *b);

//Компоратор, возвращаюший 
// 1, если a > b
// 0, если a == b
//-1, если a < b
//Предназначен для сравнивания строк СПРАВА НАЛЕВО
int Comparator_End(const void *a, const void *b);

//Make_Index_Origin копирует массив index в массив index_first для дальнейшего
//вывода текста в оригинальном виде
int Make_Index_Origin(int strcnt, struct Str *index, struct Str **index_first);

//Output_Text записывает данные из массива index 
//в файл, на который указывает f
int Output_Text(struct Str *index, int strcnt, FILE *f);