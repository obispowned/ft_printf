/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:32:36 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 22:08:07 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					comprobar_pointer(t_flag *f, char *digits)
{
	unsigned long int	argumento;
	unsigned long int	resto;
	int					i;

	argumento = va_arg(f->args, unsigned long int);
	resto = argumento;
	i = 0;
	while (resto > 0)
	{
		resto = resto / 16;
		i++;
	}
	if ((f->precision < f->width && argumento) ||
	(f->flag_precision && !f->precision && !argumento))
		i += 2;
	else if (argumento == 0 && !f->flag_precision && !f->precision)
		i += 3;
	comprobar_pointer2(f, digits, argumento, i);
}

void					comprobar_pointer2(t_flag *f,
char *digits, unsigned long int argumento, int i)
{
	if (f->flag_width == 1)
	{
		comprobar_pointer3(f, digits, argumento, i);
	}
	else if (f->flag_precision && !f->flag_width)
	{
		f->len += write(1, "0x", 2);
		pointer_precision(f, i);
		print_pointer(f, digits, argumento);
	}
	else
	{
		f->len += write(1, "0x", 2);
		print_pointer(f, digits, argumento);
	}
}

void					comprobar_pointer3(t_flag *f,
char *digits, unsigned long int argumento, int i)
{
	if (f->minus_width == 1)
	{
		f->len += write(1, "0x", 2);
		pointer_precision(f, i);
		print_pointer(f, digits, argumento);
		pointer_width(f, i);
	}
	else
	{
		if (f->precision > f->width)
			f->len += write(1, "0x", 2);
		pointer_width(f, i);
		if (f->width > f->precision)
			f->len += write(1, "0x", 2);
		pointer_precision(f, i);
		print_pointer(f, digits, argumento);
	}
}
