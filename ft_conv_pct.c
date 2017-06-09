/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:05:54 by yli               #+#    #+#             */
/*   Updated: 2017/06/09 11:05:58 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft/libft.h"
#include "include/ft_printf.h"

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
