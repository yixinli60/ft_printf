/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:17:28 by yli               #+#    #+#             */
/*   Updated: 2016/12/05 11:18:07 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_neg(long long *nbr, long long *neg)
{
	if (*nbr < 0)
	{
		*nbr = *nbr * -1;
		*neg = 1;
	}
}

char		*ft_itoa(long long n)
{
	long long	tmp;
	long long len;
	long long	neg;
	char			*str;

	//if (n == 9223372034)
	//	return (ft_strdup("9223372034"));
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
