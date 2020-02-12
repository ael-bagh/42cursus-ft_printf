/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:22:26 by ael-bagh          #+#    #+#             */
/*   Updated: 2019/12/23 15:22:34 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				g_ret;
int				g_min_width;
int				g_precision;
int				g_zero;
int				g_minus;
int				g_point;
va_list			g_ap;

int				ft_printf(char *str, ...);
int				ft_isdigit(char c);
void			ft_putchar(char c);
char			*skip_char(char *str, char c);
char			*skip_digit(char *str);
void			ft_putnbr(unsigned int nb);
unsigned int	val_abs(int x);
void			ft_puthex(unsigned long long nb, const char *x);
int				hex_len(unsigned long long nb, const char *x);
void			treating_di(int d);
void			treating_x(unsigned int d, char str);
void			treating_p(unsigned long long d);
void			treating_u(unsigned int d);
void			treating_s(char *s);
void			treating_c(char c);

#endif
