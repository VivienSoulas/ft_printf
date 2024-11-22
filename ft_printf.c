/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:53:33 by vsoulas           #+#    #+#             */
/*   Updated: 2024/11/22 13:53:02 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft.h"

//int	main(void)
//{
//	char			c;
//	char			*s;
//	void			*p;
//	int				d;
//	int				i;
//	unsigned int	u;
//	int				x;
//	int				X;

//	c = 'a';
//	s = "Codam";
//	p = &c;
//	d = 666;
//	i = INT_MIN;
//	u = 4294967295;
//	x = 568913;
//	X = 568913;
	
//	printf("\n");
//	printf("original printf:\n");
//	printf("char c = %c\n", c);
//	printf("string s = %s\n", s);
//	printf("pointer p = %p\n", p);
//	printf("int d = %d\n", d);
//	printf("int i = %i\n", i);
//	printf("unsigned decimal u = %u\n", u);
//	printf("hex lower x = %x\n", x);
//	printf("hexa upper X = %X\n", X);
//	printf("%%\n");
//	printf("trial %c, %s, %x, %u", c, s, x, u);
//	printf("\n\n");
	
//	ft_printf("my ft_printf:\n");
//	ft_printf("char c = %c\n", c);
//	ft_printf("string s = %s\n", s);
//	ft_printf("pointer p = %p\n", p);
//	ft_printf("int d = %d\n", d);
//	ft_printf("int i = %i\n", i);
//	ft_printf("unsigned decimal u = %u\n", u);
//	ft_printf("hex lower x = %x\n", x);
//	ft_printf("hexa upper X = %X\n", X);
//	ft_printf("%%\n");
//	ft_printf("trial %c, %s, %x, %u", c, s, x, u);
//	printf("\n");
//	return (0);
//}

int ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;

	if (format == NULL)
		return (0);
	i = 0;
	va_start(ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			ft_check_format(format, i + 1, ptr);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (i);
}

void	ft_check_format(const char *format, int i, va_list ptr)
{
	if (format[i] == 'c')
		ft_putchar(va_arg(ptr, int));
	if (format[i] == 's')
		ft_putstr(va_arg(ptr, char *));
	if (format[i] == 'p')
		ft_printptr(va_arg(ptr, void *));
	if (format[i] == 'd')
		ft_putnbr(va_arg(ptr, int));
	if (format[i] == 'i')
		ft_putnbr(va_arg(ptr, int));
	if (format[i] == 'u')
		ft_putunsignednbr(va_arg(ptr, unsigned int));
	if (format[i] == 'x')
		ft_printhexa(va_arg(ptr, unsigned int), format[i]);
	if (format[i] == 'X')
		ft_printhexa(va_arg(ptr, unsigned int), format[i]);
	if (format[i] == '%')
		write(1, "%", 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_printptr(void *ptr)
{
	//uintptr_t	address;

	//address = (uintptr_t)ptr;
	write(1, "0x", 3);
	ft_printhexa((uintptr_t)ptr, 'x');
}

void	ft_putnbr(int i)
{
	if (i == INT_MIN)
		write(1, "-2147483648", 12);
	else
	{
		if (i < 0)
		{
			write(1, "-", 1);
			i *= -1;
		}
		if (i >= 10)
			ft_putnbr(i / 10);
		ft_putchar((i % 10) + '0');
	}
}

void	ft_putunsignednbr(unsigned int i)
{
		if (i >= 10)
			ft_putnbr(i / 10);
		ft_putchar((i % 10) + '0');
}

void	ft_printhexa(unsigned int x, char a)
{
	char			c;
	char	base_up_hexa [] = "0123456789ABCDEF";
	char	base_low_hexa [] = "0123456789abcdef";

	if (x >= 16)
	{
		ft_printhexa(x / 16, a);
	}
	if (a == 'x')
		c = base_low_hexa[x % 16];
	else if (a == 'X')
		c = base_up_hexa[x % 16];
	write(1, &c, 1);
}
