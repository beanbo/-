#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>
#include"stack.h"
#include"files.h"

struct FILO *push(struct FILO *head, int x) 
{
	struct FILO *n;    // указатель на новую структуру
	n = (struct FILO *)malloc(sizeof(struct FILO)); // выделяем память
	n->next = NULL;
	n->data = x;
	if (head == NULL)
		head = n;
	else
	{
		n->next = head;
		head = n;
	}
	return head;
}

struct FILO *push(struct FILO *head, char x) 
{
	struct FILO *n;    // указатель на новую структуру
	n = (struct FILO *)malloc(sizeof(struct FILO)); // выделяем память
	n->next = NULL;
	n->symbol = x;
	if (head == NULL)
		head = n;
	else
	{
		n->next = head;
		head = n;
	}
	return head;
}

void print(struct FILO *head)
{
	struct FILO *p = head;
	while (p != NULL) 
	{   // пока не конец стека    
		if(p->data > -500000)
		printf("%d ---> ", p->data);
		else
		printf("%c", p->symbol);
		p = p->next;       // продвижение по списку
	}
	printf("\n");
	getch();
}


struct FILO *pop(struct FILO * head)
{
	if (head != NULL)
	{
		head = head->next;
		return head;
	}
	else return NULL;

}

struct FILO *inputChar(struct FILO *head)
{
	char c='0';
	printf("Ввод в стек\n(Введите '*' в конце) ");
	while (1)
	{
		
		//fflush(stdin);
		scanf("%c", &c); 
		if(c == '*') break;
		head = push(head, c);	
	}
	printf("\n");
	return head;
}

struct FILO *inputAndDeleteDoubleHead(struct FILO *head)
{
	char c='0';
	fflush(stdin);
	scanf("%c", &c); 
	if(c == '*') 
	{
		printf("\n");
		return head;
	}
	if(head == NULL)
	head = push(head, c);
	else if(head->symbol != c)
	head = push(head, c);
	else 
	head = pop(head);
	inputAndDeleteDoubleHead(head);
}

struct FILO *deleteHeads(struct FILO *head)
{
	int k = 0;
	printf("Сколько удалим?");
	k=TrueInput(k);
	while (k != 0 && head != NULL)
	{
		head = pop(head);
		k--;
	}
	return head;
}

struct FILO *menu(struct FILO *head)
{
	char z;
	do{
		system("cls"); 
		printf("\t   Меню \n");
		printf("\t 1 Добавление элементов в стек\n");
		printf("\t 2 Добавление элементов в стек и удаление если в головке такой-же элемент\n");
		printf("\t 3 Вывод\n");
		printf("\t 4 Удаление элементов\n");
		printf("\t 5 Проверить код на Pascal\n");
		printf("\t 0 Выход\n");
		printf("Веберите пункт меню\n");
		z=getch();
		switch(z)
		{
			case '1': 
				head = inputChar(head);
				break;
			case '2': 
				printf("\nДля остановки ввода введите *");
				head = inputAndDeleteDoubleHead(head);
				break;
			case '3': 
				print(head);
				break;
			case '4': 
				head = deleteHeads(head);
				break;
			case '5': 
				if(checkCode() == 1) printf("\nОтличный код!");
				else if(checkCode() == -1) printf("\nВсе плохо:(");
				else printf("\nЭто не код, а какашка!!!");
				break;
			case '0': 
				break;
			default: printf("\tНеверный ввод\n");
		} 
	}while(z!='0');
	return head;
}

int TrueInput(int value)
{
	while(scanf("%d",&value)!=1) 
	{ 
		printf("Retry: "); 
		flushall(); 
	}
	return value;
}