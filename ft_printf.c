/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:22:15 by ael-bagh          #+#    #+#             */
/*   Updated: 2019/12/23 15:22:18 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int				ft_atoi(char *str)
{
	int result;
	int signe;

	result = 0;
	signe = 1;
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		str++;
	if (*str == '-')
	{
		signe = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		if (result < 0 && signe < 0)
			return (0);
		if (result < 0 && signe > 0)
			return (-1);
		result = result * 10 + *str - '0';
		str++;
	}
	return (signe * result);
}

static	void			set_route(char str)
{
	if (str == 'd' || str == 'i')
		treating_di(va_arg(g_ap, int));
	if (str == 'c' || str == '%')
		(str == 'c') ? treating_c(va_arg(g_ap, int)) : treating_c('%');
	if (str == 's')
		treating_s(va_arg(g_ap, char*));
	if (str == 'p')
		treating_p(va_arg(g_ap, unsigned long long));
	if (str == 'u')
		treating_u(va_arg(g_ap, unsigned int));
	if (str == 'x' || str == 'X')
		treating_x(va_arg(g_ap, unsigned int), str);
}

static	void			flags_init(void)
{
	g_min_width = 0;
	g_precision = 0;
	g_zero = 0;
	g_minus = 0;
	g_point = 0;
}

static	char			*get_flags(char *str)
{
	flags_init();
	if (*str == '-' && (g_minus = 1))
		str = skip_char(str, '-');
	if (*str == '0' && (g_zero = 1))
		str = skip_char(str, '0');
	if (ft_isdigit(*str))
	{
		g_min_width = ft_atoi(str);
		str = skip_digit(str);
	}
	else if (*str == '*' && (str++))
		g_min_width = va_arg(g_ap, int);
	if (*str == '.' && (str++))
		g_point = 1;
	if (g_point && ft_isdigit(*str))
	{
		g_precision = ft_atoi(str);
		str = skip_digit(str);
	}
	else if (g_point && *str == '*' && (str++))
		g_precision = va_arg(g_ap, int);
	g_minus = (g_min_width < 0) ? 1 && (g_min_width *= -1) : g_minus;
	set_route(*str);
	return (str);
}

int						ft_printf(char *str, ...)
{
	int i;

	i = 0;
	g_ret = 0;
	va_start(g_ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str = get_flags(str);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(g_ap);
	return (g_ret);
}
