unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!size)
		return i;
	while(--size)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = 0;
	return ++i;
}