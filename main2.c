#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include "src/libft/libft.h"

int main(void)
{
/*
  printf("%s %s %hhdh\n", "ONE", "TWO", (char)-50);
  ft_printf("%s %s %hhdh\n", "ONE", "TWO", (char)-50);

  printf("%X\n", -500);
  ft_printf("%X\n", -500);

  printf("%d\n", -500);
  ft_printf("%d\n", -500);

  printf("%d\n", INT_MAX);
  ft_printf("%2d\n", INT_MAX);

  printf("%d\n", INT_MIN);
  ft_printf("%d\n", INT_MIN);

  printf("%lld\n", LLONG_MAX);
  ft_printf("%lld\n", LLONG_MAX);

  printf("%lld\n", LLONG_MIN);
  ft_printf("%lld\n", LLONG_MIN);

  printf("%llX\n", LLONG_MAX);
  ft_printf("%llX\n", LLONG_MAX);

  printf("%llX\n", LLONG_MIN);
  ft_printf("%llX\n", LLONG_MIN);

  printf("%hhd\n", (char)-10);
  ft_printf("%hhd\n", (char)-10);

  printf("%zu\n", (size_t)10);
  ft_printf("%zu\n", (size_t)10);

  //printf("%f\n", 5.5);
  //ft_printf("%f\n", 5.5);

  printf("%0.4D\n", 444);
  ft_printf("%0.4D\n", 444);

  printf("%0.40D\n", 555);
  ft_printf("%0.40D\n", 555);

  printf("%0.2D\n", 555);
  ft_printf("%0.2D\n", 555);

  printf("%.5D\n", 555);
  ft_printf("%.5D\n", 555);

  printf("%-.8D\n", 888);
  ft_printf("%-.8D\n", 888);
*/
  printf("%012.8D\n", 123);
  ft_printf("%012.8D\n", 123);
/*
  printf("%012.1D\n", 122);
  ft_printf("%012.1D\n", 122);

  printf("%0.4D\n", -444);
  ft_printf("%0.4D\n", -444);

  printf("%0.40d\n", -555);
  ft_printf("%0.40d\n", -555);

  printf("%0.2d\n", -555);
  ft_printf("%0.2d\n", -555);

  printf("%.5d\n", -555);
  ft_printf("%.5d\n", -555);

  printf("%-.8d\n", -888);
  ft_printf("%-.8d\n", -888);

  printf("%012.8d\n", -122);
  ft_printf("%012.8d\n", -122);

  printf("%012.5d\n", -122);
  ft_printf("%012.5d\n", -122);

  printf("%012d\n", -122);
  ft_printf("%012d\n", -122);

  printf("%012.d\n", -122);
  ft_printf("%012.d\n", -122);

  printf("|%012.0d|\n", 0);
  ft_printf("|%012.0d|\n", 0);

  printf("|%12.0d|\n", 0);
  ft_printf("|%12.0d|\n", 0);

  printf("%12.1d\n", 0);
  ft_printf("%12.1d\n", 0);

  printf("%012d\n", 0);
  ft_printf("%012d\n", 0);

  printf("%-5dright\n", -888);
  ft_printf("%-5dright\n", -888);

  printf("left% 5dright\n", 888);
  ft_printf("left% 5dright\n", 888);

  printf("left%+5dright\n", 777);
  ft_printf("left%+5dright\n", 777);

  printf("left% 1dright\n", 11);
  ft_printf("left% 1dright\n", 11);
  printf("----------------\n");

  printf("left% 05dright\n", 777);
  ft_printf("left% 05dright\n", 777);

  printf("left%+05dright\n", 888);
  ft_printf("left%+05dright\n", 888);

  printf("left%+02dright\n", 888);
  ft_printf("left%+02dright\n", 888);

  printf("%012.5u\n", -122);
  ft_printf("%012.5u\n", -122);

  printf("%012X (122)\n", -122);
  ft_printf("%012X (122)\n", -122);

  printf("%-5xright\n", -888);
  ft_printf("%-5xright\n", -888); //prints extra ffffffff

  printf("left%5xright\n", 888);
  ft_printf("left%5xright\n", 888);

  printf("left%5xright\n", 777);
  ft_printf("left%5xright\n", 777);

  printf("left%1xright\n", 11);
  ft_printf("left%1xright\n", 11);

  void*ptr = "string";
  printf("%30p\n", ptr);
  ft_printf("%30p\n", ptr);

  printf("left%1oright\n", 11);
  ft_printf("left%1oright\n", 11);

  printf("left%1Oright\n", 11);
  ft_printf("left%1Oright\n", 11);

  printf("%U\n", -10);
  ft_printf("%U\n", -10);

  printf("%jx\n", (uintmax_t)(- 1));
  ft_printf("%jx\n", (uintmax_t)(- 1));

  printf("%jx\n", (uintmax_t)(- 2));
  ft_printf("%jx\n", (uintmax_t)(- 2));

  printf("%u\n", UINT_MAX + 1);
  ft_printf("%u\n", UINT_MAX + 1);

  printf("|%.5s|\n", "string");
  ft_printf("|%.5s|\n", "string");

  printf("%10s\n", "string");
  ft_printf("%10s\n", "string");

  printf("%#6.4o\n", 10);
  ft_printf("%#6.4o\n", 10);

  printf("%#6.2o\n", 10);
  ft_printf("%#6.2o\n", 10);

  printf("%#10.3x\n", 10);
  ft_printf("%#10.3x\n", 10);

  printf("%#010.3x\n", 10);
  ft_printf("%#010.3x\n", 10);

  printf("%#010.3X\n", 10);
  ft_printf("%#010.3X\n", 10);

  printf("%c\n", (char)'c');
  ft_printf("%c\n", (char)'c');

  printf("%x\n", (short)(0b1 << 31 >> 23));
  ft_printf("%x\n", (short)(0b1 << 31 >> 23));

  printf("%ls\n", L"test"); //prints test
  ft_printf("%ls\n", L"test"); // prints t

  ft_printf("--------- extra stuff after this ----------\n");

  printf("%hhx\n", (char)0b11000000);
  ft_printf("%hhx\n", (char)0b11000000);
  printf("---\n");
  printf("%lc\n", 0x01F604);
  ft_printf("%lc\n", 0x01F604);
  printf("%#08x\n", 42);
  ft_printf("%#08x\n", 42);
*/
return (0);
}
