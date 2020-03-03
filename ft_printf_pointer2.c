/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:05:02 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 22:08:05 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					pointer_width(t_flag *f, int i)
{
	int					j;
	int					z;

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

void					pointer_precision(t_flag *f, int i)
{
	int					z;

	z = i;
	while (z < f->precision)
	{
		f->len += write(1, "0", 1);
		z++;
	}
}

void					print_pointer(t_flag *f,
char *dighex, unsigned long int argumento)
{
	char				*hexaprint;
	unsigned long int	resto;
	int					i;
	unsigned long int	arg;

	resto = argumento;
	arg = argumento;
	i = 0;
	if (resto > 0)
		i = print_pointer2(resto, i);
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

int						print_pointer2(unsigned long long resto, int i)
{
	while (resto > 0)
	{
		resto = resto / 16;
		i++;
	}
	return (i);
}
