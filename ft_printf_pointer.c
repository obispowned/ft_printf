/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:32:36 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/21 12:21:52 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*# include "ft_printf.h"

void	comprobar_puntero(t_flag f)
{
	int					len;
	unsigned int		argumento;

	argumento = va_arg(f.args, unsigned int);
	printf ("IMPRIME ARGUMENTO %u", argumento);
	pointer_printer(&f, argumento);

}

void	pointer_printer(t_flag *f, unsigned int argumento)
{
	char *digHex;
	char *hexaPrint;
	unsigned int resto;
	int i;
	int j;

	digHex = "0123456789ABCDEF";
	i = 0;
	while (argumento > 0)
	{
		resto = argumento % 16;
		hexaPrint[i] = digHex[resto];
		argumento = argumento / 16;
		i++;
	}
	j = i-1;
	write(1,"0x",2);
	while (j >= 0)
	{
		write(1, &hexaPrint[j], 1);
		f->len++;
		j--;
	}
}*/

/***********************************************************/

/*void	comprobar_puntero(t_flag f)
{
	int					len;
	unsigned long int	argumento;
	char 				*aux;

	argumento = va_arg(f.args, unsigned long int);			//METEMOS EN STR EL ARGUMENTO
	aux = ft_itoa(argumento);
	len = ft_strlen(aux);					//GUARDAMOS EN LEN EL TAMAÑO DEL ARGUMENTO (que esta en str)
	if (f.flag_width == 1)
		decimal_width(&f, len);			//PARA IMPRIMIR LOS ESPACIOS Y TENER EN CUENTA LOS FLAG
	print_decimal(&f, aux);
}

void	decimal_width(t_flag *f, int len)
{
	int	i;
	int aux;

	i = 0;
	aux = len;
	if (f->flag_precision && f->precision > aux)
	{
		if (f->width > f->precision)
		{
			i = f->width;
			while (i > f->precision)
			{
				write(1, " ", 1);
				i--;
				f->len++;
			}
		}
	}
	while (aux < f->precision)
	{
		write(1, "0", 1);
		aux++;
		f->len++;
	}
}

void	print_decimal(t_flag *f, char *aux)
{
	int i;
	int lenght;

	i = 0;
	lenght = ft_strlen(aux);
	while (i < lenght)
	{
		write(1, &aux[i], 1); //STR LO HEMOS IGUALADO AL ARGUMENTO QUE REFERENCIA NUESTRO FLAG
		i++;
		f->len++;
	}
}*/
