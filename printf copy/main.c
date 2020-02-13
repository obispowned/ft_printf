/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:24:12 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/13 17:25:02 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	char *a = "hola";

	ft_printf("mi printf   15s: %5.1s\n", a);
	printf("oficial con 15s: %5.1s\n\n", a);
	/*printf("prueba con 8 de with: %8.10d\n", i);
	printf("prueba con 10 de with: %10.2d\n", i);
	printf("prueba con 2 de with: %-6s\n", a);
	printf("prueba con 4 de with: %4.2s\n", a);
	printf("prueba con 15 de with: %15.1s\n", a);

	ft_printf("prueba con 8 de with: %8.10d\n", i);
	ft_printf("prueba con 10 de with: %10.2d\n", i);
	ft_printf("prueba con 2 de with: %-6s\n", a);
	ft_printf("prueba con 4 de with: %4.2s\n", a);
	ft_printf("prueba con 15 de with: %15.1s\n", a);*/

}
