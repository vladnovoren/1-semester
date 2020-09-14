#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "funcs.h"




//
//
//
//
int main(int argc, char *argv[]){
	
	printf("Hello! This is a line sorter of the novel by Alexander Pushkin \"Eugene Onegin\"\n");

	setlocale(LC_ALL, "Russian");

	FILE *f = fopen(argv[1], "r");

	FILE *fout = fopen(argv[2] , "w");

	char *buff = 0;
	
	int strcnt = 0;

	int size = 0;

	Read_Buff(f, &buff, &size, &strcnt);
	
	struct Str *index = 0;

	struct Str *index_origin = 0;

	Make_Index( buff, &index, &size, &strcnt);
	
	Make_Index_Origin(strcnt, index, &index_origin);

	qsort(index, strcnt, sizeof(struct Str), Comparator_Begin);

	fputs("/* Left-to-right sorted lines */\n", fout);
	Output_Text(index, strcnt, fout);
	fputs("/*............................*/\n\n", fout);

	qsort(index, strcnt, sizeof(struct Str), Comparator_End);

	fputs("/* Right-to-left sorted lines */\n", fout);
	Output_Text(index, strcnt, fout);
	fputs("/*............................*/\n\n", fout);

	fputs("/* Original text */\n", fout);
	Output_Text(index_origin, strcnt, fout);
	fputs("/*...............*/\n", fout);

	fclose(f);
	fclose(fout);

	free(index_origin);
	free(index);
	free(buff - 1);
	return 0;
}
