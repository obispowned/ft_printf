/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:16:54 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/07 10:31:20 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include </Users/agutierr/Desktop/C/printf/libft/libft.h>
# include <stdarg.h>
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	va_list		args;			//Esta variable la usamos para coger los argumentos (. . .)
	int			i;				//Posición de recorrido de lectura, lo q viene siendo un índice
	int			len;			//Retorno de printf (bytes, o cantidad de caracteres)
	int			flag_width;		//Comprobar si hay width, lo usaremos de BOOL
	int			width;			//Numero, cantidad de width primer numero delante del .
	int			flag_precision; //Comprobar si hay precision, lo usaremos de BOOL
	int			precision;		//Numero, cantidad de precision segundo numero detras del .
}t_flag;

int				ft_printf(const char *format, ...);

#endif
