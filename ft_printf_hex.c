/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:22:55 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/28 20:41:24 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		hexa_width(t_flag *f, int i)
{
	int		w;
	int		p;

	p = f->precision;
	w = f->width;

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


void			hexa_convert(t_flag *f, char *dighex, unsigned int argumento)
{
	char		*hexaprint;
	int			resto;
	int			i;
	int			j;
	int			y;
	int			h;

	y = argumento;
	h = 0;
	while (y > 0)
	{
		y = y / 16;
		h++;
	}
	y = argumento;
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
		hexa_width(&(*f), i);
	j = i - 1;
	while (j >= 0)
	{
		f->len += write(1, &hexaprint[j], 1);
		j--;
	}
	free(hexaprint);
}

void	comprobar_hex(t_flag *f, char *digits)
{
	unsigned int		argumento;

	argumento = va_arg(f->args, unsigned int);
	hexa_convert(f, digits, argumento);
}
