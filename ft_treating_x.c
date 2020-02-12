/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treating_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 04:08:55 by ael-bagh          #+#    #+#             */
/*   Updated: 2019/12/29 04:08:58 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_puthex(unsigned long long nb, const char *x)
{
	if (nb > 15)
		ft_puthex(nb / 16, x);
	ft_putchar(x[nb % 16]);
}

int				hex_len(unsigned long long nb, const char *x)
{
	static int i;

	i = 0;
	if (nb > 15)
		hex_len(nb / 16, x);
	i++;
	return (i);
}

static	void	putchix_minus(unsigned int d, int prec, char str)
{
	int i;

	i = 0;
	while (i < g_precision)
	{
		ft_putchar('0');
		i++;
	}
	i = 0;
	if (!(!d && g_point && !prec) && str == 'x')
		ft_puthex(d, "0123456789abcdef");
	else if (!(!d && g_point && !prec) && str == 'X')
		ft_puthex(d, "0123456789ABCDEF");
	while (i < g_min_width)
	{
		ft_putchar(' ');
		i++;
	}
}

static	void	putchix(unsigned int d, int prec, char str)
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
	if (!(!d && g_point && !prec) && str == 'x')
		ft_puthex(d, "0123456789abcdef");
	else if (!(!d && g_point && !prec) && str == 'X')
		ft_puthex(d, "0123456789ABCDEF");
}

void			treating_x(unsigned int d, char str)
{
	int len;
	int prec;

	prec = g_precision;
	len = hex_len(d, "0123456789abcdef");
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
		putchix_minus(d, prec, str);
	else
		putchix(d, prec, str);
}
