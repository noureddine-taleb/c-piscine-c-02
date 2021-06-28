#include <stdio.h>

char *ft_strlowcase(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}
		str++;
	}
}

int is_alphanum(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	if (c >= 'A' && c <= 'Z')
		return 1;
	if (c >= '1' && c <= '9')
		return 1;
	return 0;
}

void ctoupper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

char *ft_strcapitalize(char *str)
{
	if (!*str)
		return str;
	ft_strlowcase(str);
	if (is_alphanum(*str))
	{
		ctoupper(str);
	}
	str++;
	while (*str)
	{
		if (is_alphanum(*str) && !is_alphanum(*(str - 1)))
		{
			ctoupper(str);
		}
		str++;
	}
	return str;
}

int main()
{
	char str[] = {'h', 'e', 'l', 'l', 'O', ',', 'w', 'o', 'R', 'l', 'd', '!', '\0'};
	char str2[] = {'s', 'a', 'l', 'u', 't', ',', ' ', 'c', 'o', 'm', 'm', 'e', 'n', 't', ' ', 't', 'u', ' ', 'v', 'a', 's', ' ', '?', ' ', '4', '2', 'm', 'o', 't', 's', ' ', 'q', 'u', 'a', 'r', 'a', 'n', 't', 'e', '-', 'd', 'e', 'u', 'x', ';', ' ', 'c', 'i', 'n', 'q', 'u', 'a', 'n', 't', 'e', '+', 'e', 't', '+', 'u', 'n', '\0'};
	printf("%s\n", str2);
	ft_strcapitalize(str2);
	printf("%s\n", str2);
}