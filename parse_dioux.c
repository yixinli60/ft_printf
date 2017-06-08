/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:39:23 by yli               #+#    #+#             */
/*   Updated: 2017/05/31 15:39:52 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft/libft.h"
#include "include/ft_printf.h"

int	parse_dioux(va_list ap, char **fmt, t_str_fmt *fmt_struc)
{
	int	len;

	len = 0;
	if (**fmt == 'D' || **fmt == 'O' || **fmt == 'U')
	{
		fmt_struc->length_mod = LENMOD_L;
		fmt_struc->cap = 1;
	}
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'D')
		return (len = ft_conv_dstr(ap, fmt_struc));
	else if (**fmt == 'o' || **fmt == 'O')
		return (len = ft_conv_ostr(ap, fmt_struc));
	else if (**fmt == 'u' || **fmt == 'U')
		return (len = ft_conv_ustr(ap, fmt_struc));
	else if (**fmt == 'x' || **fmt == 'X')
	{
		fmt_struc->hex = 1;
		if (**fmt == 'X')
			fmt_struc->cap = 1;
		return (len = ft_conv_xstr(ap, fmt_struc));
	}
	return (0);
}

int	parse_other(char **fmt, t_str_fmt *fmt_struc)
{
	int		width;
	char	*pad;
	char	*string;

	width = fmt_struc->wid;
	if (!(**fmt >= 65 && **fmt <= 90) || !(**fmt >= 97 && **fmt <= 122))
	{
		if (!(pad = malloc(sizeof(char) * (width))))
			return (0);
		if (width)
			ft_memset(pad, ' ', width);
		pad[width] = '\0';
		string = ft_mflag(*fmt, pad, fmt_struc);
		write(1, string, ft_strlen(string));
		if (width)
			return (width);
		return (1);
	}
	else
	{
		write(1, *fmt, 1);
		(*fmt)++;
		return (1);
	}
}
