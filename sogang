# pjoject-2019-2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	This function stores variables in name and value pointer.
	@param
	-command: getting name and value of variable
	-name: pointer that stores name of variable
	-value: pointer that stores value of variable
	-index: indicates which index to store variable
	@return
	-This function return nothing but if command satisfies
	the condition stores the variable in the pointer and increments
	index. Else	prints error message
*/

void INT(char* command, char** name, int* value, int* index)
{
	int check_INT;
	char check_name[30];
	int check_value[10];
	char enter_INT;

	check_INT = sscanf(command, "%s %d%c", check_name, check_value, &enter_INT);

	if (check_INT == 3 && enter_INT == '\n') {
		sscanf(command, "%s %d\n", name[*index], value + *index);
		(*index)++;
	}

	else printf("error\n");
}

/*
	This function prints value of the variable which is in the command.
	@param
	-command: getting name of variable
	-name: pointer that stores name of variables
	-value:	pointer that stores value of variables
	-index: the number points to the last saved variable's index
	@return
	This function return nothing but if the name is founded in the name 
	pointer prints its value. If not founded prints that notfound. Or the 
	command is not right, prints error message.
*/

void PRINT(char* command, char** name, int* value, int index)
{
	int j;
	int check_PRINT;
	char enter_PRINT;
	char check_name[30];
	int flag_PRINT = -1;
	check_PRINT = sscanf(command, "%s%c", check_name, &enter_PRINT);
	if (check_PRINT == 2 && enter_PRINT == '\n') {
		for (j = 0; j < index; j++) {
			if (strncmp(name[j], command, strlen(command) - 1) == 0) {
				flag_PRINT = 1;
				printf("%d\n", value[j]);
				break;
			}
		}

		if (flag_PRINT == -1) printf("not found\n");
	}
	else printf("error\n");
}

/*
	This function prints all name and value stored.
	@param
	-command: for checking the command is right
	-name: pointer that stores name of variables
	-value: pointer that stores value of variable
	-index: the number points to the last saved variable's index
	@return
	This function returns nothing but if there is any stored variables, prints all.
	Else if there is no variable prints empty,or prints error message when the command wrong.
*/

void PRINT_VARS(char* command, char** name, int* value, int index)
{
	int j;
	int check_PRINT_VARS;
	char enter_PRINT_VARS;
	check_PRINT_VARS = sscanf(command, "PRINT_VARS%c", &enter_PRINT_VARS);

	if (check_PRINT_VARS == 1 && enter_PRINT_VARS == '\n') {
		if (index == 0) printf("empty\n");
		else {
			for (j = 0; j < index; j++) {
				printf("%s=%d\n", name[j], value[j]);
			}
		}
	}
	else printf("error\n");
}

/*
	This function makes the program terminate.
	@param
	-command: for checking the commnad is correct
	-exit_flag: the flag that escapes the while loop
	@return
	This function returns nothing but if command is right, the program 
	breaks the while loop. If not prints error message.
*/

void EXIT(char* command, int* exit_flag)
{
	int check_EXIT;
	char enter_EXIT;

	check_EXIT = sscanf(command, "EXIT%c", &enter_EXIT);

	if (check_EXIT == 1 && enter_EXIT == '\n') *exit_flag = 1;
	else printf("error\n");
}

/*
	This fucntions executes an arithmetic operation.
	@param
	-command: storing symbol and operands
	-op: storing arithmetic sybols
	-operand1,2: storing operands
	-name: pointer that stores name of variables
	-value: pointer that stores value of variables
	-index: the number points to the last saved variable's index
	@return
	This function returns nothing. But executes an arithmetic operation with operands and op.
	If commands are not correct prints error message. 
*/

void OPERATION(char* command, char op, char* operand1, char* operand2, char** name, int* value, int index)
{
	int num1;
	int num2;
	int check_OPERATION;
	char enter_OPERATION;
	int j;
	int num1_flag = -1;
	int num2_flag = -1;
	int division_flag = -1;
	int operation_flag = -1;
	check_OPERATION = sscanf(command, "%s %c %s%c", operand1, &op, operand2, &enter_OPERATION);

	if (check_OPERATION == 4 && enter_OPERATION == '\n') {
		num1 = atoi(operand1);
		num2 = atoi(operand2);

		if (num1 == 0) {
			if (strcmp(operand1, "0") == 0) num1_flag = 1;
			else {
				for (j = 0; j < index; j++) {
					if (strcmp(name[j], operand1) == 0) {
						num1 = value[j];
						num1_flag = 1;
						break;
					}
				}
			}
		}
		else num1_flag = 1;

		if (num2 == 0) {
			if (strcmp(operand2, "0") == 0) num2_flag = 1;
			else {
				for (j = 0; j < index; j++) {
					if (strcmp(name[j], operand2) == 0) {
						num2 = value[j];
						num2_flag = 1;
						break;
					}
				}
			}
		}
		else num2_flag = 1;

		if (num1_flag == 1 && num2_flag == 1) {
			switch (op) {
			case '+':
				num1 = num1 + num2;
				break;
			case '-':
				num1 = num1 - num2;
				break;

			case '*':
				num1 = num1 * num2;
				break;

			case '/':
				if (num2 == 0) division_flag = 1;
				else {
					num1 = num1 / num2;
					break;
				}
			default:
				operation_flag = 1;
			}
			if (operation_flag == 1) printf("error\n");
			else {
				if (division_flag == 1) printf("error\n");
				else printf("%d\n", num1);
			}
		}
		else printf("error\n");
	}

	else printf("error\n");
}

int main()
{
	char** name;
	int* value;
	int i;
	int index = 0;
	int exit_flag = 0;
	char* command;
	char* operand1, * operand2;

	name = (char**)malloc(sizeof(char*) * 33);
	for (i = 0; i < 32; i++) {
		name[i] = (char*)malloc(sizeof(char) * 31);
	}

	value = (int*)malloc(sizeof(char) * 33);

	while (1) {
		char op;
		command = (char*)malloc(sizeof(char) * 128);
		operand1 = (char*)malloc(sizeof(char) * 30);
		operand2 = (char*)malloc(sizeof(char) * 30);

		if (exit_flag == 1) break;
		printf(">> ");
		fgets(command, 128, stdin);

		if (strncmp(command, "EXIT", 4) == 0) {
			EXIT(command, &exit_flag);
			continue;
		}

		else if (strncmp(command, "INT ", 4) == 0) {
			INT(command + 4, name, value, &index);
			continue;
		}

		else if (strncmp(command, "PRINT ", 6) == 0) {
			PRINT(command + 6, name, value, index);
			continue;
		}

		else if (strncmp(command, "PRINT_VARS", 10) == 0) {
			PRINT_VARS(command, name, value, index);
			continue;
		}

		else if (sscanf(command, "%s %c %s\n", operand1, &op, operand2) == 3) {
			OPERATION(command, op, operand1, operand2, name, value, index);
			continue;
		}
		else printf("error\n");
	}

	for (i = 0; i < 32; i++) {
		free(name[i]);
	}
	free(name);
	free(value);
	free(command);
	free(operand1);
	free(operand2);

	return 0;
}
