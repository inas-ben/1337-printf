/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibendris <ibendris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 20:45:55 by ibendris          #+#    #+#             */
/*   Updated: 2026/11/13 10:50:22 by ibendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar_length(char c, int *length);
void	ft_putstr_length(char *s, int *length);
void	ft_putnum_length(int nbr, int *length);
void	ft_putunsigned_int(unsigned int u, int *length);
void	ft_puthexa(unsigned long int x, int *length, char x_or_X);
void	ft_putptr_length(size_t ptr, int *length);
int		ft_printf(const char *s, ...);

#endif