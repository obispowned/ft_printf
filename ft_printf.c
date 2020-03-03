/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:01:01 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 22:34:49 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_flag	f;

	f.len = 0;
	f.i = 0;
	reset_flags(&f);
	va_start(f.args, format);
	if (ft_strchr(format, '%'))
	{
		comprobar_percent(format, &f);
	}
	else
	{
		ft_putstr(format);
		f.len = ft_strlen(format);
	}
	va_end(f.args);
	return (f.len);
}

void		comprobar_percent(const char *format, t_flag *f)
{
	while (format[f->i] != '\0')
	{
		if (format[f->i] == '%' && format[f->i + 1] != '\0')
		{
			reset_flags(f);
			f->i++;
			while ((format[f->i] == '0' && format[f->i + 1] == '-') ||
			(format[f->i] == '0' && format[f->i + 1] == '0'))
				f->i++;
			if (format[f->i] == '0')
				f->space_zero = '0';
			comprobar_percent2(format, f);
		}
		else
			f->len += write(1, &format[f->i], 1);
		f->i++;
	}
}

void		comprobar_percent2(const char *format, t_flag *f)
{
	if (format[f->i] == '-' || format[f->i] == '.' ||
	format[f->i] == '*' || (format[f->i] > 47 && format[f->i] < 58))
	{
		if (format[f->i + 1] != '\0')
		{
			if (format[f->i] == '-')
			{
				f->minus_width = 1;
				f->i++;
			}
			comprobar_flag(format, f);
		}
	}
	if (format[f->i] == 'd' || format[f->i] == 'u' ||
	format[f->i] == 'f' || format[f->i] == 'x' ||
	format[f->i] == 'X' || format[f->i] == 'o' ||
	format[f->i] == 's' || format[f->i] == 'c' ||
	format[f->i] == 'p' || format[f->i] == 'i')
		comprobar_formato(format, f);
	else
		stranger_things(f);
}

void		comprobar_flag(const char *format, t_flag *f)
{
	if ((format[f->i] > 47 && format[f->i] < 58) ||
	format[f->i] == 42 || format[f->i] == 46)
	{
		while ((format[f->i] > 47 && format[f->i] < 58) || format[f->i] == 42)
		{
			f->flag_width = 1;
			if (format[f->i] == 42)
			{
				f->width = va_arg(f->args, int);
				subtracta(&(*f));
				f->i++;
			}
			else
				calculo_width(format, f);
		}
		comprobar_flag2(format, f);
	}
}

void		comprobar_flag2(const char *format, t_flag *f)
{
	if (format[f->i] == 46)
	{
		f->flag_precision = 1;
		f->space_zero = ' ';
		f->i++;
		if (format[f->i] == '-')
		{
			f->minus_width = 1;
			f->i++;
		}
		while ((format[f->i] > 47 && format[f->i] < 58) ||
		format[f->i] == 42)
		{
			if (format[f->i] == 42)
			{
				f->precision = va_arg(f->args, int);
				subtracta(&(*f));
				f->i++;
			}
			else
			{
				calculo_precision(format, f);
			}
		}
	}
}
