/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unde.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:41:33 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/25 18:35:44 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	comprobar_undecimal(t_flag *f)
{
	int		len;
	unsigned int		argumento;
	char 	*aux;

	argumento = va_arg(f->args, unsigned int);			//METEMOS EN STR EL ARGUMENTO
	aux = ft_itoa(argumento);
	len = ft_strlen(aux);					//GUARDAMOS EN LEN EL TAMAÑO DEL ARGUMENTO (que esta en str)
	if (f->flag_width == 1)
		undecimal_width(f, len);			//PARA IMPRIMIR LOS ESPACIOS Y TENER EN CUENTA LOS FLAG
	print_undecimal(f, aux);
}

void	undecimal_width(t_flag *f, int len)
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
				f->len += write(1, " ", 1);
				i--;
			}
		}
	}
	while (aux < f->precision)
	{
		f->len += write(1, "0", 1);
		aux++;
	}
}

void	print_undecimal(t_flag *f, char *aux)
{
	int i;
	int lenght;

	i = 0;
	lenght = ft_strlen(aux);
	while (i < lenght)
	{
		f->len += write(1, &aux[i], 1); //STR LO HEMOS IGUALADO AL ARGUMENTO QUE REFERENCIA NUESTRO FLAG
		i++;
	}
}
