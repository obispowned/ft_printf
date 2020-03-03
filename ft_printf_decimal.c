/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:22:22 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 21:34:45 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		comprobar_decimal(t_flag *f)
{
	int		len;
	int		a;
	char	*aux;

	f->minus = 0;
	a = va_arg(f->args, int);
	if (f->width < 0 && a < 0)
		f->space_zero = ' ';
	if (f->width < 0)
		f->width *= -1;
	if (a < 0)
	{
		f->minus = 1;
		a *= -1;
		f->width--;
	}
	aux = ft_itoa(a);
	len = ft_strlen(aux);
	comprobar_decimal2(f, aux, len);
}

void		comprobar_decimal2(t_flag *f, char *aux, int len)
{
	if (f->flag_width == 1)
	{
		comprobar_decimal3(f, aux, len);
	}
	else if (f->flag_precision && !f->flag_width)
	{
		decimal_precision(f, len);
		print_decimal(f, aux);
	}
	else
	{
		compare_minus(f);
		print_decimal(f, aux);
	}
}

void		comprobar_decimal3(t_flag *f, char *aux, int len)
{
	if (f->minus_width == 1)
	{
		compare_minus(f);
		decimal_precision(f, len);
		print_decimal(f, aux);
		decimal_width(f, len);
	}
	else
	{
		decimal_width(f, len);
		compare_minus(f);
		decimal_precision(f, len);
		print_decimal(f, aux);
	}
}
