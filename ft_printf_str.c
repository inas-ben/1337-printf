/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibendris <ibendris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:12:19 by ibendris          #+#    #+#             */
/*   Updated: 2026/11/13 16:03:19 by ibendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_length(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
}

void	ft_putstr_length(char *s, int *length)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_length(s[i], length);
		i++;
	}
}
