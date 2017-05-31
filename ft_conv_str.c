/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:27:08 by yli               #+#    #+#             */
/*   Updated: 2017/05/04 13:55:00 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft/libft.h"
#include "include/ft_printf.h"

int	ft_conv_dstr(va_list ap, t_str_fmt *fmt_struc)
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

int	ft_conv_ustr(va_list ap, t_str_fmt *fmt_struc)
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

int	ft_conv_cstr(va_list ap, t_str_fmt *fmt_struc)
{
	int		i;
	char	str[2];
	char	*string;
	int		width;

	width = fmt_struc->wid;
	i = va_arg(ap, int);
	if (fmt_struc->length_mod == LENMOD_L)
		i = (long)i;
	if (i == 0)
	{
		if (fmt_struc->wid > 0)
		{
			while (fmt_struc->wid != 1)
			{
				write(1, " ", 1);
				fmt_struc->wid--;
			}
			return (width);
		}
		else
			write(1, "", 1);
		return (1);
	}
	str[0] = i;
	str[1] = '\0';
	string = ft_add_pad(str, fmt_struc);
	write(1, string, ft_strlen(string));
	return (ft_strlen(string));
}

int	ft_conv_sstr(va_list ap, t_str_fmt *fmt_struc)
{
	char	*i;
	char	*string;
	char	*final_str;

	i = va_arg(ap, char *);
	if (i == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if ((int)ft_strlen(i) > fmt_struc->pre && fmt_struc->pre > 0)
	{
		if (!(string = malloc(sizeof(char) * (fmt_struc->pre))))
			return (0);
		ft_strncpy(string, i, fmt_struc->pre);
	}
	else
	{
		if (!(string = malloc(sizeof(char) * (ft_strlen(i) + 1))))
			return (0);
		string = i;
	}
	final_str = ft_handle_str(string, fmt_struc);
	write(1, final_str, ft_strlen(final_str));
	return (ft_strlen(final_str));
}

int	ft_conv_ostr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string_fin;
	char		*str;
	char		*string_0;

	if (!(str = malloc(sizeof(char) * 20)))
		return (0);
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
	ft_itoa_base(i, str, 8);
	if (fmt_struc->flag.hash && str != 0)
		string_0 = ft_strjoin("0", str);
	else
		string_0 = str;
	if (fmt_struc->cap == 1)
		ft_strtoupper(string_0);
	string_fin = ft_add_pad(string_0, fmt_struc);
	write(1, string_fin, ft_strlen(string_fin));
	return (ft_strlen(string_fin));
}

int	ft_conv_xstr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string_fin;
	char		*str;

	if (!(str = malloc(sizeof(char) * 20)))
		return (0);
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
	ft_itoa_base(i, str, 16);
	string_fin = ft_handle_hex(str, fmt_struc);
	if (fmt_struc->cap == 1)
		ft_strtoupper(string_fin);
	write(1, string_fin, ft_strlen(string_fin));
	//free(str);
	return (ft_strlen(string_fin));
}

int	ft_conv_p(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*str;
	char		*string = NULL;
	char *string_fin;

	if (!(str = malloc(sizeof(char) * 20)))
		return (0);
	i = va_arg(ap, uintmax_t);
	if (i == 0)
		str = "0";
	else
	{
		ft_itoa_base(i, str, 16);
		free(str);
	}
	string = ft_strjoin("0x", str);
	string_fin = ft_add_pad(string, fmt_struc);
	write(1, string_fin, ft_strlen(string_fin));
	return (ft_strlen(string_fin));
}

int	ft_conv_pct(t_str_fmt *fmt_struc)
{
	char	str[2];
	char	*string;

	str[0] = '%';
	str[1] = '\0';
	string = ft_handle_pct(str, fmt_struc);
	write(1, string, ft_strlen(string));
	return (ft_strlen(string));
}
