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

static void	ft_neg(intmax_t *nbr, intmax_t *neg)
{
	if (*nbr < 0)
	{
		*nbr = *nbr * -1;
		*neg = 1;
	}
}

char		*ft_itoa(intmax_t n)
{
	intmax_t	tmp;
	intmax_t	len;
	intmax_t	neg;
	char		*str;

	tmp = n;
	len = 1;
	neg = 0;
	ft_neg(&n, &neg);
	while (tmp /= 10)
		len++;
	len = len + neg;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
