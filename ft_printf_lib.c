/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:48:00 by ael-bagh          #+#    #+#             */
/*   Updated: 2019/12/29 03:48:04 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void			ft_putchar(char c)
{
	g_ret += write(1, &c, 1);
}

char			*skip_char(char *str, char c)
{
	while (*str == c)
		str++;
	return (str);
}

char			*skip_digit(char *str)
{
	while (ft_isdigit(*str))
		str++;
	return (str);
}

unsigned int	val_abs(int x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}
