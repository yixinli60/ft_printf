/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:46:36 by yli               #+#    #+#             */
/*   Updated: 2017/05/23 15:13:00 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft/libft.h"
#include "include/ft_printf.h"

char		*ft_handle_str(char *str_w_0pad, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*str_w_spad;
	int		width;

	width = fmt_struc->wid;
	if (fmt_struc->pre == 0)
	{
		if (!(pad = malloc(sizeof(char) * (width + 1))))
			return (0);
		ft_memset(pad, ' ', (width));
		pad[(width + 1)] = '\0';
		return (pad);
	}
	if (width > (int)ft_strlen(str_w_0pad))
	{
		if (!(pad = malloc(sizeof(char) * (width - ft_strlen(str_w_0pad) + 1))))
			return (0);
		ft_memset(pad, ' ', (width - ft_strlen(str_w_0pad)));
		pad[(width - ft_strlen(str_w_0pad))] = '\0';
		str_w_spad = ft_mflag(str_w_0pad, pad, fmt_struc);
		return (str_w_spad);
	}
	return (str_w_0pad);
}

uintmax_t	ft_lenmod(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;

	i = va_arg(ap, uintmax_t);
	if (fmt_struc->length_mod == LENMOD_H)
		i = (unsigned short)i;
	else if (fmt_struc->length_mod == LENMOD_HH)
		i = (unsigned char)i;
	else if (fmt_struc->length_mod == LENMOD_L)
		i = (unsigned long)i;
	else if (fmt_struc->length_mod == LENMOD_LL)
		i = (unsigned long long)i;
	else if (fmt_struc->length_mod == LENMOD_J)
		i = (uintmax_t)i;
	else if (fmt_struc->length_mod == LENMOD_Z)
		i = (size_t)i;
	else
		i = (unsigned int)i;
	return (i);
}

intmax_t	ft_lendmod(va_list ap, t_str_fmt *fmt_struc)
{
	intmax_t	i;

	i = va_arg(ap, intmax_t);
	if (fmt_struc->length_mod == LENMOD_H)
		i = (short)i;
	else if (fmt_struc->length_mod == LENMOD_HH)
		i = (char)i;
	else if (fmt_struc->length_mod == LENMOD_L)
		i = (long)i;
	else if (fmt_struc->length_mod == LENMOD_LL)
		i = (intmax_t)i;
	else if (fmt_struc->length_mod == LENMOD_J)
		i = (intmax_t)i;
	else if (fmt_struc->length_mod == LENMOD_Z)
		i = (size_t)i;
	else
		i = (int)i;
	return (i);
}
