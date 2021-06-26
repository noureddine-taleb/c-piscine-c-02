char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	while (n)
	{
		*dest++ = *src++;
		n--;
	}
	return dest;
}
