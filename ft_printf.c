/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibendris <ibendris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 20:44:34 by ibendris          #+#    #+#             */
/*   Updated: 2026/11/13 19:45:42 by ibendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(char c, va_list *args, int *length, size_t *i)
{
	if (c == 'c')
		ft_putchar_length(va_arg(*args, int), length);
	else if (c == 's')
		ft_putstr_length(va_arg(*args, char *), length);
	else if (c == 'p')
		ft_putptr_length((size_t)va_arg(*args, void *), length);
	else if (c == 'd' || c == 'i')
		ft_putnum_length(va_arg(*args, int), length);
	else if (c == 'u')
		ft_putunsigned_int(va_arg(*args, unsigned int), length);
	else if (c == 'x')
		ft_puthexa(va_arg(*args, unsigned int), length, 'x');
	else if (c == 'X')
		ft_puthexa(va_arg(*args, unsigned int), length, 'X');
	else if (c == '%')
		ft_putchar_length('%', length);
	else if (c != '\0')
	{
		ft_putchar_length('%', length);
		ft_putchar_length(c, length);
	}
	else
		(*i)--;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			check_format(s[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putchar_length(s[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
