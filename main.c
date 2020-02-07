/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:22:09 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/05 19:34:08 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

			/*****************************************************/
			/* EJEMPLOS PARA CONOCER EL FUNCIONAMIENTO DE PRINTF */
			/*****************************************************/

#include <stdio.h>

int		main()
{
	printf("EJEMPLO DE WIDTH 5 Y PRECISION 3 PARA STRING = HOLA: %5.3s\n", "hola");
	printf("EJEMPLO DE WIDHT 0 Y PRECISION 5 PARA STRING = PEPITO69: %5s\n", "pepito69");
	printf("EJEMPLO DE WIDTH 8 Y PRECISION 0 PARA STRING = ALCAPONErt: %8.0s\n", "ALCAPONErt");
	printf("EEEEEEJ con solo UN NUMERO DETRAS DEL 2 HOLA - 6 HOLA %2s\n - %6s\n", "hola", "hola");
	printf("EJEMPLO DE WIDTH * Y PRECISION * PARA STRING = PATROCLO22: %*.*s\n\n\n",2,2, "patroclo22");

	printf("VAMOS CON ENTEROS\n\n");

	printf("EJEMPLO DE WIDTH 5 Y PRECISION 5 PARA INT = 15987: %5.5d\n", 15987);
	printf("EJEMPLO DE WIDHT 0 Y PRECISION 5 PARA INT = 564982: %0.5d\n", 564982);
	printf("EJEMPLO DE WIDTH 8 Y PRECISION 0 PARA INT = 698235714: %8.0d\n", 698235714);
	printf("EJEMPLO DE WIDTH * Y PRECISION * PARA INT = 1359724: %*.*d\n\n",1,1, 1359724);
}
