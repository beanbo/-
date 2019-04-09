#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>
#include"stack.h"
#include"files.h"

struct FILO *push(struct FILO *head, int x) 
{
	struct FILO *n;    // ��������� �� ����� ���������
	n = (struct FILO *)malloc(sizeof(struct FILO)); // �������� ������
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
	struct FILO *n;    // ��������� �� ����� ���������
	n = (struct FILO *)malloc(sizeof(struct FILO)); // �������� ������
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
	{   // ���� �� ����� �����    
		if(p->data > -500000)
		printf("%d ---> ", p->data);
		else
		printf("%c", p->symbol);
		p = p->next;       // ����������� �� ������
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
	printf("���� � ����\n(������� '*' � �����) ");
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
	printf("������� ������?");
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
		printf("\t   ���� \n");
		printf("\t 1 ���������� ��������� � ����\n");
		printf("\t 2 ���������� ��������� � ���� � �������� ���� � ������� �����-�� �������\n");
		printf("\t 3 �����\n");
		printf("\t 4 �������� ���������\n");
		printf("\t 5 ��������� ��� �� Pascal\n");
		printf("\t 0 �����\n");
		printf("�������� ����� ����\n");
		z=getch();
		switch(z)
		{
			case '1': 
				head = inputChar(head);
				break;
			case '2': 
				printf("\n��� ��������� ����� ������� *");
				head = inputAndDeleteDoubleHead(head);
				break;
			case '3': 
				print(head);
				break;
			case '4': 
				head = deleteHeads(head);
				break;
			case '5': 
				if(checkCode() == 1) printf("\n�������� ���!");
				else if(checkCode() == -1) printf("\n��� �����:(");
				else printf("\n��� �� ���, � �������!!!");
				break;
			case '0': 
				break;
			default: printf("\t�������� ����\n");
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