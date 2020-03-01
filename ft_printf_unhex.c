/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:10:07 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/01 16:47:34 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				comprobar_unhex(t_flag *f, char *digits)
{
	unsigned int	argumento;
	int				resto;
	int				i;

	argumento = va_arg(f->args, unsigned int);
	resto = argumento;
	i = 0;
	while (resto > 0)
	{
		resto = resto / 16;
		i++;
	}
	if (argumento == 0 && !f->precision && !f->flag_precision)
		i = 1;
	if (f->flag_width == 1)
	{
		if (f->minus_width == 1)
		{
			unhexa_precision(f, i);
			print_unhexa(f, digits, argumento);
			unhexa_width(f, i);
		}
		else
		{
			unhexa_width(f, i);
			unhexa_precision(f, i);
			print_unhexa(f, digits, argumento);
		}
	}
	else if (f->flag_precision && !f->flag_width)
	{
		unhexa_precision(f, i);
		print_unhexa(f, digits, argumento);
	}
	else
		print_unhexa(f, digits, argumento);
}



/****************************************************************/

void		print_unhexa(t_flag *f, char *dighex, unsigned int argumento)
{
	char	*hexaprint;
	int		resto;
	int		i;

	if	(argumento == 0 && !f->precision && !f->flag_precision)
		f->len += write(1, "0", 1);
	resto = argumento;
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
	while (i >= 0)
		f->len += write(1, &hexaprint[i--], 1);
	free(hexaprint);
}

/****************************************************************/

void	unhexa_width(t_flag *f, int i)
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

void	unhexa_precision(t_flag *f, int i)
{
	int z;

	z = i;
	while (z < f->precision)
	{
		f->len += write(1, "0", 1);
		z++;
	}
}
