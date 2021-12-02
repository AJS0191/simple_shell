#include "main.h"

unsigned long int loopcount = 0;

int main(int ac, char **av)
{
	char **argv = NULL;
	(void) ac;
	(void) av;

	if (ac > 1)
		shell_error(cant_open, av[1]);

	while (1)
	{
		prompt();
		argv = splitter(get_input(), " ");
		printf("argv0 is %s\n", argv[0]);
		printf("argtocom is %s\n", argtocom(argv[0]));
		is_program(argv);
		free(argv);
	}
}
