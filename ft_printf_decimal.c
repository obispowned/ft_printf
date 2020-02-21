/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:22:22 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/18 14:23:50 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	comprobar_decimal(t_flag f)
{
	int		len;
	int		argumento;
	char 	*aux;

	argumento = va_arg(f.args, int);			//METEMOS EN STR EL ARGUMENTO
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
}
