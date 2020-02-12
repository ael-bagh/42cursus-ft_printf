/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treating_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:18:26 by ael-bagh          #+#    #+#             */
/*   Updated: 2019/12/30 22:18:28 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void			putchu_minus(unsigned int d, int prec)
{
	int i;

	i = 0;
	while (i < g_precision)
	{
		ft_putchar('0');
		i++;
	}
	i = 0;
	if (!(!d && g_point && !prec))
		ft_putnbr(d);
	while (i < g_min_width)
	{
		ft_putchar(' ');
		i++;
	}
}

static	void			putchu(unsigned int d, int prec)
{
	int i;

	i = 0;
	while (i < g_min_width)
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < g_precision)
	{
		ft_putchar('0');
		i++;
	}
	if (!(!d && g_point && !prec))
		ft_putnbr(d);
}

static	int				len_uint(unsigned int x)
{
	int i;

	i = 1;
	while ((x = x / 10))
		i++;
	return (i);
}

void					treating_u(unsigned int d)
{
	int len;
	int prec;

	prec = g_precision;
	len = len_uint(d);
	if (g_precision >= len)
		g_precision = g_precision - len;
	else
		g_precision = 0;
	if (g_point && !d && prec == 0)
		len = 0;
	if (g_precision >= 0)
		g_min_width = g_min_width - (g_precision + len);
	else
		g_min_width = g_min_width - len;
	if ((g_zero && !g_point) || (g_point && g_zero && prec < 0))
	{
		g_precision = g_min_width;
		g_min_width = 0;
	}
	if (g_minus)
		putchu_minus(d, prec);
	else
		putchu(d, prec);
}
