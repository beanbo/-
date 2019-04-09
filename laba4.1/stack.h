#pragma once 

struct FILO {
	union {
	int data;
	char symbol;
	}; 
	struct FILO *next;
};

struct FILO *push(struct FILO *, char);	
struct FILO *push(struct FILO *, int);  // ������������� �������� � ������, ������� ������ ������
void print(struct FILO *); // �������� �����
struct FILO *inputChar(struct FILO *);	// ���� �������� � ����
struct FILO *pop(struct FILO *); //�������� �������
struct FILO *deleteHeads(struct FILO *); //�������� ���������� ��������� 
struct FILO *inputAndDeleteDoubleHead(struct FILO *);
struct FILO *menu(struct FILO *);
int TrueInput(int value);