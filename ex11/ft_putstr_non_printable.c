#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	_put_hex(char hex)
{
	if (hex >= 0x0 && hex <= 0x9)
	{
		put_char(hex + '0');
	}
	else if (hex >= 0xa && hex <= 0xf)
	{
		put_char(hex - 0xa + 'a');
	}
}

void	put_hex(unsigned char c)
{
	put_char('\\');
	_put_hex(c >> 4);
	_put_hex(c & 0x0f);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
			put_hex(*str);
		str++;
	}
}
