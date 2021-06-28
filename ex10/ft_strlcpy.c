unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (src[len])
	{
		len++;
	}
	while(*src && --size > 0)
	{
		*dest++ = *src++;
	}
	*dest = 0;
	return (len);
}
