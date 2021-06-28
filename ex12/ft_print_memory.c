void put_char(char c)
{
	write(1, &c, 1);
}

void put_char2(char c)
{
	if (c >= 32 && c <= 127)
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
	if (h <= 0xf && h >= 0x0)
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
		int i;
	
		put_buf((unsigned long)addr, 16);
		put_hex((unsigned long)addr);
		put_char(':');
		put_char(' ');
		
		i=0;
		while (i < 0x8)
		{
			if (addr + (i*2) >= end)
				break;
			short hex = *((short *)addr + i);
			put_buf(hex, 4);
			put_hex(hex);
			i++;
			put_char(' ');
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

int main()
{
	char *str = "hello world!\n";
	// char *str2 = "hello world!\n no no no fuck yeah!!!!??, .,";
	// char *str3 = "";
	ft_print_memory(str, strlen(str)+1);
	// ft_print_memory(str2, strlen(str2)+1);
	// ft_print_memory(str3, strlen(str)+1);

}