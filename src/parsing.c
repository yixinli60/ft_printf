/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:19:51 by yli               #+#    #+#             */
/*   Updated: 2017/04/25 14:41:37 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

int		parse_format(char *format, t_str_fmt *fmt_struc)
{
	if (*format == '#')
		return (fmt_struc->flag.hash = 1);
	else if (*format == '-')
		return (fmt_struc->flag.minus = 1);
	else if (*format == '+')
		return (fmt_struc->flag.plus = 1);
	else if (*format == ' ')
		return (fmt_struc->flag.space = 1);
	else if (*format == '0')
		return (fmt_struc->flag.zero = 1);
	return (0);
}

int		parse_width(char **format, t_str_fmt *fmt_struc)
{
	intmax_t	width;

	width = 0;
	while ((**format >= '0' && **format <= '9'))
	{
		width *= 10;
		width += **format - '0';
		(*format)++;
	}
	return (fmt_struc->wid = width);
}

int		parse_precision(char **format, t_str_fmt *fmt_struc)
{
	intmax_t	precision;

	precision = -1;
	if (**format == '.')
	{
		precision = 0;
		(*format)++;
		while ((**format >= '0' && **format <= '9'))
		{
			precision *= 10;
			precision += **format - '0';
			(*format)++;
		}
	}
	return (fmt_struc->pre = precision);
}

int		parse_lm(char **format, t_str_fmt *fmt_struc)
{
	if (**format == 'h')
	{
		(*format)++;
		if (**format == 'h')
			fmt_struc->length_mod = LENMOD_HH;
		else
			return (fmt_struc->length_mod = LENMOD_H);
	}
	else if (**format == 'l')
	{
		(*format)++;
		if (**format == 'l')
			fmt_struc->length_mod = LENMOD_LL;
		else
			return (fmt_struc->length_mod = LENMOD_L);
	}
	else if (**format == 'j')
		fmt_struc->length_mod = LENMOD_J;
	else if (**format == 'z')
		fmt_struc->length_mod = LENMOD_Z;
	else
		return (0);
	(*format)++;
	return (0);
}

void	parse_conv(va_list ap, char **format, t_str_fmt *fmt_struc)
{
	uintmax_t	u;
	char		*ptr;

	if (**format == 'd' || **format == 'i')
		ft_conv_dstr(ap, fmt_struc);
	else if (**format == 'c' || **format == 'C')
		ft_conv_cstr(ap, fmt_struc);
	else if (**format == 'o' || **format == 'O' || **format == 'u'
		|| **format == 'U' || **format == 'x' || **format == 'X')
		u = va_arg(ap, uintmax_t);
	else if (**format == 's' || **format == 'S')
	{
		ptr = va_arg(ap, char *);
		while (*ptr)
		{
			write(1, ptr, 1);
			ptr++;
		}
	}
	else
		return ;
	fmt_struc->conv = **format;
	(*format)++;
}
