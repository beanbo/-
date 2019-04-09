#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<locale.h>
#include"stack.h"

int main() {
	setlocale(LC_ALL, "rus");
	struct FILO *head;    // адрес, указывающий на голову стека
	head = NULL;
	head = menu(head);
	free(head);
	return 0;
}
