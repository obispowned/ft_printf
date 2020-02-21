/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:52:21 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/18 21:49:14 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"


void	comprobar_char(t_flag f)
{
	char	chr;

	chr = va_arg(f.args, int);			//METEMOS EN STR EL ARGUMENTO
	if (f.flag_width == 1)
	{
		if (f.minus_width == 1)
		{
			print_chr(&f, chr);
			f.width *= -1;
			chr_width(&f);
		}
		else
		{
			chr_width(&f);
			print_chr(&f, chr);
		}
	}
	else
		print_chr(&f, chr);
}

void	chr_width(t_flag *f)
{
	int	i;

	i = 1;
	while (i < f->width)
	{
		write(1, " ", 1);
		i++;
		f->len++;
	}
}

void	print_chr(t_flag *f, char chr)
{
	write(1, &chr, 1);
	f->len++;
}
