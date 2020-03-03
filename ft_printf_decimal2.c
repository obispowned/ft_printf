/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:34:25 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 21:35:36 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		decimal_width(t_flag *f, int len)
{
	int		i;
	int		aux;

	i = 0;
	aux = len;
	if (f->space_zero == '0' && f->minus == 1)
	{
		f->len += write(1, "-", 1);
		f->minus = 0;
	}
	if (f->space_zero == '0' && f->width < 0)
		f->space_zero = ' ';
	if (f->width > f->precision && f->width > aux)
	{
		i = f->width;
		if (f->minus_width == 1 && !f->flag_precision)
			f->space_zero = ' ';
		while ((i > f->precision && i > aux))
		{
			f->len += write(1, &f->space_zero, 1);
			i--;
		}
	}
}

void		decimal_precision(t_flag *f, int len)
{
	int		aux;

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

void		print_decimal(t_flag *f, char *aux)
{
	int		i;
	int		lenght;
	int		atoizador;

	atoizador = ft_atoi(aux);
	i = 0;
	lenght = ft_strlen(aux);
	if (f->flag_precision && f->precision == 0 && atoizador == 0 && !f->width)
		write(1, "", 0);
	else if (f->flag_precision && f->precision == 0 && atoizador == 0)
		f->len += write(1, " ", 1);
	else
	{
		while (i < lenght)
		{
			write(1, &aux[i], 1);
			i++;
			f->len++;
		}
	}
}
