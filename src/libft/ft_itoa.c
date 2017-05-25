/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:17:28 by yli               #+#    #+#             */
/*   Updated: 2017/05/10 14:16:04 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static void	ft_neg(uintmax_t *nbr, uintmax_t *neg)
{
	if (*nbr < 0)
	{
		*nbr = *nbr * -1;
		*neg = 1;
	}
}
*/
char		*ft_itoa(uintmax_t n)
{
	uintmax_t	tmp;
	uintmax_t	len;
	//uintmax_t	neg;
	char		*str;

	tmp = n;
	len = 1;
	//neg = 0;
	//ft_neg(&n, &neg);
	while (tmp /= 10)
		len++;
	//len = len + neg;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	//if (neg)
	//	str[0] = '-';
	return (str);
}
