/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:53:33 by vsoulas           #+#    #+#             */
/*   Updated: 2024/11/28 12:59:28 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	main(void)
// {
// 	char			c;
// 	// char			*s;
// 	void			*p;
// 	int				d;
// 	int				i;
// 	unsigned int	u;
// 	int				x;
// 	int				X;
// 	int				result;
// 	int				results;

// 	c = 'a';
// 	// s = NULL;
// 	p = NULL;
// 	d = 666;
// 	i = INT_MIN;
// 	u = -1;
// 	x = 568913;
// 	X = 568913;
// 	result = 0;
// 	results = 0;

// 	printf("\n");
// 	printf("original printf:\n");
// 	printf("char c = %c\n", c);
// 	// result = printf(" NULL %s NULL \n", NULL);
// 	// printf("%i\n", result);
// 	result = printf("pointer p = %p\n", p);
// printf("%i\n", result);
// 	printf("int d = %d\n", d);
// 	printf("int i = %i\n", i);
// 	printf("unsigned decimal u = %u\n", u);
// 	printf("hex lower x = %x\n", x);
// 	printf("hexa upper X = %X\n", X);
// 	printf("%%\n");
// 	printf("\n\n");

// 	ft_printf("my ft_printf:\n");
// 	ft_printf("char c = %c\n", c);
// 	// results = printf(" NULL %s NULL \n", NULL);
// 	// printf("%i\n", results);
// 	results = ft_printf("pointer p = %p\n", 0);
//printf("%i\n", results);
// 	ft_printf("int d = %d\n", d);
// 	ft_printf("int i = %i\n", i);
// 	ft_printf("unsigned decimal u = %u\n", u);
// 	ft_printf("hex lower x = %x\n", x);
// 	ft_printf("hexa upper X = %X\n", X);
// 	ft_printf("%%\n");
// 	printf("\n");
// 	return (0);
// }

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;
	int		count;

	if (format == NULL)
		return (0);
	i = 0;
	count = 0;
	va_start(ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += ft_check_format(format, i + 1, ptr);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}

int	ft_check_format(const char *format, int i, va_list ptr)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	if (format[i] == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	if (format[i] == 'p')
		return (ft_printptr(va_arg(ptr, void *), &count));
	if (format[i] == 'd')
		return (ft_putnbr(va_arg(ptr, int), &count));
	if (format[i] == 'i')
		return (ft_putnbr(va_arg(ptr, int), &count));
	if (format[i] == 'u')
		return (ft_putunsignednbr(va_arg(ptr, unsigned int), &count));
	if (format[i] == 'x')
		return (ft_printhexa(va_arg(ptr, unsigned int), format[i], &count));
	if (format[i] == 'X')
		return (ft_printhexa(va_arg(ptr, unsigned int), format[i], &count));
	if (format[i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_printptr(void *ptr, int *count)
{
	int	result;

	result = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	result = ft_printhexa((uintptr_t)ptr, 'x', count);
	return (result + 2);
}
