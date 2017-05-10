/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:01:01 by yli               #+#    #+#             */
/*   Updated: 2017/04/25 15:17:29 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_parse_fmt(va_list ap, char **format)
{
	t_str_fmt	fmt_struc;

	if (**format == '%')
	{
		(*format)++;
		if (**format == '%')
		{
			write(1, "%", 1);
			(*format)++;
		}
		ft_memset(&fmt_struc, 0, sizeof(fmt_struc));
		while (parse_format(*format, &fmt_struc))
			(*format)++;
		parse_width(format, &fmt_struc);
		parse_precision(format, &fmt_struc);
		parse_lm(format, &fmt_struc);
		parse_conv(ap, format, &fmt_struc);
	}
	else
	{
		ft_putchar(**format);
		(*format)++;
	}
}

int		ft_printf(char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	while (*format != '\0')
		ft_parse_fmt(ap, &format);
	va_end(ap);
	return (0);
}
