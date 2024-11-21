/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:53:33 by vsoulas           #+#    #+#             */
/*   Updated: 2024/11/21 15:59:05 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	main(void)
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	int				i;
	unsigned int	u;
	int				x;
	int				X;

	c = 'a';
	s = "Codam";
	p = &c;
	d = 666;
	i = INT_MIN;
	u = 4294967295;
	x = 568913;
	X = 568913;
	
	printf("original printf:\n");
	printf("char c = %c\n", c);
	printf("string s = %s\n", s);
	printf("pointer p = %p\n", p);
	printf("int d = %d\n", d);
	printf("int i = %i\n", i);
	printf("unsigned decimal u = %u\n", u);
	printf("hex lower x = %x\n", x);
	printf("hexa upper X = %X\n", X);
	printf("%%\n");
	
	ft_printf("my ft_printf:\n");
	ft_printf("char c = %c\n", c);
	ft_printf("string s = %s\n", s);
	ft_printf("pointer p = %p\n", p);
	ft_printf("int d = %d\n", d);
	ft_printf("int i = %i\n", i);
	ft_printf("unsigned decimal u = %u\n", u);
	ft_printf("hex lower x = %x\n", x);
	ft_printf("hexa upper X = %X\n", X);
	ft_printf("%%\n");
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;

	i = 0;
	va_start(ptr, format);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			ft_check(format, i + 1);
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(ptr);
}

void	ft_check(const char *format, int i)
{
	if (i == 'c')
	{
		va_arg(ptr, char);
	}
	if (i == 's')
		va_arg(ptr, char *);
	if (i == 'p')
		va_arg(ptr, void *);
	if (i == 'd')
		va_arg(ptr, int);
	if (i == 'i')
	
}