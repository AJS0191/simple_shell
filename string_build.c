#include "main.h"

char *_itoa(unsigned long int value, char *newString)
{
	int i = 0;
	unsigned long int n = value;
	unsigned long int r;

	newString[11] =  '\0';

	while (n)
	{
		r = n % 10;
		newString[11 - i - 1] = r + 48;
		n = n / 10;
		i++;
	}

	return (newString + 11 - i);
}

char *_strcat(char *desty, char *src)
{
	int goback = 0;
	int i = 0;
	char *retval;

	char dest[PATH_MAX];

	while (*(desty + i) != '\0')
	{
		dest[i] = *(desty + i);
		i++;
		goback++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[goback] = *(src + i);
		i++;
		goback++;
	}
	dest[goback] = '\0';

	retval = dest;
	return (retval);
}

char *string_build(char *command, int errorno)
{
	char this_shell[] = "hsh: ";
	char notfound[] = "not found";
	char noaccess[] = "Permission denied";
	char *colon = ": ";
	char itoahold[12];
	char catholder[PATH_MAX];
	char *errptr;


	strcpy(itoahold, _itoa(1, itoahold));

	strcpy(itoahold, _strcat(itoahold, colon));
	strcpy(catholder, _strcat(this_shell, itoahold));

	strcpy(command, _strcat(command, colon));
	strcpy(catholder, _strcat(catholder, command));

	switch (errorno)
	{
	case no_access :
		errptr = noaccess;
		break;
	case not_found :
		errptr = notfound;
		break;
	}

	strcpy(catholder, _strcat(catholder, errptr));

	errptr = catholder;
	return (errptr);
}
