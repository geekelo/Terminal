#include "main.h"

/**
 *
 *
 */

int main(int ac, char *av[])
{
/*
 * a prompt that shows up when expecting input
 * from user
 */
	char *prompt = "typecommand $";
	char *text_inputed;
	size_t n;
	ssize_t length_textinputed;
	/*
	 * declaring void variables
	 * because we haven't used them yet
	 * to enable compile
	 */
	(void)ac;
	(void)av;

	printf("Shell Started... To exit \"press Enter\"\n");
/*
 * this loop keeps the shell running once started
 * without the loop the shell runce once and automatically exits
 * This loop exits if the length of the input is <= 1 before pressing enter
 */
	while (1)
	{

	/* prints the promp text and icon*/
		printf("%s ", prompt);

	/*
	 * calls the getline function and prints the
	 * text inputed by the user
	 */
		/*
		 * this fuctn  inbuilt in stdio.h
		 * takes string inputs from users
		 * lineptr holds the text, n- no. of text,
		 * stdin source of input (keyboard)
		*/
		length_textinputed = getline(&text_inputed, &n, stdin);
		if (length_textinputed <= 1) 
		{
			printf("Shell Exited!...\n");
			free(text_inputed);
			return (-1);
		}
		else
		{
			printf("%s\n", text_inputed);
			printf("%ld\n", length_textinputed);	
		}	
	}
	free(text_inputed);

	return (0);
}

