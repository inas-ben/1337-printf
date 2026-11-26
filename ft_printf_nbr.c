/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibendris <ibendris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:13:08 by ibendris          #+#    #+#             */
/*   Updated: 2026/11/13 13:49:18 by ibendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnum_length(int nbr, int *length)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_length('-', length);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnum_length(nbr / 10, length);
	ft_putchar_length(nbr % 10 + '0', length);
}

void	ft_putunsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		ft_putunsigned_int(u / 10, length);
	ft_putchar_length(u % 10 + '0', length);
}

void	ft_puthexa(unsigned long int x, int *length, char x_or_X)
{
	char	*base;

	if (x_or_X == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (x >= 16)
		ft_puthexa(x / 16, length, x_or_X);
	ft_putchar_length(base[x % 16], length);
}

void	ft_putptr_length(size_t ptr, int *length)
{
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		(*length) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*length) += 2;
	ft_puthexa(ptr, length, 'x');
}
