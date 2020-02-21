/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:10:07 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/21 12:20:51 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	comprobar_unhex(t_flag f)
{
	int					len;
	unsigned int		argumento;

	argumento = va_arg(f.args, unsigned int);
	un_hex_printer(&f, argumento);

}

void	un_hex_printer(t_flag *f, unsigned int argumento)
{
	char *digHex;
	char *hexaPrint;
	unsigned int resto;
	int i;
	int j;

	digHex = "0123456789ABCDEF";
	i = 0;
	while (argumento > 0)
	{
		resto = argumento % 16;
		hexaPrint[i] = digHex[resto];
		argumento = argumento / 16;
		i++;
	}
	hexaPrint[i] = '\0';
	j = i-1;
	while (j >= 0)
	{
		write(1, &hexaPrint[j], 1);
		f->len++;
		j--;
	}
}

