#pragma once 

struct FILO {
	union {
	int data;
	char symbol;
	}; 
	struct FILO *next;
};

struct FILO *push(struct FILO *, char);	
struct FILO *push(struct FILO *, int);  // присоединение элемента к голове, возврат адреса головы
void print(struct FILO *); // просмотр стека
struct FILO *inputChar(struct FILO *);	// ввод символов в стек
struct FILO *pop(struct FILO *); //удаление головки
struct FILO *deleteHeads(struct FILO *); //удаление нескольких элементов 
struct FILO *inputAndDeleteDoubleHead(struct FILO *);
struct FILO *menu(struct FILO *);
int TrueInput(int value);