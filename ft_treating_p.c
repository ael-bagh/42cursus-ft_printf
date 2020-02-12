/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treating_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:18:38 by ael-bagh          #+#    #+#             */
/*   Updated: 2019/12/30 22:22:07 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void			putchip_minus(unsigned long long d, int prec)
{
	int i;

	i = 0;
	while (i < g_precision)
	{
		ft_putchar('0');
		i++;
	}
	i = 0;
	ft_putchar('0');
	ft_putchar('x');
	if (!(!d && g_point && !prec))
		ft_puthex(d, "0123456789abcdef");
	while (i < g_min_width)
	{
		ft_putchar(' ');
		i++;
	}
}

static	void			putchip(unsigned long long d, int prec)
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
	ft_putchar('0');
	ft_putchar('x');
	if (!(!d && g_point && !prec))
		ft_puthex(d, "0123456789abcdef");
}

void					treating_p(unsigned long long d)
{
	int len;
	int prec;

	prec = g_precision;
	len = hex_len(d, "0123456789abcdef") + 2;
	if (g_precision >= len)
		g_precision = g_precision - len;
	else
		g_precision = 0;
	if (g_point && !d && prec == 0)
		len = 2;
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
		putchip_minus(d, prec);
	else
		putchip(d, prec);
}
