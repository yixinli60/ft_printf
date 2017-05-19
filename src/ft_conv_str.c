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

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_conv_dstr(va_list ap, t_str_fmt *fmt_struc)
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
}

void	ft_conv_ustr(va_list ap, t_str_fmt *fmt_struc)
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
}
void	ft_conv_cstr(va_list ap, t_str_fmt *fmt_struc)
{
	int		i;
	char	str[2];
	char	*string;

	i = va_arg(ap, int);
	if (fmt_struc->length_mod == LENMOD_L)
		i = (long)i;
	str[0] = i;
	str[1] = '\0';
	string = ft_add_pad(str, fmt_struc);
	write(1, string, ft_strlen(string));
}

void	ft_conv_sstr(va_list ap, t_str_fmt *fmt_struc)
{
	char	*i;
	char	*string;
	char	*final_str;

	i = va_arg(ap, char *);
	if (i == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	//if ((int)ft_strlen(i) < fmt_struc->wid)
	//{
	if (!(string = malloc(sizeof(char) * (ft_strlen(i) + 1))))
		return ;
	string = i;
	//}
	//else
	//{
	//	if (!(string = malloc(sizeof(char) * (fmt_struc->wid))))
	//		return ;
	//	printf("string is |%s|\n,", string);
	//}
	final_str = ft_add_pad(string, fmt_struc);
	write(1, final_str, ft_strlen(final_str));
}
	
void	ft_conv_ostr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string_fin;
	char		*str;
	char		*string_0;

	if (!(str = malloc(sizeof(char) * 20)))
		return ;
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
		i = (int)i;
	ft_itoa_base(i, str, 8);
	if (fmt_struc->flag.hash)
		string_0 = ft_strjoin("0", str);
	else
		string_0 = str;
	if (fmt_struc->cap == 1)
		ft_to_upper(string_0);
	string_fin = ft_add_pad(string_0, fmt_struc);
	write(1, string_fin, ft_strlen(string_fin));
}

void	ft_conv_xstr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string_fin;
	char		*str;
	char		*string_0x;

	if (!(str = malloc(sizeof(char) * 20)))
		return ;
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
		i = (int)i;
	ft_itoa_base(i, str, 16);
	if (fmt_struc->flag.hash)
		string_0x = ft_strjoin("0x", str);
	else
		string_0x = str;
	if (fmt_struc->cap == 1)
		ft_to_upper(string_0x);
	string_fin = ft_add_pad(string_0x, fmt_struc);
	write(1, string_fin, ft_strlen(string_fin));
}

void	ft_conv_p(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*str;
	char		*string = NULL;
	char *string_fin;

	if (!(str = malloc(sizeof(char) * 20)))
		return ;
	i = va_arg(ap, uintmax_t);
	ft_itoa_base(i, str, 16);
	string = ft_strjoin("0x", str);
	free(str);
	string_fin = ft_add_pad(string, fmt_struc);
	write(1, string_fin, ft_strlen(string_fin));
}

void	ft_to_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else
			i++;
	}
	i++;
}
