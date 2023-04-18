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
	char *text_inputed_copy = NULL;
	int numOfTokens = 0, i = 0;
	/*
	 * declaring void variables
	 * because we haven't used them yet
	 * to enable compile
	 */
	(void)ac;
	(void)av;

	printf("Shell Started... To exit \"press Enter Twice\"\n");
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
			text_inputed_copy = malloc(length_textinputed * sizeof(char *));
			if (text_inputed_copy == NULL)
			{
				perror("Err: uunable to allocate memory to 'text_inputed_copy'");
				return (-1);
			}
			strcpy(text_inputed_copy, text_inputed);
		/*get number of tokens passed in or number of words*/
			numOfTokens = count_numofTokens(text_inputed);
			av = getTokens(text_inputed_copy, av); 
			printf("%s\n", text_inputed);
			printf("%ld\n", length_textinputed);
			printf("%d\n", numOfTokens);
			for (i = 0; i < numOfTokens; i++)
			{
				printf("%s\n", av[i]);
			}

		}	
	}
	free(text_inputed);

	return (0);
}

int count_numofTokens(char *text_inputed)
{
	char *token, *delim = " ";
	int count = 0;

	token = strtok(text_inputed, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);

	}
	return (count);
}

char** getTokens(char *text_inputed_copy, char *av[])
{
	char *token, *delim = " ";
//	char *arr[numOfTokens];
	int i = 0;

	token = strtok(text_inputed_copy, delim);
	while (token != NULL)
	{
		av[i] = token;	
		i++;
		token = strtok(NULL, delim);
	}
	return (av);

}

