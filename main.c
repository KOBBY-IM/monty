#include "monty.h"

/*stack_t **global_head;  pointer to the global head of stack */

/**
 * main - the main fucntion of the programme
 * @argc: number of arguments passed to the programme
 * @argv: arguments vector
 *
 * Return: on scuccess, always EXIT_SUCCESS
 */

int main(int argc, char *argv[])
{
	stack_t *head;

	/*check if the number of arguments is correct */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*set new stack node to global head */
	head = NULL;
	global_head = &head;

	/*Read the file and parse the instruction */
	read_file(argv[1], &head);

	atexit(global_free); /*free memory allocated to stack*/

	exit(EXIT_SUCCESS);
}
