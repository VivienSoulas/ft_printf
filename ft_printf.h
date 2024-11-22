/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:53:36 by vsoulas           #+#    #+#             */
/*   Updated: 2024/11/22 13:53:16 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int		ft_printf(const char *, ...);
void	ft_check_format(const char *format, int i, va_list ptr);
void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_printptr(void *ptr);
void	ft_putnbr(int i);
void	ft_putunsignednbr(unsigned int i);
void	ft_printhexa(unsigned int x, char a);

#endif