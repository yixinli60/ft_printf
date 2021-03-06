/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:47:07 by yli               #+#    #+#             */
/*   Updated: 2016/12/02 14:55:25 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *area;

	area = malloc(size + 1);
	if (!area)
		return (NULL);
	ft_memset(area, '\0', size + 1);
	return (area);
}
