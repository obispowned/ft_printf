/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:22:22 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/28 22:37:21 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	comprobar_decimal(t_flag *f)
{
	int		len;
	int		a;
	char 	*aux;

	f->minus = 0;
	a = va_arg(f->args, int);			//METEMOS EN STR EL ARGUMENTO
	if (a < 0)
	{
		f->minus = 1;
		a *= -1;
		f->width--;
	}
	aux = ft_itoa(a);
	len = ft_strlen(aux);					//GUARDAMOS EN LEN EL TAMAÑO DEL ARGUMENTO (que esta en str)
	if (f->flag_width == 1)
	{
		if (f->minus_width == 1)				//WIDTH NEGATIVO
		{
			if (f->minus == 1)
			{
				f->len += write(1, "-", 1);
				f->minus = 0;
			}
			decimal_precision(f, len);
			print_decimal(f, aux);
			decimal_width(f, len);
		}
		else
		{
			decimal_width(f, len);		//WIDTH POSITIVO
			if (f->minus == 1)
			{
				f->len += write(1, "-", 1);
				f->minus = 0;
			}
			decimal_precision(f, len);
			print_decimal(f, aux);
		}
	}

	else if (f->flag_precision && !f->flag_width)
	{
		decimal_precision(f, len);
		print_decimal(f, aux);
	}
	else
	{
		if (f->minus == 1)
		{
			f->len += write(1, "-", 1);
			f->minus = 0;
		}
		print_decimal(f, aux);
	}
}
/********************************************************************************************/
void	decimal_width(t_flag *f, int len)
{
	int	i;
	int aux;

	i = 0;
	aux = len;
	if (f->space_zero == '0' && f->minus == 1)
	{
		f->len += write(1, "-", 1);
		f->minus = 0;
	}
	if (f->width > f->precision && f->width > aux)
	{
		i = f->width;
		while (i > f->precision && i > aux)
		{
			f->len += write(1, &f->space_zero, 1);
			i--;
		}
	}
}
/********************************************************************************************/
void	decimal_precision(t_flag *f, int len)
{
	int aux;

	aux = len;
	if (f->space_zero == ' ' && f->minus == 1 && f->minus_width == 0)
	{
		f->len += write(1, "-", 1);
		f->minus = 0;
	}
	while (aux < f->precision)
	{
		write(1, "0", 1);
		aux++;
		f->len++;
	}
}
/********************************************************************************************/
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
