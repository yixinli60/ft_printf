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
		//free(pad);
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
	if (*str == '0')
	{
		if (fmt_struc->pre <= 0)
		{
			if (fmt_struc->pre < 0)
			{
				if (!(pad = malloc(sizeof(char) * 2)))
					return (0);
				pad[0] = '0';
				pad[1] = '\0';
				return (pad);
			}
			else if (fmt_struc->wid)
			{
				if (!(pad = malloc(sizeof(char) * (fmt_struc->wid + 1))))
					return (0);
				ft_memset(pad, ' ', fmt_struc->wid);
				pad[fmt_struc->wid + 1] = '\0';
				return (pad);
			}
			else
			{
				if (!(pad = malloc(sizeof(char) * 1)))
					return (0);
				pad[0] = '\0';
				return (pad);
			}
		}
		else
		{
			if (!(pad = malloc(sizeof(char) * (fmt_struc->pre + 1))))
				return (0);
			ft_memset(pad, '0', fmt_struc->pre);
			pad[fmt_struc->pre + 1] = '\0';
			return (ft_add_space(pad, fmt_struc));
		}
	}
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
		return (ft_add_pad(str, fmt_struc));
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

char	*ft_handle_pct(char *str, t_str_fmt *fmt_struc)
{
	char *space_pad;
	char *padded_str;

	if (fmt_struc->wid)
	{
		if (!(space_pad = malloc(sizeof(char) * (fmt_struc->wid))))
			return (0);
		ft_memset(space_pad, ' ', fmt_struc->wid - 1);
		padded_str = ft_mflag(str, space_pad, fmt_struc);
	}
	else
	{
		if (!(padded_str = malloc(sizeof(char) * 2)))
			return (0);
		padded_str[0] = '%';
		padded_str[1] = '\0';
	}
	return (padded_str);
}
/*
char	*ft_handle_oct(char *str, t_str_fmt *fmt_struc)
{
	char *string;
	char *pad;
	char *pad_w_0;
	pad = NULL;
	string = NULL;
	if (fmt_struc->flag.hash)
	{
		if (!(pad = malloc(sizeof(char) * (fmt_struc->wid - 3))))
			return (0);
		ft_memset(pad, '0', (fmt_struc->wid - ft_strlen(str) - 2));
		pad_w_0 = ft_strjoin("0x", pad);
		return (string = ft_strjoin(pad_w_0, str));
	}
	else
	{
		if (!(pad = malloc(sizeof(char) * (fmt_struc->wid - 1))))
			return (0);
		ft_memset(pad, '0', (fmt_struc->wid - ft_strlen(str)));
		return (string = ft_strcat(pad, str));
	}
}
*/
