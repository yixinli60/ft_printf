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
		return (str_w_spad);
	}
	return (str_w_0pad);
}

char	*ft_hex_zero(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;

	if (!(pad = malloc(sizeof(char) * (fmt_struc->wid + 1))))
		return (0);
	ft_memset(pad, ' ', fmt_struc->wid);
	pad[(fmt_struc->wid + 1)] = '\0';
	str = pad;
	free(pad);
	return (str);
}

char	*ft_add_hash(char *str, t_str_fmt *fmt_struc)
{
	char	*hash_pad;

	if (fmt_struc->flag.hash)
	{
		hash_pad = ft_strjoin("0x", str);
		return (hash_pad);
	}
	else
		return (str);
}

char	*ft_zero_hash(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*zero_pad;

	if (!(pad = malloc(sizeof(char) * (fmt_struc->wid - ft_strlen(str) + 1))))
		return (0);
	ft_memset(pad, '0', (fmt_struc->wid - ft_strlen(str)));
	pad[(fmt_struc->wid - ft_strlen(str))] = '\0';
	zero_pad = ft_strjoin(pad, str);
	free(pad);
	if (fmt_struc->flag.hash)
		zero_pad[1] = 'x';
	return (zero_pad);
}

char	*ft_handle_hex(char *str, t_str_fmt *fmt_struc)
{
	char	*hash_pad;
	char	*pad;
	int		len;

	len = ft_strlen(str);
	if ((len >= fmt_struc->pre) && (len >= fmt_struc->wid))
		return (ft_add_hash(str, fmt_struc));
	else if ((fmt_struc->pre > len) && (fmt_struc->pre >= fmt_struc->wid))
	{
		if (!(pad = malloc(sizeof(char) * fmt_struc->pre - len + 1)))
			return (0);
		ft_memset(pad, '0', (fmt_struc->pre - len));
		pad[(fmt_struc->pre - len + 1)] = '\0';
		hash_pad = ft_strjoin(pad, str);
		free(pad);
		return (ft_add_hash(hash_pad, fmt_struc));
	}
	else if ((fmt_struc->wid >= len) && (len >= fmt_struc->pre))
	{
		if (fmt_struc->pre == -1 && fmt_struc->flag.zero && !fmt_struc->flag.minus)
			return (ft_zero_hash(str, fmt_struc));
		hash_pad = ft_add_hash(str, fmt_struc);
		if (!(pad = malloc(sizeof(char) * (fmt_struc->wid - ft_strlen(hash_pad) + 1))))
			return (0);
		ft_memset(pad, ' ', (fmt_struc->wid - ft_strlen(hash_pad)));
		pad[(fmt_struc->wid - ft_strlen(hash_pad))] = '\0';
		return (ft_mflag(hash_pad, pad, fmt_struc));
	}
	else
		return (str);
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
