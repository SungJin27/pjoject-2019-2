#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum {
	INTEGER = 0, REAL, NAN
}Type;
typedef struct __Number{
	Type t;
union {
	int i;
	double r;
	}data;
}Number;
typedef enum {
	ADD = 0, SUB, MUL, DIV
}Operation;
Number calculate(Number n1, Number n2, Operation op)
{
	Number n3;

	switch (op) {
	case 0:
		if (n1.t == 0 && n2.t == 0) {
			n3.t = 0;
			n3.data.i = n1.data.i + n2.data.i;
			return n3;
		}
		else if (n1.t == 0 && n2.t == 1) {
			n3.t = 1;
			n3.data.r = n1.data.i + n2.data.r;
			return n3;
		}
		else if (n1.t == 1 && n2.t == 0) {
			n3.t = 1;
			n3.data.r = n1.data.r + n2.data.i;
			return n3;
		}
		else {
			n3.t = 1;
			n3.data.r = n1.data.r + n2.data.r;
			return n3;
		}
	case 1:
		if (n1.t == 0 && n2.t == 0) {
			n3.t = 0;
			n3.data.i = n1.data.i - n2.data.i;
			return n3;
		}
		else if (n1.t == 0 && n2.t == 1) {
			n3.t = 1;
			n3.data.r = n1.data.i - n2.data.r;
			return n3;
		}
		else if (n1.t == 1 && n2.t == 0) {
			n3.t = 1;
			n3.data.r = n1.data.r - n2.data.i;
			return n3;
		}
		else {
			n3.t = 1;
			n3.data.r = n1.data.r - n2.data.r;
			return n3;
		}
	case 2:
		if (n1.t == 0 && n2.t == 0) {
			n3.t = 0;
			n3.data.i = n1.data.i * n2.data.i;
			return n3;
		}
		else if (n1.t == 0 && n2.t == 1) {
			n3.t = 1;
			n3.data.r = n1.data.i * n2.data.r;
			return n3;
		}
		else if (n1.t == 1 && n2.t == 0) {
			n3.t = 1;
			n3.data.r = n1.data.r * n2.data.i;
			return n3;
		}
		else {
			n3.t = 1;
			n3.data.r = n1.data.r * n2.data.r;
			return n3;
		}
	case 3:
		if (n2.t == 0 && n2.data.i == 0) {
			n3.t = 2;
			return n3;
		}
		else if (n2.t == 1 && n2.data.r == 0) {
			n3.t = 2;
			return n3;
		}
		
		if(n1.t == 0 && n2.t == 0){
			n3.t = 1;
			n3.data.r = n1.data.i / n2.data.i;
			return n3;
			}
		else if (n1.t == 0 && n2.t == 1) {
			n3.t = 1;
			n3.data.r = n1.data.i / n2.data.r;
			return n3;
		}
		else if (n1.t == 1 && n2.t == 0) {
			n3.t = 1;
			n3.data.r = n1.data.r / n2.data.i;
			return n3;
		}
		else {
			n3.t = 1;
			n3.data.r = n1.data.r / n2.data.r;
			return n3;
		}
	default:
		break;
	}
}
int main()
{
	Number a, b;
	Number c;
	int i;
	char arr1[10], arr2[10];
	int flag1 = -1, flag2 = -1;

	scanf("%s", arr1);
	scanf("%s", arr2);
	
	for (i = 0; i < strlen(arr1); i++) {
		if (arr1[i] == '.') {
			flag1 = 1;
			break;
		}
	}
	for (i = 0; i < strlen(arr2); i++) {
		if (arr2[i] == '.') {
			flag2 = 1;
			break;
		}
	}
	if (flag1 == 1) {
		a.t = 1;
		a.data.r = atof(arr1);
	}
	else {
		a.t = 0;
		a.data.i = atoi(arr1);
	}
	if (flag2 == 1) {
		b.t = 1;
		b.data.r = atof(arr2);
	}
	else {
		b.t = 0;
		b.data.i = atoi(arr2);
	}
	for (i = 0; i < 4; i++) {
		c = calculate(a, b, i);
		switch (i) {
		case 0: 
			printf("ADD ");
			break;
		case 1:
			printf("SUB ");
			break;
		case 2:
			printf("MUL ");
			break;
		case 3:
			printf("DIV ");
			break;
		default:
			break;
		}
		
		switch (c.t) {
		case 0:
			printf("%d INTEGER\n", c.data.i);
			break;
		case 1:
			printf("%f REAL\n", c.data.r);
			break;
		case 2:
			printf("NAN\n");
			break;
		default:
			break;
		}
	}
	return 0;
}
