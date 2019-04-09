#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>
#include"files.h"
#include"stack.h"

FILE *createFile(FILE *fl)
{
	fflush(stdin);
	char *name, *dos;
	name = (char*)calloc(1,1);
	dos = (char*)calloc(1,1);
	if(fl != NULL) fclose(fl);
	printf("¬ведите им€ файла: ");
	gets_s(name,256);
	name = strcat(name,".txt");
	printf("¬ведите режим доступа к файлу\nr-чтение, w - создание, a - создание или долнение в конец: ");
	gets_s(dos, 256);
	if( strcmp(dos,"a") && strcmp(dos,"w") && strcmp(dos,"r") ) createFile(fl);
	dos = strcat(dos,"+");
	if (!(fl = fopen(name,dos))) 
	{ 
		puts("‘айл инвалид. ќткрыватьс€ не хочет."); 
		getch();
		system("cls");
		createFile(fl);
	} 
	if( (!(strcmp(dos,"a+"))) || (!(strcmp(dos,"w+"))) ) inputFile(fl);
	return fl;
}
void inputFile(FILE *fl)
{
	char *buf,z;
	buf = (char*)calloc(1,1);
	rewind(fl);
	do{
	fflush(stdin);
	printf("\n¬ведите строку: ");
	gets_s(buf, 256);
	fputs(buf,fl);
	printf("ƒл€ выхода нажмите 1: ");
	z = getch();
	}while(z != '1');
}
void outputFile(FILE *fl)
{
	char *buf;
	buf = (char*)calloc(1,1);
	rewind(fl);
	while(!(feof(fl)))	
	{
		fgets(buf,255,fl);
		puts(buf);
	}
}
int checkCode()
{
	FILE *fl;
	fl = NULL;
	fl = createFile(fl);
	if(fl == NULL) 
	{
		printf("‘айл не открыт");
		return -1;
	}
	struct FILO *head;    // адрес, указывающий на голову стека
	head = NULL;
	char *word;
	word = (char*)calloc(1,1);
	rewind(fl);
	while(!(feof(fl)))
	{
		fflush(stdin);
		fscanf(fl,"%s",word);
		if(strcmp(word,"begin") == 0) head = push(head,1);
		if(strcmp(word,"end") == 0) 
		{
			if(head == NULL) return 0; //возвращает 0, если код писал говнокодер
			head = pop(head);
		}
	}
	if(head == NULL) return 1; //возращает 1, если код написан правильно
	free(head);
	return 0; //возвращает 0, если код писал говнокодер
}