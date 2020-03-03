/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:12:54 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 22:31:13 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(t_flag *f)
{
	f->flag_width = 0;
	f->width = 0;
	f->flag_precision = 0;
	f->precision = 0;
	f->minus_width = 0;
	f->minus_precision = 0;
	f->space_zero = ' ';
}

void	subtracta(t_flag *f)
{
	if (f->width < 0)
		f->minus_width = 1;
	if (f->precision < 0)
		f->minus_precision = 1;
}

void	compare_minus(t_flag *f)
{
	if (f->minus == 1)
	{
		f->len += write(1, "-", 1);
		f->minus = 0;
	}
}

void	stranger_things(t_flag *f)
{
	if (f->flag_width == 1)
	{
		if (f->minus_width == 1)
		{
			f->len += write(1, "%", 1);
			str_width(f, 1);
		}
		else
		{
			str_width(f, 1);
			f->len += write(1, "%", 1);
		}
	}
	else
		f->len += write(1, "%", 1);
}
