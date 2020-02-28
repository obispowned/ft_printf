/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:32:36 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/25 20:16:09 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						point_width(t_flag *f, int i)
{
	int						w;
	int						p;

	p = f->precision;
	w = f->width;
	i += 2;  //OJO QUE LO MISMO TENEMOS QUE SUMAR SOLO 1

	while (w > i || p > i)
	{
		if (w > f->precision)
			f->len += write(1, " ", 1);
		else
			f->len += write(1, "0", 1);
		w--;
		p--;
	}
}


void						point_convert(t_flag *f, char *dighex, unsigned long long int argumento)
{
	char					*hexaprint;
	int						resto;
	int						i;
	int						j;
	long long int			y;
	int						h;

	y = (long long int)argumento;
	h = 0;
	while (y > 0)
	{
		y = y / 16;
		h++;
	}
	hexaprint = malloc(h);
	i = 0;
	while (argumento > 0)
	{
		resto = argumento % 16;
		hexaprint[i] = dighex[resto];
		argumento = argumento / 16;
		i++;
	}
	if (f->flag_width == 1)
		point_width(f, i);
	j = i - 1;
	f->len += (int)write(1, "0x", 2);
	while (j >= 0)
	{
		f->len += write(1, &hexaprint[j], 1);
		j--;
	}
	free(hexaprint);
}

void							comprobar_puntero(t_flag *f)
{
	unsigned long long int		argumento;

	argumento = va_arg(f->args, unsigned long long int);
	point_convert(f, "0123456789abcdef", argumento);
}
