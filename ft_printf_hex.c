/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:22:55 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/21 15:43:07 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	hexa_width(t_flag *f, int l)
{
	int	i;

	i = f->width;
	while (i > l)
	{
		if (i > f->precision)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		i --;
		f->len++;
	}
}

void	hexa_convert(t_flag *f, char *digHex, unsigned int argumento)
{
	char 	*hexaPrint;
	int		resto;
	int		i;
	int		j;


	i = 0;
	while (argumento > 0)
	{
		resto = argumento % 16;
		hexaPrint[i] = digHex[resto];
		argumento = argumento / 16;
		i++;
	}
	if (f->flag_width == 1)
		hexa_width(&(*f), i);
	j = i - 1;
	while (j >= 0)
	{
		write(1, &hexaPrint[j], 1);
		f->len++;
		j--;
	}

}

void	comprobar_hex(t_flag f)
{
	int					len;
	unsigned int		argumento;

	argumento = va_arg(f.args, unsigned int);
	hexa_convert(&f, "0123456789abcdef", argumento);
}


/********************************/

/*void	comprobar_hex(t_flag *f)
{
	int					len;
	unsigned int		argumento;

	argumento = va_arg(f->args, unsigned int);
	hex_convert (&(*f), argumento);
}

void 	hex_convert(t_flag *f, unsigned int argumento)
{
	char *digHex;
	char *hexaPrint;
	unsigned int resto;
	int i;

	digHex = "0123456789ABCDEF";
	i = 0;
	while (argumento > 0)
	{
		resto = (argumento % 16) * 16;
		hexaPrint[i] = digHex[resto];
		argumento = argumento / 16;
		i++;
	}
	hexaPrint[i] = '\0';
	if (f->flag_width == 1)
		hexa_width(&(*f), i);
	hex_printer(&(*f), argumento, i, hexaPrint);
}

void 	hexa_width(t_flag *f, int l)
{
	int	i;
	int aux;

	i = 0;
	aux = l;
	if (f->flag_precision && f->precision > aux)
	{
		if (f->width > f->precision)
		{
			i = f->width;
			while (i > f->precision)
			{
				write(1, " ", 1);
				i--;
				f->len++;
			}
		}
	}
	while (aux < f->precision)
	{
		write(1, "0", 1);
		aux++;
		f->len++;
	}
}

void	hex_printer(t_flag *f, unsigned int argumento, int i, char *hexaPrint)
{
	int j;

	j = i-1;
	while (j >= 0)
	{
		write(1, &hexaPrint[j], 1);
		f->len++;
		j--;
	}
}*/

/*****************************************************/

/*void	comprobar_hex(t_flag f)
{
	int					len;
	unsigned int		argumento;

	argumento = va_arg(f.args, unsigned int);
	hex_printer(&f, argumento);

}

void	hex_printer(t_flag *f, unsigned int argumento)
{
	char *digHex;
	char *hexaPrint;
	unsigned int resto;
	int i;
	int j;

	digHex = "0123456789abcdef";
	i = 0;
	while (argumento > 0)
	{
		resto = argumento % 16;
		hexaPrint[i] = digHex[resto];
		argumento = argumento / 16;
		i++;
	}
	j = i-1;
	while (j >= 0)
	{
		write(1, &hexaPrint[j], 1);
		f->len++;
		j--;
	}
}*/
