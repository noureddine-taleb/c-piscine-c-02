unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_memcpy(char *dst, char *src, unsigned int size)
{
	char	*dest;

	dest = dst;
	while (size)
	{
		*dst++ = *src++;
		size--;
	}
	return (dest);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	srclen;

	srclen = ft_strlen(src);
	if ((srclen + 1) < size)
	{
		ft_memcpy(dest, src, srclen + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen);
}
