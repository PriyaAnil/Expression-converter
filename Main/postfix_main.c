#include <stdio.h>
#include <infix.h>

int main()
{
	char buff[100], array[100];

	// Read the expression
	printf("Enter the infix expression: ");
	scanf("%s", array);

	//Infix to postfix conversion
	infix_postfix_conversion(array, buff);
	
	printf("Postfix expression = %s\n", buff);

	// Infix to postfix evaluation
	infix_postfix_evaluation(buff);

	return 0;	
}
