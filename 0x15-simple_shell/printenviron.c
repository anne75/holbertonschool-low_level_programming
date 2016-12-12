#include "shell.h"





/**
 * main - prints environment, using global variable environ
 *
 * Return: always 0
 */
int main(void)
{
	int i;
	extern char **environ;
	char *s[] = {"MAIL", "PATH", "HELLO", NULL};
	path_t *head;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i++]);
	}
	puts("Trying to get environment variables\n");
	i = 0;
	while (s[i] != NULL)
	{
		printf("%s %i ", __FILE__, __LINE__);
		printf("%s\n", s[i]);
		printf("%s is %s\n", s[i], _getenv(s[i]));
		++i;
	}
	puts("Print path\n");
	print_path();
	puts("Done this way");
	head = NULL;
	link_path(&head);
	puts("with linked list");
	while (head != NULL)
	{
		printf("%s\n", head->path);
		head = head->next;
	}
	free_list(head);
	puts("working with environ");
	i = _setenv("Hello", "world", 1);
	if (i != 0)
		printf("failed to insert variable\n");
	printf("value of Hello %s\n", _getenv("Hello"));
	puts("Environ again");
	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i++]);
	}
return (0);
}
