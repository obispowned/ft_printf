/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:24:12 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 19:47:56 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int			main()
{

	char	c = 'c';
	int 	x;
	char 	*a = "hola";
	int   	j = 696969;
	int		*p = &j;


	/*ft_printf("\n\n****** CHAR ******\n");

	printf("CARACTERES: %d \n", ft_printf("mi char 9c: -%9c-\n", c));
	printf("CARACTERES: %d \n\n", printf("char 9c :   -%9c-\n", c));
	printf("CARACTERES: %d \n", ft_printf("mi char -5c: -%-5c-\n", c));
	printf("CARACTERES: %d \n\n", printf("char -5c  :  -%-5c-\n", c));
	printf("CARACTERES: %d \n", ft_printf("mi char 4c: -%4c-\n", c));
	printf("CARACTERES: %d \n\n", printf("char 4c :   -%4c-\n", c));
	printf("CARACTERES: %d \n", ft_printf("mi char *c10: -%*c-\n", 10, c));
	printf("CARACTERES: %d \n\n", printf("char  *c10:   -%*c-\n", 10, c));
	printf("CARACTERES: %d \n", ft_printf("mi har *c-10: -%*c-\n", -10, c));
	printf("CARACTERES: %d \n\n", printf("char  *c-10:   -%*c-\n", -10, c));
	printf("CARACTERES: %d \n", ft_printf("mi char *c-5: -%*c-\n", -5, c));
	printf("CARACTERES: %d \n\n", printf("char  *c-5:   -%*c-\n", -5, c));
	printf("CARACTERES: %d \n", ft_printf("mi char *c-20: -%*c-\n", -20, c));
	printf("CARACTERES: %d \n\n", printf("char  *c-20:   -%*c-\n", -20, c));*/

	/*ft_printf("\n\n****** STRINGS ******\n");

	printf("CARACTERES: %d \n", ft_printf("mi printf   15s: %*.*s\n",11, 1, a));
	printf("CARACTERES: %d \n\n", printf("oficial con 15s: %*.*s\n",11, 1, a));
	printf("CARACTERES: %d \n", ft_printf("mi printf   15s: %9.3s\n", a));
	printf("CARACTERES: %d \n\n", printf("oficial con 15s: %9.3s\n", a));
	printf("CARACTERES: %d \n", ft_printf("%s\n", "testing testing"));
	printf("CARACTERES: %d \n\n", printf("%s\n", "testing testing"));
	printf("CARACTERES: %d \n", ft_printf("%s%s", "hello", "world"));
	printf("CARACTERES: %d \n\n", printf("%s%s", "hello", "world"));
	printf("CARACTERES: %d \n", ft_printf("..%s stuff %s", "a", "b"));
	printf("CARACTERES: %d \n\n", printf("..%s stuff %s", "a", "b"));
	printf("CARACTERES: %d \n", ft_printf("this %s is %s", "hello", ""));
	printf("CARACTERES: %d \n\n", printf("this %s is %s", "hello", ""));
	printf("CARACTERES: %d \n", ft_printf("this %s is %s", "", "hello"));
	printf("CARACTERES: %d \n\n", printf("this %s is %s", "", "hello"));
	printf("CARACTERES: %d \n", ft_printf("%s%s%s", "1", "2", "3's a charm"));
	printf("CARACTERES: %d \n\n", printf("%s%s%s", "1", "2", "3's a charm"));
	printf("CARACTERES: %d \n", ft_printf("%32s", "abc"));
	printf("CARACTERES: %d \n\n", printf("%32s", "abc"));
	printf("CARACTERES: %d \n", ft_printf("hello, %s.", NULL));
	printf("CARACTERES: %d \n\n", printf("hello, %s.", NULL));
	printf("CARACTERES: %d \n", ft_printf("%32s", NULL));
	printf("CARACTERES: %d \n\n", printf("%32s", NULL));
	printf("CARACTERES: %d \n", ft_printf("%-32s", NULL));
	printf("CARACTERES: %d \n\n", printf("%-32s", NULL));
	printf("CARACTERES: %d \n", ft_printf("%-16s", NULL));
	printf("CARACTERES: %d \n\n", printf("%-16s", NULL));
	printf("CARACTERES: %d \n", ft_printf("%.03s", NULL));
	printf("CARACTERES: %d \n\n", printf("%.03s", NULL));
	printf("CARACTERES: %d \n", ft_printf("%3.s", NULL));
	printf("CARACTERES: %d \n\n", printf("%3.s", NULL));
	printf("CARACTERES: %d \n", ft_printf("%10.s", NULL));
	printf("CARACTERES: %d \n\n", printf("%10.s", NULL));
	printf("CARACTERES: %d \n", ft_printf("%-3.s", NULL));
	printf("CARACTERES: %d \n\n", printf("%-3.s", NULL));
	printf("CARACTERES: %d \n", ft_printf("%-8.s", NULL));
	printf("CARACTERES: %d \n\n", printf("%-8.s", NULL));
	printf("CARACTERES: %d \n", ft_printf("%-3.1s", NULL));
	printf("CARACTERES: %d \n\n", printf("%-3.1s", NULL));
	printf("CARACTERES: %d \n", ft_printf("%7.5s", "123456789"));
	printf("CARACTERES: %d \n\n", printf("%7.5s", "123456789"));
	printf("CARACTERES: %d \n", ft_printf("%0-0s", "hi low"));
	printf("CARACTERES: %d \n\n", printf("%0-0s", "hi low"));
	printf("CARACTERES: %d \n", ft_printf("%00-s", "hi low"));
	printf("CARACTERES: %d \n\n", printf("%00-s", "hi low"));
	printf("CARACTERES: %d \n", ft_printf("%09s", "hi low"));
	printf("CARACTERES: %d \n\n", printf("%09s", "hi low"));*/

	/*ft_printf("\n\n****** INT ******\n");

	printf("|CARACTERES: %d \n\n", printf("%-7d", -14));
	printf("|CARACTERES: %d \n\n", ft_printf("%-7d", -14));
	printf("|CARACTERES: %d \n", ft_printf("MI int con 9.7: %9.7d\n", j));
	printf("|CARACTERES: %d \n\n", printf("int con 9.7   : %9.7d\n", j));
	printf("|CARACTERES: %d \n", ft_printf("MI int con 7.9: %7.9d\n", j));
	printf("|CARACTERES: %d \n\n", printf("int con 7.9   : %7.9d\n", j));
	printf("|CARACTERES: %d \n", ft_printf("%7d", 33));
	printf("|CARACTERES: %d \n\n", printf("%7d", 33));
	printf("|CARACTERES: %d \n", ft_printf("%7d", -14));
	printf("|CARACTERES: %d \n\n", printf("%7d", -14));
	printf("|CARACTERES: %d \n", ft_printf("%3d", 0));
	printf("|CARACTERES: %d \n\n", printf("%3d", 0));
	printf("|CARACTERES: %d \n", ft_printf("%-7d", 33));
	printf("|CARACTERES: %d \n\n", printf("%-7d", 33));
	printf("|CARACTERES: %d \n", ft_printf("%-7d", -14));
	printf("|CARACTERES: %d \n\n", printf("%-7d", -14));
	printf("|CARACTERES: %d \n", ft_printf("%-3d", 0));
	printf("|CARACTERES: %d \n\n", printf("%-3d", 0));
	printf("|CARACTERES: %d \n", ft_printf("%.5d", 2));
	printf("|CARACTERES: %d \n\n", printf("%.5d", 2));
	printf("|CARACTERES: %d \n", ft_printf("%.6d", -3));
	printf("|CARACTERES: %d \n\n", printf("%.6d", -3));
	printf("|CARACTERES: %d \n", ft_printf("%.3d", 0));
	printf("|CARACTERES: %d \n\n", printf("%.3d", 0));
	printf("|CARACTERES: %d \n", ft_printf("%05d", 43));
	printf("|CARACTERES: %d \n\n", printf("%05d", 43));
	printf("|CARACTERES: %d \n", ft_printf("%07d", -54));
	printf("|CARACTERES: %d \n\n", printf("%07d", -54));
	printf("|CARACTERES: %d \n", ft_printf("%03d", 0));
	printf("|CARACTERES: %d \n\n", printf("%03d", 0));
	printf("|CARACTERES: %d \n", ft_printf("%3.7d", -2375));
	printf("|CARACTERES: %d \n\n", printf("%3.7d", -2375));
	printf("|CARACTERES: %d \n", ft_printf("%0-8.5d", 34));
	printf("|CARACTERES: %d \n\n", printf("%0-8.5d", 34));
	printf("|CARACTERES: %d \n", ft_printf("%-10.5d", -216));
	printf("|CARACTERES: %d \n\n", printf("%-10.5d", -216));
	printf("|CARACTERES: %d \n", ft_printf("%10.5d", -216));
	printf("|CARACTERES: %d \n\n", printf("%10.5d", -216));
	printf("|CARACTERES: %d \n", ft_printf("%-8.5d", 34));
	printf("|CARACTERES: %d \n\n", printf("%-8.5d", 34));
	printf("|CARACTERES: %d \n\n", printf("%d", 0));
	printf("|CARACTERES: %d \n\n", ft_printf("%d", 0));
	printf("|CARACTERES: %d \n\n", printf("%07d", -54));
	printf("|CARACTERES: %d \n\n", ft_printf("%07d", -54));
	printf("|CARACTERES: %d \n\n", printf("%0-8.5d", 34));
	printf("|CARACTERES: %d \n\n", ft_printf("%0-8.5d", 34));
	printf("|CARACTERES: %d \n\n", printf("%0-10.5d", -216));
	printf("|CARACTERES: %d \n\n", ft_printf("%0-10.5d", -216));
	printf("|CARACTERES: %d \n\n", printf("%0-8.5d", 0));
	printf("|CARACTERES: %d \n\n", ft_printf("%0-8.5d", 0));
	printf("\n\n");
	printf("|CARACTERES: %d \n", ft_printf("%.0d", 0));
	printf("|CARACTERES: %d \n\n", printf("%.0d", 0));
	printf("|CARACTERES: %d \n", printf("%.d", 0));
	printf("|CARACTERES: %d \n\n", ft_printf("%.d", 0));
	printf("|CARACTERES: %d \n", printf("%5.0d", 0));
	printf("|CARACTERES: %d \n\n", ft_printf("%5.0d", 0));
	printf("|CARACTERES: %d \n", printf("%5.d", 0));
	printf("|CARACTERES: %d \n\n", ft_printf("%5.d", 0));
	printf("|CARACTERES: %d \n", printf("%-5.0d", 0));
	printf("|CARACTERES: %d \n\n", ft_printf("%-5.0d", 0));
	printf("|CARACTERES: %d \n", printf("%-5.d", 0));
	printf("|CARACTERES: %d \n\n", ft_printf("%-5.d", 0));*/

	/*ft_printf("\n\n****** UNSIGNED ******\n");

	printf("CARACTERES: %d \n", printf("\noFiUNSIGNED %u\n", 30));
	printf("CARACTERES: %d \n\n", ft_printf("\nUNSIGNED %u\n", 30));
		printf("CARACTERES: %d \n", printf("%u", 4294967295u));
	printf("CARACTERES: %d \n\n", ft_printf("%u", 4294967295u));
		printf("CARACTERES: %d \n", printf("%7u", 33));
	printf("CARACTERES: %d \n\n", ft_printf("%7u", 33));
		printf("CARACTERES: %d \n", printf("%3u", 0));
	printf("CARACTERES: %d \n\n", ft_printf("%3u", 0));
		printf("CARACTERES: %d \n", printf("%-7u", 33));
	printf("CARACTERES: %d \n\n", ft_printf("%-7u", 33));
		printf("CARACTERES: %d \n", printf("%-3u", 0));
	printf("CARACTERES: %d \n\n", ft_printf("%-3u", 0));
		printf("CARACTERES: %d \n", printf("%.5u", 2));
	printf("CARACTERES: %d \n\n", ft_printf("%.5u", 2));
		printf("CARACTERES: %d \n", printf("%05u", 43));
	printf("CARACTERES: %d \n\n", ft_printf("%05u", 43));
		printf("CARACTERES: %d \n", printf("%8.5u", 0));
	printf("CARACTERES: %d \n\n", ft_printf("%8.5u", 0));*/


	/*ft_printf("\n\n****** HEX ******\n");

	printf("CARACTERES: %d \n", ft_printf("HEXADECIMAL: %x\n", 4779));
	printf("CARACTERES: %d \n\n", printf("oficial HEXADECIMAL: %x\n", 4779));
	printf("CARACTERES: %d \n", ft_printf("HEXADECIMAL 6.6: %6.6x\n", 2323));
	printf("CARACTERES: %d \n\n", printf("oficialHEXADECIMAL 6.6: %6.6x\n", 2323));
	printf("CARACTERES: %d \n", ft_printf("HEXADECIMAL 3.9: %3.9x\n", 6969));
	printf("CARACTERES: %d \n\n", printf("oficialHEXADECIMAL 3.9: %3.9x\n", 6969));
	printf("CARACTERES: %d \n", ft_printf("HEXADECIMAL 9.3: %9.3x\n", 111));
	printf("CARACTERES: %d \n\n", printf("oficialHEXADECIMAL 9.3: %9.3x\n", 111));
	printf("CARACTERES: %d \n", ft_printf("HEXADECIMAL 1.9: %1.9x\n", 111));
	printf("CARACTERES: %d \n\n", printf("oficialHEXADECIMAL 1.9: %1.9x\n", 111));
	printf("CARACTERES: %d \n", ft_printf("this %x number", 0));
	printf("CARACTERES: %d \n\n", printf("this %x number", 0));*/


	/*ft_printf("\n\n****** PUNTEROS ******\n");

	printf("CARACTERES: %d \n", ft_printf("punteros    p: %p\n", p));
	printf("CARACTERES: %d \n\n", printf("OFIpunteros p: %p\n", p));
	printf("CARACTERES: %d \n", ft_printf("punteros    8p: -%8p-\n", p));
	printf("CARACTERES: %d \n\n", printf("OFIpunteros 8p: -%8p-\n", p));
	printf("CARACTERES: %d \n", ft_printf("punteros    9.3p: -%9.3p-\n", p));
	printf("CARACTERES: %d \n\n", printf("OFIpunteros 9.3p: -%9.3p-\n\n", p));
	printf("CARACTERES: %d \n", ft_printf("punteros    3.7p: -%3.7p-\n", p));
	printf("CARACTERES: %d \n\n", printf("OFIpunteros 3.7p: -%3.7p-\n", p));

	printf("CARACTERES: %d \n", ft_printf("%p", NULL));
	printf("CARACTERES: %d \n\n", printf("%p", NULL));
	printf("CARACTERES: %d \n", ft_printf("%5p", NULL));
	printf("CARACTERES: %d \n\n", printf("%5p", NULL));
	printf("CARACTERES: %d \n", ft_printf("%.p", NULL));
	printf("CARACTERES: %d \n\n", printf("%.p", NULL));
	printf("CARACTERES: %d \n", ft_printf("%9.2p", 1234));
	printf("CARACTERES: %d \n\n", printf("%9.2p", 1234));

	printf("CARACTERES: %d \n", ft_printf("%2.9p", 1234));
	printf("CARACTERES: %d \n\n", printf("%2.9p", 1234));
	printf("CARACTERES: %d \n", ft_printf("%.5p", 0));
	printf("CARACTERES: %d \n\n", printf("%.5p", 0));
	printf("CARACTERES: %d \n", ft_printf("%.0p", 0));
	printf("CARACTERES: %d \n\n", printf("%.0p", 0));
	printf("CARACTERES: %d \n", ft_printf("%5p", 0));
	printf("CARACTERES: %d \n\n", printf("%5p", 0));
	printf("CARACTERES: %d \n", ft_printf("%9.2p", 1234));
	printf("CARACTERES: %d \n\n", printf("%9.2p", 1234));
	printf("CARACTERES: %d \n", ft_printf("%.5p", 0));
	printf("CARACTERES: %d \n\n", printf("%.5p", 0));
	printf("CARACTERES: %d \n", ft_printf("%p", NULL));
	printf("CARACTERES: %d \n\n", printf("%p", NULL));
	printf("CARACTERES: %d \n", ft_printf("%5p", NULL));
	printf("CARACTERES: %d \n\n", printf("%5p", NULL));
	printf("CARACTERES: %d \n", ft_printf("%2p", NULL));
	printf("CARACTERES: %d \n\n", printf("%2p", NULL));
	printf("CARACTERES: %d \n", ft_printf("%.5p", 0));
	printf("CARACTERES: %d \n\n", printf("%.5p", 0));
	printf("CARACTERES: %d \n", ft_printf("%5p", 0));
	printf("CARACTERES: %d \n\n", printf("%5p", 0));
	printf("CARACTERES: %d \n", ft_printf("%p",&j));
	printf("CARACTERES: %d \n\n", printf("%p",&j));
	printf("CARACTERES: %d \n", ft_printf("%p",p));
	printf("CARACTERES: %d \n\n", printf("%p",p));
	printf("CARACTERES: %d \n", ft_printf("%.5p", 0));
	printf("CARACTERES: %d \n\n", printf("%.5p", 0));
	printf("CARACTERES: %d \n", ft_printf("%p", 1234));
	printf("CARACTERES: %d \n\n", printf("%p", 1234));
	printf("CARACTERES: %d \n\n", printf("%p", (void *)-1));
	printf("CARACTERES: %d \n\n", ft_printf("%p", (void *)-1));*/

	/*ft_printf("\n\n****** UN-HEX ******\n");

	printf("CARACTERES: %d \n", ft_printf("UN-HEXADECIMAL: %X\n", 1598));
	printf("CARACTERES: %d \n\n", printf("oficial-UN-HEXADECIMAL: %X\n", 1598));*/


	ft_printf("\n\n****** OTRAS PRUEBAS ******\n");

/*	printf("CARACTERES: %d \n", ft_printf("%05"));
	printf("CARACTERES: %d \n\n", printf("%05"));
	printf("CARACTERES: %d \n", ft_printf("%-05"));
	printf("CARACTERES: %d \n\n", printf("%-05"));
	printf("CARACTERES: %d \n", ft_printf("%-5"));
	printf("CARACTERES: %d \n\n", printf("%-5"));
	printf("CARACTERES: %d \n", ft_printf("%*s", -32, "abc"));
	printf("CARACTERES: %d \n\n", printf("%*s", -32, "abc"));
	printf("CARACTERES: %d \n", ft_printf("%-*s", -32, "abc"));
	printf("CARACTERES: %d \n\n", printf("%-*s", -32, "abc"));
	printf("CARACTERES: %d \n", ft_printf("%-*.*s", -7, -3, "yolo"));
	printf("CARACTERES: %d \n\n", printf("%-*.*s", -7, -3, "yolo"));*/
/*	printf("CARACTERES: %d \n", ft_printf("%*i", -14, 94827));
	printf("CARACTERES: %d \n\n", printf("%*i", -14, 94827));
	printf("CARACTERES: %d \n", ft_printf("%10.5i", -216));
	printf("CARACTERES: %d \n\n", printf("%10.5i", -216));
	printf("CARACTERES: %d \n", ft_printf("%0-10.5d", -216));
	printf("CARACTERES: %d \n\n", printf("%0-10.5d", -216));
	printf("CARACTERES: %d \n", ft_printf("%0*i", -7, -54));
	printf("CARACTERES: %d \n\n", printf("%0*i", -7, -54));
	printf("CARACTERES: %d \n", ft_printf("%0*d", -10, 42));
	printf("CARACTERES: %d \n\n", printf("%0*d", -10, 42));
	printf("CARACTERES: %d \n", ft_printf("%*.*d", 0, 0, 0));
	printf("CARACTERES: %d \n\n", printf("%*.*d", 0, 0, 0));*/

	printf("CARACTERES: %d \n", ft_printf("%01.10x", -1));
	printf("CARACTERES: %d \n\n", printf("%01.10x", -1));
	printf("CARACTERES: %d \n", ft_printf("%02.2x", -1));
	printf("CARACTERES: %d \n\n", printf("%02.2x", -1));

//	printf("CARACTERES: %d \n", ft_printf("%.s", 42));
//	printf("CARACTERES: %d \n\n", printf("%.s", 42));














//	printf("CARACTERES: %d \n", ft_printf("numero: %d, letra: %c, hexadec: %x, string: %s", 69, 'A', 6969, "mierda"));
//	printf("\n-1-\n");
//	printf("\n flagW-width: |%d|%d| - flagP-precision: |%d|%d| -\n", f->flag_width, f->width, f->flag_precision, f->precision);

}

