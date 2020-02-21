/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:24:12 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/21 15:22:09 by agutierr         ###   ########.fr       */
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

	ft_printf("\n\n****** CHAR ******\n");

	ft_printf("mi char 9c: -%9c-\n", c);
	printf("char 9c :   -%9c-\n\n", c);
	ft_printf("mi char -5c: -%-5c-\n", c);
	printf("char -5c  :  -%-5c-\n\n", c);
	ft_printf("mi char 4c: -%4c-\n", c);
	printf("char 4c :   -%4c-\n\n", c);
	ft_printf("mi char *c10: -%*c-\n", 10, c);
	printf("char  *c10:   -%*c-\n\n", 10, c);
	ft_printf("mi char *c-10: -%*c-\n", -10, c);
	printf("char  *c-10:   -%*c-\n\n", -10, c);
	ft_printf("mi char *c-5: -%*c-\n", -5, c);
	printf("char  *c-5:   -%*c-\n\n", -5, c);
	ft_printf("mi char *c-20: -%*c-\n", -20, c);
	printf("char  *c-20:   -%*c-\n\n", -20, c);

	ft_printf("\n\n****** STRINGS ******\n");

	ft_printf("mi printf   15s: %*.*s\n",11, 1, a);
	printf("oficial con 15s: %*.*s\n\n",11, 1, a);
	ft_printf("mi printf   15s: %9.3s\n", a);
	printf("oficial con 15s: %9.3s\n\n", a);

	ft_printf("\n\n****** INT ******\n");

	ft_printf("MI int con 9.7: %9.7d\n", j);
	printf("int con 9.7   : %9.7d\n\n", j);
	ft_printf("MI int con 7.9: %7.9d\n", j);
	printf("int con 7.9   : %7.9d\n\n", j);

	ft_printf("\n\n****** HEX ******\n");

	ft_printf("HEXADECIMAL: %x\n", 4779);
	printf("oficial HEXADECIMAL: %x\n\n", 4779);


	printf("oficialHEXADECIMAL 6.6: %6.6x\n\n", 2323);
	ft_printf("HEXADECIMAL 6.6: %6.6x\n", 2323);
	/*ft_printf("HEXADECIMAL 3.9: %3.9x\n", 6969);
	printf("oficialHEXADECIMAL 3.9: %3.9x\n\n", 6969);
	ft_printf("HEXADECIMAL 9.3: %9.3x\n", 111);
	printf("oficialHEXADECIMAL 9.3: %9.3x\n\n", 111);

	ft_printf("\n\n****** UN-HEX ******\n");

	ft_printf("UN-HEXADECIMAL: %X\n", 1598);
	printf("oficial-UN-HEXADECIMAL: %X\n\n", 1598);

	ft_printf("\n\n****** PUNTEROS ******\n");

	ft_printf("punteros p: -%p-\n", p);
	printf("OFIpunteros p: -%p-\n\n", p);

	ft_printf("\n\n****** UNSIGNED ******\n");

	printf("\nUNSIGNED %u\n", -30);*/
}

