/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:54:57 by yli               #+#    #+#             */
/*   Updated: 2017/05/04 17:18:26 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft/libft.h"
#include "include/ft_printf.h"

char	*ft_add_signs(char *str, t_str_fmt *fmt_struc)
{
	char *string;

	if (fmt_struc->flag.hash && fmt_struc->hex)
		str[1] = 'x';
	if (fmt_struc->conv == 'u' || fmt_struc->conv == 'U')
		return (str);
	if (!(string = malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (0);
	if (fmt_struc->neg_nbr)
		string = ft_strjoin("-", str);
	else if (fmt_struc->flag.plus)
		string = ft_strjoin("+", str);
	else if (fmt_struc->flag.space)
		string = ft_strjoin(" ", str);
	else if (fmt_struc->flag.zero && fmt_struc->wid > (int)ft_strlen(str) &&
					fmt_struc->pre > fmt_struc->wid)
		string = ft_strjoin("0", str);
	else
		string = str;
	return (string);
}

char	*ft_add_space(char *str_w_0pad, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*str_w_spad;
	int		wid;

	wid = fmt_struc->wid;
	if (fmt_struc->pre > (int)ft_strlen(str_w_0pad))
	{
		if (!(pad = malloc(sizeof(char) * (wid - fmt_struc->pre + 1))))
			return (0);
		ft_memset(pad, ' ', (wid - fmt_struc->pre));
		pad[(wid - fmt_struc->pre)] = '\0';
	}
	else
	{
		if (wid >= (int)ft_strlen(str_w_0pad))
		{
			if (!(pad = malloc(sizeof(char) * (wid - ft_strlen(str_w_0pad) + 1))))
				return (0);
			ft_memset(pad, ' ', (wid - ft_strlen(str_w_0pad)));
			pad[(wid - ft_strlen(str_w_0pad))] = '\0';
		}
		else
		{
			if (!(pad = malloc(sizeof(char) * 1)))
				return (0);
			pad[0] = '\0';
		}
	}
	str_w_spad = ft_mflag(str_w_0pad, pad, fmt_struc);
	free(str_w_0pad);
	free(pad);
	return (str_w_spad);
}

char	*ft_mflag(char *str, char *pad, t_str_fmt *fmt_struc)
{
	if (fmt_struc->flag.minus)
		return (ft_strjoin(str, pad));
	return (ft_strcat(pad, str));
}
