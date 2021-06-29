#include <unistd.h>
#include <string.h>

void	put_char(unsigned char c)
{
	if (c >= 32 && c <= 126)
	{
		write(1, &c, 1);
	}
	else
	{
		c = '.';
		write(1, &c, 1);
	}
}

void	put_hex(unsigned long h)
{
	if (h <= 0xf && h > 0x0)
	{
		if (h >= 0x0 && h <= 0x9)
		{
			put_char(h + '0');
		}
		else if (h >= 0xa && h <= 0xf)
		{
			put_char(h - 0xa + 'a');
		}
	}
	else if (h > 0xf)
	{
		put_hex(h >> 4);
		if ((h % 0x10) >= 0x0 && (h % 0x10) <= 0x9)
		{
			put_char((h % 0x10) + '0');
		}
		else if ((h % 0x10) >= 0xa && (h % 0x10) <= 0xf)
		{
			put_char((h % 0x10) - 0xa + 'a');
		}
	}
}

void	put_buf(unsigned long n, int count)
{
	while (n)
	{
		count--;
		n >>= 4;
	}
	while (count--)
	{
		write(1, "0", 1);
	}
}

void	print_line(void *addr, void *end)
{
	unsigned int			i;
	unsigned char			hex;

	put_buf((unsigned long)addr, 16), put_hex((unsigned long)addr);
	write(1, ": ", 2), i = 0;
	while (i < 0x10)
	{
		if (addr + i >= end)
			write(1, "  ", 2);
		else
			hex = *((char *)addr + i), put_buf(hex, 2), put_hex(hex);
		if (i++ % 2 == 1)
			put_char(' ');
	}
	i = 0;
	while (i < 0x10)
	{
		if (addr + i >= end)
			break ;
		put_char(*((char *)addr + i)), i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*end;
	int		i;

	i = 0;
	end = addr + size;
	while ((addr + (0x10 * i)) < end)
	{
		print_line(addr + (0x10 * i), end);
		i++;
	}
	return (addr);
}
