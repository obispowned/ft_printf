/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:52:21 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 20:34:03 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		comprobar_char(t_flag *f)
{
	char	chr;

	chr = va_arg(f->args, int);
	if (f->flag_width == 1)
	{
		if (f->minus_width == 1)
		{
			f->len += write(1, &chr, 1);
			chr_width(f);
		}
		else
		{
			chr_width(f);
			f->len += write(1, &chr, 1);
		}
	}
	else
		f->len += write(1, &chr, 1);
}

void		chr_width(t_flag *f)
{
	int		i;

	if (f->width < 0)
	{
		i = -1;
		while (i > f->width)
		{
			f->len += write(1, &f->space_zero, 1);
			i--;
		}
	}
	else if (f->width > 0)
	{
		i = 1;
		while (i < f->width)
		{
			f->len += write(1, &f->space_zero, 1);
			i++;
		}
	}
}
