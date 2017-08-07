#include <stdio.h>
#include <string.h>
#include <stackarr.h>
#include <astack.h>
#include <infix.h>

// Set flag function
int set_flag(char ch)
{
	if (ch == '(' || ch == ')')
		return 0;

	else if (ch == '+' || ch == '-')
		return 1;

	else if (ch == '*' || ch == '/')
		return 2;
}

// Infix to postfix conversion
void infix_postfix_conversion(char *arr, char *buff)
{
	char stack[100], ch, op, s_peak;
	int size = 100, index, j_index = 0, s_flag = 0, flag = 0, stop = 0, top = 0;

	for (index = 0; arr[index] != '\0'; index++)
	{
	
		// If it is an operand
		if (arr[index] >= '0' && arr[index] <= '9')

			// Copy the operands to a buffer
			buff[j_index++] = arr[index];

		else
		{
			// Add space
			if (buff[j_index - 1] != ' ')
				buff[j_index++] = ' ';

			// If open bracket comes
			if (arr[index] == '(')

				//Push it to stack
				push_c(stack, &top, size, arr[index]);

			// If closed bracket arrives
			else if (arr[index] == ')')
			{

				// Pop all the operations till open bracket to the buffer
				while ((ch = pop_c(stack, &top)) != '(')
					buff[j_index++] = ch;
			}

			else 
			{

				// If stack is empty 
				if (top == 0)

					// Push operation to stack
					push_c(stack, &top, size, arr[index]);

				else
				{

					// Set flag for operation
					flag = set_flag(arr[index]);

					while (1)
					{
						// Get the peak value of top of stack
						s_peak = peak_c(stack, top);

						// Set flag for top of stack
						s_flag = set_flag(s_peak);

						// Check for precedence
						if (s_flag < flag)
						{

							// Pusk operation to stack
							push_c(stack, &top, size, arr[index]);
							break;
						}

						else
						{
							// Get the operation
							op = pop_c(stack, &top);

							if (op == '\0')
							{
								// Push to stack
								push_c(stack, &top, size, arr[index]);
								stop = 1;
							}

							else
							{
								// Pop operation from stack to buffer
								buff[j_index++] = op;
								stop = 0;
							}
						}

						if (stop)
							break;
					}
				}
			}
		}
	}
	
	// Pop operation from stack to the buffer
	while ((ch = pop_c(stack, &top)) != '\0' )
		buff[j_index++] = ch;

	buff[j_index] = '\0';
}

// Infix to postfix evaluation
void infix_postfix_evaluation(char *buff)
{	
	int result, val1 , val2, num, index = 0, j_index;
	int stack[100], size = 100, top = 0;
	char arr[100];

	while (buff[index] != '\0')
	{
		j_index = 0;

		// Get all the operands to a buffer array
		while (buff[index] != '\0' && buff[index] != ' ' && buff[index] >= '0' && buff[index] <= '9')
			arr[j_index++] = buff[index++];
		
		arr[j_index] = '\0';
		
		// Converting operands from ascii to integer
		if (j_index != 0)
		{
			sscanf(arr, "%d", &num);

			// Push the operands into stack
			push_i(stack, &top, size, num);
		}

		if (buff[index] != '\0' && buff[index] != ' ')
		{
			// Pop top two operands from the stack
			val1 = pop_i(stack, &top);
			val2 = pop_i(stack, &top);
			
			switch (buff[index])
			{
				case '+':

					// Add and push the result to stack
					result = val2 + val1;
					push_i(stack, &top, size, result);
					break;

				case '-':

					// Subtract and push the result to stack
					result = val2 - val1;
					push_i(stack, &top, size, result);
					break;

				case '*':
					
					// Multiply and push the result to stack
					result = val2 * val1;
					push_i(stack, &top, size, result);
					break;

				case '/':
					
					// Divide and push the result to stack
					result = val2 / val1;
					push_i(stack, &top, size, result);
					break;
			}
		}

		if (buff[index] != '\0')
			index++;
	}

	// Print the result
	printf("Result = %d\n", pop_i(stack, &top));
}

