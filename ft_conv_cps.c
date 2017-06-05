/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:26:01 by yli               #+#    #+#             */
/*   Updated: 2017/05/31 16:32:59 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft/libft.h"
#include "include/ft_printf.h"

int	ft_conv_cstr(va_list ap, t_str_fmt *fmt_struc)
{
	int		i;
	char	str[2];
	char	*string;
	int		width;

	width = fmt_struc->wid;
	i = va_arg(ap, int);
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

int	ft_conv_p(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*str;
	char		*string;
	char		*string_fin;

	string = NULL;
	if (!(str = malloc(sizeof(char) * 20)))
		return (0);
	i = va_arg(ap, uintmax_t);
	if (i == 0)
		str = "0";
	else
		ft_itoa_base(i, str, 16);
	string = ft_strjoin("0x", str);
	//free(str);
	string_fin = ft_add_pad(string, fmt_struc);
	write(1, string_fin, ft_strlen(string_fin));
	return (ft_strlen(string_fin));
}

int	ft_conv_sstr(va_list ap, t_str_fmt *fmt_struc)
{
	char	*i;
	char	*string;
	char	*final_str;
	int len = 0;

	if (fmt_struc->length_mod == LENMOD_L)
		return (len = ft_conv_wsstr(ap));
	i = va_arg(ap, char*);

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
	//free(string);
	write(1, final_str, ft_strlen(final_str));
	return (ft_strlen(final_str));
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

int	ft_conv_wsstr(va_list ap)
{
	wchar_t *i;
	wchar_t *N = NULL;

	i = va_arg(ap, wchar_t*);
	if (i == N)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, i, ft_wstrlen(i)* 4);
	return (0);
}

int	ft_conv_wcstr(va_list ap)
{
	wchar_t i;

	i = va_arg(ap, wchar_t);
	//if (i == '0')
	//{
	//	write(1, "(null)", 6);
	//	return (6);
	//}
	//else
	write(1, &i, 4);
	return (1);
}
