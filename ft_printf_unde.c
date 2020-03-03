/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unde.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:41:33 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 21:45:09 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					comprobar_undecimal(t_flag *f)
{
	int					len;
	unsigned int		argumento;
	char				*aux;

	argumento = va_arg(f->args, unsigned int);
	aux = ft_itoa(argumento);
	len = ft_strlen(aux);
	if (f->flag_width == 1)
	{
		comprobar_undecimal2(f, aux, len);
	}
	else if (f->flag_precision && !f->flag_width)
	{
		decimal_precision(f, len);
		print_decimal(f, aux);
	}
	else
		print_decimal(f, aux);
}

void					comprobar_undecimal2(t_flag *f, char *aux, int len)
{
	if (f->minus_width == 1)
	{
		undecimal_precision(f, len);
		print_undecimal(f, aux);
		undecimal_width(f, len);
	}
	else
	{
		undecimal_width(f, len);
		undecimal_precision(f, len);
		print_undecimal(f, aux);
	}
}

void					undecimal_width(t_flag *f, int len)
{
	int					i;
	int					aux;

	i = 0;
	aux = len;
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

void					undecimal_precision(t_flag *f, int len)
{
	int					aux;

	aux = len;
	while (aux < f->precision)
	{
		write(1, "0", 1);
		aux++;
		f->len++;
	}
}

void					print_undecimal(t_flag *f, char *aux)
{
	int					i;
	int					lenght;
	int					atoizador;

	atoizador = ft_atoi(aux);
	i = 0;
	lenght = ft_strlen(aux);
	if (f->flag_precision && f->precision == 0 &&
	atoizador == 0 && !f->flag_width)
		write(1, "", 0);
	else if (f->flag_precision && f->precision == 0 && atoizador == 0)
		f->len += write(1, " ", 1);
	else
	{
		while (i < lenght)
		{
			f->len += write(1, &aux[i], 1);
			i++;
		}
	}
}
