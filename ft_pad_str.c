/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:02:26 by yli               #+#    #+#             */
/*   Updated: 2017/05/17 12:02:30 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pre_str_zero
** when both precision and string are "0"
** if plus flag is present, malloc pad of size width
** if not, return empty string of width size
*/

#include "src/libft/libft.h"
#include "include/ft_printf.h"

char		*pre_str_zero(t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*pad_w_spad;

	if (!(pad = malloc(sizeof(char) * (fmt_struc->wid) + 1)))
		return (0);
	if (fmt_struc->flag.plus)
	{
		ft_memset(pad, ' ', (fmt_struc->wid));
		pad[(fmt_struc->wid)] = '\0';
		pad_w_spad = ft_strcat(pad, "+");
		free(pad);
		return (pad_w_spad);
	}
	else
	{
		ft_memset(pad, ' ', (fmt_struc->wid));
		pad[(fmt_struc->wid)] = '\0';
		pad_w_spad = pad;
		free(pad);
		return (pad_w_spad);
	}
}

char		*ft_wid_len_pre(t_str_fmt *fmt_struc, int int_len, char *str)
{
	char	*str_w_0pad;
	char	*pad;
	char	*str_w_pad;
	char	*string_0x;

	if (fmt_struc->flag.plus || fmt_struc->flag.space || fmt_struc->neg_nbr)
		int_len = int_len + 1;
	if (!(pad = malloc(sizeof(char) * (fmt_struc->wid - int_len + 1))))
		return (0);
	if (fmt_struc->pre == -1 && fmt_struc->flag.zero && !fmt_struc->flag.minus)
	{
		ft_memset(pad, '0', (fmt_struc->wid - int_len));
		pad[(fmt_struc->wid - int_len)] = '\0';
		str_w_pad = ft_strcat(pad, str);
		//free(pad);
		return (ft_add_signs(str_w_pad, fmt_struc));
	}
	if (fmt_struc->flag.hash && fmt_struc->hex)
		string_0x = ft_strjoin("0x", str);
	else
		string_0x = str;
	str_w_0pad = ft_add_signs(string_0x, fmt_struc);
	if (fmt_struc->wid >= (int)ft_strlen(str_w_0pad))
	{
		ft_memset(pad, ' ', (fmt_struc->wid - ft_strlen(str_w_0pad)));
		pad[(fmt_struc->wid - int_len)] = '\0';
		str_w_pad = ft_mflag(str_w_0pad, pad, fmt_struc);
		free(pad);
		return (str_w_pad);
	}
	else
		return (str_w_0pad);
}

char		*ft_set_pad(t_str_fmt *fmt_struc, int len)
{
	char	*pad;

	if (!(pad = malloc(sizeof(char) * (fmt_struc->pre - len + 1))))
		return (0);
	ft_memset(pad, '0', (fmt_struc->pre - len));
	pad[(fmt_struc->pre - len)] = '\0';
	return (pad);
}

char		*ft_add_pad(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*str_w_0pad;
	int		str_len;

	str_len = ft_strlen(str);
	if (fmt_struc->pre == 0 && *str == '0' && !fmt_struc->flag.hash)
		return (pre_str_zero(fmt_struc));
	else if (fmt_struc->pre >= str_len && fmt_struc->pre >= fmt_struc->wid)
	{
		pad = ft_set_pad(fmt_struc, str_len);
		str_w_0pad = ft_add_signs(ft_strcat(pad, str), fmt_struc);
		return (str_w_0pad);
	}
	else if (fmt_struc->wid >= str_len && str_len >= fmt_struc->pre)
	{
		return (ft_wid_len_pre(fmt_struc, str_len, str));
	}
	else if (fmt_struc->wid >= fmt_struc->pre && fmt_struc->pre >= str_len)
	{
		pad = ft_set_pad(fmt_struc, str_len);
		str_w_0pad = ft_add_signs(ft_strcat(pad, str), fmt_struc);
		return (ft_add_space(str_w_0pad, fmt_struc));
	}
	return (ft_add_signs(str, fmt_struc));
}
