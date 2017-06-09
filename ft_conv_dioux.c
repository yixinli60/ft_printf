/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_dioux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:27:08 by yli               #+#    #+#             */
/*   Updated: 2017/05/04 13:55:00 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft/libft.h"
#include "include/ft_printf.h"

int			ft_conv_dstr(va_list ap, t_str_fmt *fmt_struc)
{
	intmax_t	i;
	intmax_t	nbr;
	char		*string;

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
	if (i < 0)
		fmt_struc->neg_nbr = 1;
	nbr = ft_absval(i);
	string = ft_add_pad(ft_itoa(nbr), fmt_struc);
	write(1, string, ft_strlen(string));
	return (ft_strlen(string));
}

int			ft_conv_ustr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string;

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
	string = ft_add_pad(ft_itoa(i), fmt_struc);
	write(1, string, ft_strlen(string));
	return (ft_strlen(string));
}

int			ft_conv_ostr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string_fin;
	char		str[100];
	char		*string_0;

	i = ft_lenmod(ap, fmt_struc);
	ft_itoa_base(i, str, 8);
	if (fmt_struc->flag.hash && (str[0] != '0'))
		string_0 = ft_strjoin("0", str);
	else
		string_0 = str;
	if (fmt_struc->cap == 1)
		ft_strtoupper(string_0);
	string_fin = ft_add_pad(string_0, fmt_struc);
	write(1, string_fin, ft_strlen(string_fin));
	return (ft_strlen(string_fin));
}

int			ft_conv_xstr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string_fin;
	char		str[100];

	i = ft_lenmod(ap, fmt_struc);
	ft_itoa_base(i, str, 16);
	string_fin = ft_handle_hex(str, fmt_struc);
	if (fmt_struc->cap == 1)
		ft_strtoupper(string_fin);
	write(1, string_fin, ft_strlen(string_fin));
	return (ft_strlen(string_fin));
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
