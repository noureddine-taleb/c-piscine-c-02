char *ft_strlowcase(char *str)
{
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'Z'))
			*str += 32;
		str++;
	}
}

char *ft_strcapitalize(char *str)
{
	ft_strlowcase(str);
	if (*str && is_alpha(*str))
	{
		*str -= 32;
		str++;
	}
	while (*str)
	{
		if (is_alpha(*str) && !is_alpha(*(str - 1)))
		{
			*str -= 32;
		}
	}
}