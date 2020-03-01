/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:32:36 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/01 20:28:09 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				comprobar_pointer(t_flag *f, char *digits)
{
	unsigned long int	argumento;
	unsigned long int	resto;
	int				i;

	argumento = va_arg(f->args, unsigned long int);
	resto = argumento;
	i = 0;
	while (resto > 0)
	{
		resto = resto / 16;
		i++;
	}
	if((f->precision < f->width && argumento) || (f->flag_precision && !f->precision && !argumento))   //quitarlo o CAMBIAR CONDICION
		i += 2;
	else if (argumento == 0 && !f->flag_precision && !f->precision)
		i += 3;
	if (f->flag_width == 1)
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



/****************************************************************/

void		print_pointer(t_flag *f, char *dighex, unsigned long int argumento)
{
	char				*hexaprint;
	unsigned long int	resto;
	int		i;
	unsigned long int	arg;

	resto = argumento;
	arg = argumento;
	i = 0;
	while (resto > 0)
	{
		resto = resto / 16;
		i++;
	}
	hexaprint = malloc(i);
	i = 0;
	while (argumento > 0)
	{
		resto = argumento % 16;
		hexaprint[i++] = dighex[resto];
		argumento = argumento / 16;
	}
	i = i - 1;
	if (arg == 0 && !f->flag_precision)
		f->len += write(1, "0", 1);
	while (i >= 0)
		f->len += write(1, &hexaprint[i--], 1);
	free(hexaprint);
}

/****************************************************************/

void	pointer_width(t_flag *f, int i)
{
	int	j;
	int	z;

	j = 0;
	z = i;

	if (f->width > f->precision && f->width > z)
	{
		j = f->width;
		while (j > f->precision && j > z)
		{
			f->len += write(1, &f->space_zero, 1);
			j--;
		}
	}
}

/****************************************************************/

void	pointer_precision(t_flag *f, int i)
{
	int z;

	z = i;
	while (z < f->precision)
	{
		f->len += write(1, "0", 1);
		z++;
	}
}
