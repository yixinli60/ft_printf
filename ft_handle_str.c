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
