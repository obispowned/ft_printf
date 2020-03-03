/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:14:02 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 20:36:24 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		comprobar_string(t_flag *f)
{
	int		len;
	char	*str;

	str = va_arg(f->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (f->flag_width == 1)
	{
		if (f->minus_width == 1)
		{
			print_string(f, str);
			str_width(f, len);
		}
		else
		{
			str_width(f, len);
			print_string(f, str);
		}
	}
	else
		print_string(f, str);
}

void		str_width(t_flag *f, int len)
{
	int		i;
	int		aux;

	i = 0;
	aux = len;
	if (f->flag_precision && f->precision >= 0 && f->precision < aux)
		aux = f->precision;
	if (f->flag_width)
	{
		if (f->width < 0)
			f->width *= -1;
		while (i < (f->width - aux))
		{
			write(1, &f->space_zero, 1);
			f->len++;
			i++;
		}
	}
}

void		print_string(t_flag *f, char *str)
{
	int		i;
	int		aux;

	i = 0;
	if (str)
		aux = ft_strlen(str);
	else
		aux = 6;
	if (f->flag_precision && f->precision >= 0 && f->precision < aux)
		aux = f->precision;
	while (i < aux)
	{
		write(1, &str[i], 1);
		i++;
		f->len++;
	}
}
