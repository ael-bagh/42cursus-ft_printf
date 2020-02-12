/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:43:27 by ael-bagh          #+#    #+#             */
/*   Updated: 2019/12/23 16:43:29 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int				len_int(int x)
{
	int i;

	i = 1;
	while ((x = x / 10))
		i++;
	return (i);
}

void					ft_putnbr(unsigned int nb)
{
	if (nb / 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

static	void			putchi_minus(int d, int prec)
{
	int i;

	i = 0;
	if (d < 0)
		ft_putchar('-');
	while (i < g_precision)
	{
		ft_putchar('0');
		i++;
	}
	i = 0;
	if (!(!d && g_point && !prec))
		ft_putnbr(val_abs(d));
	while (i < g_min_width)
	{
		ft_putchar(' ');
		i++;
	}
}

static	void			putchi(int d, int prec)
{
	int i;

	i = 0;
	while (i < g_min_width)
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	if (d < 0)
		ft_putchar('-');
	while (i < g_precision)
	{
		ft_putchar('0');
		i++;
	}
	if (!(!d && g_point && !prec))
		ft_putnbr(val_abs(d));
}

void					treating_di(int d)
{
	int len;
	int prec;

	prec = g_precision;
	len = len_int(d);
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
	g_min_width -= (d < 0);
	if ((g_zero && !g_point) || (g_point && g_zero && prec < 0))
	{
		g_precision = g_min_width;
		g_min_width = 0;
	}
	if (g_minus)
		putchi_minus(d, prec);
	else
		putchi(d, prec);
}
