/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:14:02 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/17 18:15:30 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	comprobar_string(t_flag f)
{
	int		len;
	char	*str;

	str = va_arg(f.args, char *);			//METEMOS EN STR EL ARGUMENTO
	len = ft_strlen(str);					//GUARDAMOS EN LEN EL TAMAÑO DEL ARGUMENTO (que esta en str)
	if (f.flag_width == 1)
		str_width(&f, len);			//PARA IMPRIMIR LOS ESPACIOS Y TENER EN CUENTA LOS FLAG
	print_string(&f, str);
}

void	str_width(t_flag *f, int len)
{
	int	i;
	int aux;

	i = 0;
	aux = len;
	if (f->flag_precision && f->precision >= 0 && f->precision < aux)
		aux = f->precision;
	if (f->width > 0)
	{
		while (i < (f->width - aux))
		{
			write(1, " ", 1);
			i++;
			f->len++;
		}
	}
}

void	print_string(t_flag *f, char *str)
{
	int i;
	int aux;

	i = 0;
	aux = ft_strlen(str);
	if (f->flag_precision && f->precision >= 0 && f->precision < aux)
		aux = f->precision;
	while(i < aux)
	{
		write(1, &str[i], 1); //STR LO HEMOS IGUALADO AL ARGUMENTO QUE REFERENCIA NUESTRO FLAG
		i++;
		f->len++;
	}
}
