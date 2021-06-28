void put_char(char c)
{
	write(1, &c, 1);
}

void put_char2(char c)
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

void _put_hex(char hex)
{
	if (hex >= 0x0 && hex <= 0x9)
	{
		put_char(hex + '0');
	}
	else if(hex >= 0xa && hex <= 0xf)
	{
		put_char(hex - 0xa + 'a');
	}
}

void put_hex(unsigned long h)
{
	if (h <= 0xf && h > 0x0)
	{
		_put_hex(h);
	}
	else if (h > 0xf)
	{
		put_hex(h >> 4);
		_put_hex(h % 0x10);
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

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long end;

	end = (unsigned long)addr + size;
	while ((unsigned long)addr < end)
	{
		int	i;
	
		put_buf((unsigned long)addr, 16);
		put_hex((unsigned long)addr);
		write(1, ": ", 2);
		
		i=0;
		while (i < 0x10)
		{
			if (addr + i >= end)
			{
				write(1, "  ", 2);
			}
			else
			{
				char hex = *((char *)addr + i);
				put_buf(hex, 2);
				put_hex(hex);
			}
			if (i % 2 == 1)
				put_char(' ');
			i++;
		}
		i=0;
		while (i < 0x10)
		{
			if (addr + i >= end)
				break;
			put_char2(*((char *)addr + i));
			i++;
		}
		addr += 0x10;
		put_char('\n');
	}
}