// Reverse sring function
void reverse_string(char *buff)
{
	int index, temp, length;

	length = strlen(buff);

	for (index = 0; index < length / 2; index++)
	{
		temp = buff[length - 1 - index];
		buff[length - 1 - index] = buff[index];
		buff[index] = temp;
	}
}

// Infix to prefix conversion
void infix_prefix_conversion(char *arr, char *buff)
{
	char stack[100], ch, op, s_peak;
	int size = 100, index, j_index = 0, s_flag = 0, flag = 0, stop = 0, top = 0;

	// Reverse expression
	reverse_string(arr);

	for (index = 0; arr[index] != '\0'; index++)
	{
	
		// If it is an operand
		if (arr[index] >= '0' && arr[index] <= '9')

			// Copy the operands to a buffer
			buff[j_index++] = arr[index];

		else
		{
			// Add space
			if (buff[j_index - 1] != ' ')
				buff[j_index++] = ' ';

			// If closed bracket comes
			if (arr[index] == ')')

				//Push it to stack
				push_c(stack, &top, size, arr[index]);

			// If open bracket arrives
			else if (arr[index] == '(')
			{

				// Pop all the operations till closed bracket to the buffer
				while ((ch = pop_c(stack, &top)) != ')')
					buff[j_index++] = ch;
			}

			else 
			{

				// If stack is empty 
				if (top == 0)

					// Push operation to stack
					push_c(stack, &top, size, arr[index]);

				else
				{

					// Set flag for operation
					flag = set_flag(arr[index]);

					while (1)
					{
						// Get the peak value of top of stack
						s_peak = peak_c(stack, top);

						// Set flag for top of stack
						s_flag = set_flag(s_peak);

						// Check for precedence
						if (s_flag <= flag)
						{

							// Pusk operation to stack
							push_c(stack, &top, size, arr[index]);
							break;
						}

						else
						{
							// Get the operation
							op = pop_c(stack, &top);

							if (op == '\0')
							{
								// Push to stack
								push_c(stack, &top, size, arr[index]);
								stop = 1;
							}

							else
							{
								// Pop operation from stack to buffer
								buff[j_index++] = op;
								stop = 0;
							}
						}

						if (stop)
							break;
					}
				}
			}
		}
	}
	
	// Pop operation from stack to the buffer
	while ((ch = pop_c(stack, &top)) != '\0' )
		buff[j_index++] = ch;

	buff[j_index] = '\0';
	
	// Reverse the expression
	reverse_string(buff);
}

// Infix to prefix evaluation
void infix_prefix_evaluation(char *buff)
{	
	int result, val1 , val2, num, index = strlen(buff), j_index;
	int stack[100], size = 100, top = 0;
	char arr[100];

	while (index >= 0)
	{
		j_index = 0;

		// Get all the operands to a buffer array
		while (index >= 0 && buff[index] != ' ' && buff[index] >= '0' && buff[index] <= '9')
			arr[j_index++] = buff[index--];
		
		arr[j_index] = '\0';

		// Reverse the number
		reverse_string(arr);
		
		// Converting operands from ascii to integer
		if (j_index != 0)
		{
			sscanf(arr, "%d", &num);

			// Push the operands into stack
			push_i(stack, &top, size, num);
		}

		if (buff[index] != '\0' && buff[index] != ' ')
		{
			// Pop top two operands from the stack
			val1 = pop_i(stack, &top);
			val2 = pop_i(stack, &top);
			
			switch (buff[index])
			{
				case '+':

					// Add and push the result to stack
					result = val1 + val2;
					push_i(stack, &top, size, result);
					break;

				case '-':

					// Subtract and push the result to stack
					result = val1 - val2;
					push_i(stack, &top, size, result);
					break;

				case '*':
					
					// Multiply and push the result to stack
					result = val1 * val2;
					push_i(stack, &top, size, result);
					break;

				case '/':
					
					// Divide and push the result to stack
					result = val1 / val2;
					push_i(stack, &top, size, result);
					break;
			}
		}

		if (index >= 0)
			index--;
	}

	// Print the result
	printf("Result = %d\n", pop_i(stack, &top));
}


