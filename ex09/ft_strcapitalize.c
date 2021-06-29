void	ft_strlowcase(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

int	is_alphanum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ctoupper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str[i])
		return (str);
	ft_strlowcase(str);
	if (is_alphanum(str[i]))
		ctoupper(str);
	i++;
	while (str[i])
	{
		if (is_alphanum(str[i]) && !is_alphanum(str[i - 1]))
			ctoupper(&str[i]);
		i++;
	}
	return (str);
}

