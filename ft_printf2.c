/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:33:27 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 22:34:14 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		calculo_width(const char *format, t_flag *f)
{
	int						j;
	int						l;
	char					*str;

	l = 0;
	j = f->i;
	while (format[j] > 47 && format[j] < 58)
	{
		j++;
		l++;
	}
	j = 0;
	str = malloc(l + 1);
	while (format[f->i] > 47 && format[f->i] < 58)
	{
		str[j] = format[f->i];
		j++;
		f->i++;
	}
	str[j] = '\0';
	if (f->flag_width == 1)
		f->width = ft_atoi(str);
	free(str);
}

void		calculo_precision(const char *format, t_flag *f)
{
	int		j;
	int		l;
	char	*str;

	l = 0;
	j = f->i;
	while ((format[j] > 47) && (format[j] < 58))
	{
		j++;
		l++;
	}
	j = 0;
	str = malloc(l + 1);
	while (format[f->i] > 47 && format[f->i] < 58)
	{
		str[j] = format[f->i];
		j++;
		f->i++;
	}
	str[j] = '\0';
	if (f->flag_precision == 1)
		f->precision = ft_atoi(str);
	free(str);
}

void		comprobar_formato(const char *format, t_flag *f)
{
	if (format[f->i] == 'd' || format[f->i] == 'i')
		comprobar_decimal(f);
	if (format[f->i] == 'x')
		comprobar_hex(f, "0123456789abcdef");
	if (format[f->i] == 'X')
		comprobar_unhex(f, "0123456789ABCDEF");
	if (format[f->i] == 'u')
		comprobar_undecimal(f);
	if (format[f->i] == 'c')
		comprobar_char(f);
	if (format[f->i] == 's')
		comprobar_string(f);
	if (format[f->i] == 'p')
		comprobar_pointer(f, "0123456789abcdef");
}
