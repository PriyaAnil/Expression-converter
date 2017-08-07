#include <stdio.h>
#include <infix.h>

int main()
{
	char buff[100], array[100], ch;
	int option;

	// Read the expression
	printf("Enter the infix expression: ");
	scanf("%s", array);


	//Infix to prefix conversion
	infix_prefix_conversion(array, buff);
	printf("Prefix expressiom = %s\n", buff);

	// Infix to prefix evaluation
	infix_prefix_evaluation(buff);

	return 0;	
}
