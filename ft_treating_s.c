/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treating_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:03:42 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/01/05 16:03:47 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t		ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

static	void		putchis_minus(char *s)
{
	int i;

	i = 0;
	while (i < g_precision && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	i = 0;
	while (i < g_min_width)
	{
		ft_putchar(' ');
		i++;
	}
}

static	void		putchis(char *s)
{
	int i;

	i = 0;
	while (i < g_min_width)
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < g_precision && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void				treating_s(char *s)
{
	int len;
	int prec;

	len = 0;
	prec = g_precision;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (g_point)
	{
		if (g_precision >= len)
			g_precision = len;
		else if (g_precision < 0)
			g_precision = len;
		else
			len = (g_precision < 0) ? -g_precision : g_precision;
		g_precision = (g_precision < 0) ? -g_precision : g_precision;
	}
	else
		g_precision = len;
	g_min_width -= (len);
	if (g_minus)
		putchis_minus(s);
	else
		putchis(s);
}
