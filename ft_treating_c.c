/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treating_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:41:47 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/01/02 16:42:49 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treating_c(char c)
{
	if (g_min_width > 0)
	{
		if (g_minus)
		{
			g_ret += write(1, &c, 1);
			while (--g_min_width)
				g_ret += write(1, " ", 1);
		}
		else if (!g_zero)
		{
			while (--g_min_width)
				g_ret += write(1, " ", 1);
			g_ret += write(1, &c, 1);
		}
		else
		{
			while (--g_min_width)
				g_ret += write(1, "0", 1);
			g_ret += write(1, &c, 1);
		}
	}
	else
		g_ret += write(1, &c, 1);
}
