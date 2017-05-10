/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 20:10:41 by yli               #+#    #+#             */
/*   Updated: 2017/05/03 20:25:40 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

int			main(void)
{
	//int zero = 0;
	long long int nbr = 2147483647;


	char c = 'a';
	//char *string = "Hello!";

	ft_printf("|%-15c|\n", c);
	printf("|%-15c|\n\n", c);

  printf("width, string, no precision, 0 flag:\n");
  ft_printf("|%lld|\n", nbr);
	printf("|%lld|\n\n", nbr);

	/*printf("precision, string, no width, 0 flag,:\n");
  ft_printf("|%0.15d|\n", nbr);
	printf("|%0.15d|\n\n", nbr);

	printf("\n----------ZERO STRING----------\n");

	printf("precision is .0:\n");
	ft_printf("|%+.0d|\n", zero);
	printf("|%+.0d|\n\n", zero);

	printf("' 7d':\n");
	ft_printf("|% 7.0d|\n", zero);
	printf("|% 7.0d|\n\n", zero);

	printf("'0d':\n");
	ft_printf("|%0d|\n", zero);
	printf("|%0d|\n\n", zero);

	printf("'-7d':\n");
	ft_printf("|%-7d|\n", zero);
	printf("|%-7d|\n\n", zero);

	printf("' 0d':\n");
	ft_printf("|% 0d|\n", zero);
	printf("|% 0d|\n\n", zero);

	printf("\n----------ZERO FLAG----------\n");

	printf("precision, string, width:\n");
	ft_printf("|%02.15d|\n", nbr);
	printf("|%02.15d|\n\n", nbr);

	printf("precision, width, string:\n");
	ft_printf("|%013.15d|\n", nbr);
	printf("|%013.15d|\n\n", nbr);

	printf("string, precision, width:\n");
	ft_printf("|%01.7d|\n", nbr);
	printf("|%01.7d|\n\n", nbr);

	printf("string, width, precision:\n");
	ft_printf("|%04.2d|\n", nbr);
	printf("|%04.2d|\n\n", nbr);

	printf("width, string, precision:\n");
	ft_printf("|%015.2d|\n", nbr);
	printf("|%015.2d|\n\n", nbr);

	printf("width, precision, string:\n");
	ft_printf("|%015.12d|\n", nbr);
	printf("|%015.12d|\n\n", nbr);

	printf("\n----------SPACE FLAG----------\n");

	printf("precision, string, width:\n");
	ft_printf("|% 1.12d|\n", nbr);
	printf("|% 1.12d|\n\n", nbr);

	printf("precision, width, string:\n");
	ft_printf("|% 12.15d|\n", nbr);
	printf("|% 12.15d|\n\n", nbr);

	printf("string, precision, width:\n");
	ft_printf("|% 1.2d|\n", nbr);
	printf("|% 1.2d|\n\n", nbr);

	printf("string, width, precision:\n");
	ft_printf("|% 4.2d|\n", nbr);
	printf("|% 4.2d|\n\n", nbr);

	printf("width, string, precision:\n");
	ft_printf("|% 15.1d|\n", nbr);
	printf("|% 15.1d|\n\n", nbr);

	printf("width, precision, string:\n");
	ft_printf("|% -15.12d|\n", nbr);
	printf("|% -15.12d|\n\n", nbr);

	printf("\n----------PLUS FLAG----------\n");

	printf("precision, string, width:\n");
	ft_printf("|%+1.12d|\n", nbr);
	printf("|%+1.12d|\n\n", nbr);

	printf("precision, width, string:\n");
	ft_printf("|%+12.15d|\n", nbr);
	printf("|%+12.15d|\n\n", nbr);

	printf("string, precision, width:\n");
	ft_printf("|%+1.2d|\n", nbr);
	printf("|%+1.2d|\n\n", nbr);

	printf("string, width, precision:\n");
	ft_printf("|%+4.2d|\n", nbr);
	printf("|%+4.2d|\n\n", nbr);

	printf("width, string, precision:\n");
	ft_printf("|%+15.1d|\n", nbr);
	printf("|%+15.1d|\n\n", nbr);

	printf("width, precision, string:\n");
	ft_printf("|%+15.12d|\n", nbr);
	printf("|%+15.12d|\n\n", nbr);
*/
	return (0);
}
