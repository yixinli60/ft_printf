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

char	*ft_handle_str(char *str_w_0pad, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*str_w_spad;
	int		width;

	width = fmt_struc->wid;
	if (width > (int)ft_strlen(str_w_0pad))
	{
		if (!(pad = malloc(sizeof(char) * (width - ft_strlen(str_w_0pad) + 1))))
			return (0);
		ft_memset(pad, ' ', (width - ft_strlen(str_w_0pad)));
		pad[(width - ft_strlen(str_w_0pad))] = '\0';
		str_w_spad = ft_mflag(str_w_0pad, pad, fmt_struc);
		free(pad);
		return (str_w_spad);
	}
	else
		return (str_w_0pad);
}

char	*ft_handle_hex(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*str_w_0pad;
	int		str_len;
	char	*hash_pad;

	str_len = ft_strlen(str);
	if (fmt_struc->pre == 0 && *str == '0')
		return (pre_str_zero(fmt_struc));
	if (fmt_struc->pre >= str_len && fmt_struc->pre >= fmt_struc->wid)
	{
		pad = ft_set_pad(fmt_struc, str_len);
		if (fmt_struc->flag.hash)
		{
			if (!(hash_pad = malloc(sizeof(char) * (ft_strlen(pad) + 3))))
				return (0);
			hash_pad = ft_strjoin("0x", pad);
			str_w_0pad = ft_add_signs(ft_strcat(hash_pad, str), fmt_struc);
		}
		else
			str_w_0pad = ft_add_signs(ft_strcat(pad, str), fmt_struc);
		return (str_w_0pad);
	}
	else if (fmt_struc->wid >= str_len && str_len >= fmt_struc->pre)
		return (ft_wid_len_pre(fmt_struc, str_len, str));
	else if (fmt_struc->wid >= fmt_struc->pre && fmt_struc->pre >= str_len)
	{
		pad = ft_set_pad(fmt_struc, str_len);
		if (fmt_struc->flag.hash)
		{
			if (!(hash_pad = malloc(sizeof(char) * (ft_strlen(pad) + 3))))
				return (0);
			hash_pad = ft_strjoin("0x", pad);
			str_w_0pad = ft_add_signs(ft_strcat(hash_pad, str), fmt_struc);
		}
		else
			str_w_0pad = ft_add_signs(ft_strcat(pad, str), fmt_struc);
		return (ft_add_space(str_w_0pad, fmt_struc));
	}
	else
	{
		if (fmt_struc->flag.hash)
		{
			if (!(hash_pad = malloc(sizeof(char) * (ft_strlen(str) + 3))))
				return (0);
			hash_pad = ft_strjoin("0x", str);
			return (ft_add_signs(hash_pad, fmt_struc));
		}
	}
	return (ft_add_signs(str, fmt_struc));
}
