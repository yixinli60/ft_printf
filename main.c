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
  //int len = 0;
  //int leng = 0;

  /*
  printf("HEX TEST\n");
  printf("______________\n\n");

  printf("wid not set, pre not set:\n");
  printf("|%x|\n", 0);
  ft_printf("|%x|\n", 0);

  printf("len, pre, wid:\n");
  printf("|%#0x|\n", 0);
  ft_printf("|%#0x|\n", 0);

  printf("len, wid, pre:\n");
  printf("|%#2.1x|\n", 0);
  ft_printf("|%#2.1x|\n", 0);

  printf("wid, pre, len:\n");
  printf("|%#10.8x|\n", 0);
  ft_printf("|%#10.8x|\n", 0);

  printf("wid, len, pre:\n");
  printf("|%#10.1x|\n", 0);
  ft_printf("|%#10.1x|\n\n", 0);

  printf("pre, len, wid:\n");
  printf("|%#0.10x|\n", 0);
  ft_printf("|%#0.10x|\n\n", 0);


  printf("pre, wid, len:\n");
  printf("|%#9.10x|\n", 0);
  ft_printf("|%#9.10x|\n\n", 0);

  printf("HEX TEST nbr is 1234\n");
  printf("|%x|\n", 1234);
  ft_printf("|%x|\n", 1234);

  printf("len, pre, wid:\n");
  printf("|%#1.2x|\n", 1234);
  ft_printf("|%#1.2x|\n", 1234);

  printf("len, wid, pre:\n");
  printf("|%#2.1x|\n", 1234);
  ft_printf("|%#2.1x|\n", 1234);

  printf("wid, pre, len:\n");
  printf("|%#10.8x|\n", 1234);
  ft_printf("|%#10.8x|\n", 1234);

  printf("wid, len, pre:\n");
  printf("|%#10.1x|\n", 1234);
  ft_printf("|%#10.1x|\n", 1234);
*/
  //printf("pre, wid, len:\n");
  //printf("|%#8.10x|\n", 1234);
  //ft_printf("|%#8.10x|\n", 1234);

  //printf("pre, len, wid:\n");
  //printf("|%#1.10x|\n", 1234);
  //ft_printf("|%#1.10x|\n", 1234);
  //printf("______________\n\n");

//printf("|%-5.3s|\n", "LYDI");
//ft_printf("|%-5.3s|\n", "LYDI");


printf("STRING TEST\n");
printf("______________\n\n");

printf("wid not set, pre not set:\n");
printf("|%s|\n", "HELEOIJ");
ft_printf("|%s|\n\n", "HELEOIJ");

printf("len, wid, pre not set:\n");
printf("|%1s|\n", "HELEOIJ");
ft_printf("|%1s|\n\n", "HELEOIJ");

printf("wid, len, pre not set:\n");
printf("|%-15s|\n", "HELEOIJ");
ft_printf("|%-15s|\n\n", "HELEOIJ");

printf("len, wid, pre = 0:\n");
printf("|%1.0s|\n", "HELEOIJ");
ft_printf("|%1.0s|\n\n", "HELEOIJ");

printf("wid, len, pre = 0:\n");
printf("|%10.0s|\n", "HELEOIJ");
ft_printf("|%10.0s|\n\n", "HELEOIJ");

printf("len, pre, wid:\n");
printf("|%1.4s|\n", "HELEOIJ");
ft_printf("|%1.4s|\n\n", "HELEOIJ");

printf("pre, len, wid:\n");
printf("|%1.15s|\n", "HELEOIJ");
ft_printf("|%1.15s|\n\n", "HELEOIJ");

printf("wid, len, pre:\n");
printf("|%-10.1s|\n", "HELEOIJ");
ft_printf("|%-10.1s|\n\n", "HELEOIJ");


printf("len, wid, pre:\n");
printf("|%-4.1s|\n", "HELEOIJ");
ft_printf("|%-4.1s|\n\n", "HELEOIJ");

printf("pre, wid, len:\n");
printf("|%-10.15s|\n", "HELEOIJ");
ft_printf("|%-10.15s|\n\n", "HELEOIJ");


printf("wid, pre, len:\n");
printf("|%-15.10s|\n", "HELEOIJ");
ft_printf("|%-15.10s|\n\n", "HELEOIJ");

printf("______________\n\n");

/*
printf("len is %d, leng is %d\n", len, leng);

printf("|% 10.1d|\n", 1234);
ft_printf("|% 10.1d|\n", 1234);

printf("|%+10.1d|\n", 1234);
ft_printf("|%+10.1d|\n", 1234);

printf("|%-10.1d|\n", 1234);
ft_printf("|%-10.1d|\n", 1234);

printf("|%010.1d|\n", 1234);
ft_printf("|%010.1d|\n", 1234);

printf("|% -10.1d|\n", 1234);
ft_printf("|% -10.1d|\n", 1234);
*/
//printf("|%#010.9d|\n", 1234);
//ft_printf("|%#010.9d|\n", 1234);



//printf("|%+4d|\n", 0); //prints test
//ft_printf("|%+4d|\n", 0); // prints t
/*int len = 0;
int leng = 0;
  len = printf("|5%|\n");
  leng = ft_printf("|5 %|\n");
printf("len is %d\n", len);
printf("leng is %d\n", leng);
*/
//printf("|%.p|, |%.0p|\n", 0, 0);
//ft_printf("|%.p|, |%.0p|\n", 0, 0);




/*
printf("|%#08x|\n", 42);
ft_printf("|%#08x|\n\n", 42);

printf("|%#8.5x|\n", 42);
ft_printf("|%#8.5x|\n\n", 42);

printf("|%#08.9x|\n", 42);
ft_printf("|%#08.9x|\n\n", 42);

printf("|%#0.x|\n", 42);
ft_printf("|%#0.x|\n\n", 42);


//printf("%d, {10R}, %s\n", 10, "HELLO"); //moulitest 50 shows error????
//ft_printf("%d, {10R}, %s\n\n", 10, "HELLO");

printf("{%-15Z}\n", 123);
ft_printf("{%-15Z}\n\n", 123);

printf("|%#5.O|\n", 100);        //| 0144|
ft_printf("|%#5.O|\n\n", 100);   //|     |

printf("|%#o|\n", 0);         //|0|
ft_printf("|%#o|\n\n", 0);    //|00|

printf("|%#5x|\n", 0);        // |    0|
ft_printf("|%#5x|\n\n", 0);   // |0|


// printf("|%ls|\n", L"test"); //prints test
// ft_printf("|%ls|\n", L"test"); // prints t

//long nbr = 4294967296;



printf("leng is %d\n", leng);
printf("len is %d\n", len);

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
