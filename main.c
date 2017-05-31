/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 20:10:41 by yli               #+#    #+#             */
/*   Updated: 2017/05/25 12:13:28 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft/libft.h"
#include "include/ft_printf.h"

int	main(void)
{

 printf("|%#08x|\n", 42);
 ft_printf("|%#08x|\n", 42);

  /*
//long nbr = 4294967296;

printf("@moulitest: |%#.o| |%#.0o|\n", 0, 0);
ft_printf("@moulitest: |%#.o| |%#.0o|\n", 0, 0);

printf("@moulitest: |%#5.o| |%#.0o|\n", 0, 0);
ft_printf("@moulitest: |%#5.o| |%#.0o|\n", 0, 0);

printf("@moulitest: |%#0.5x| |%#5.0x|\n", 0, 0);
ft_printf("@moulitest: |%#0.5x| |%#5.0x|\n", 0, 0);

printf("@moulitest: |%#-10.5x| |%#5.10x|\n", 0, 0);
ft_printf("@moulitest: |%#-10.5x| |%#5.10x|\n", 0, 0);


//  printf("leng is %d\n", leng);
//  printf("len is %d\n", len);

  int zero = 0;
  int nbr = 12345678;

  //char c = 'A';
  char *string = "0fjeowuf4983uru430ru349-tu4-394u3-93";

  ft_printf("|%014.15d|\n", nbr);
  printf("|%014.15d|\n\n", nbr);

  printf("pointer:\n");
  ft_printf("|%9p|\n", string);
  printf("|%9p|\n\n", string);

  printf("hex:\n");
  ft_printf("|%-#10x|\n", 123456789);
  printf("|%-#10x|\n\n", 123456789);

  printf("octal:\n");
  ft_printf("|%#15o|\n", 123456789);
  printf("|%#15o|\n\n", 123456789);

  printf("precision, string, no width, 0 flag,:\n");
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
