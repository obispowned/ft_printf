/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:01:01 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/13 18:06:47 by agutierr         ###   ########.fr       */
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
	if (ft_strchr(format, '%')) 	//SI NO HAY %
	{
		comprobar_percent(format, &f); //esto nos lo hará todo, no puede salir de aqui sin terminar el program
	}
	else							//SI HAY %
	{
		ft_putstr(format);
		f.len = ft_strlen(format);
	}
	va_end(f.args);
	return (f.len);
}

void		comprobar_percent(const char *format, t_flag *f)
{			//VIENE DE LA FUNCION FT_PPRINTF
	while(format[f->i] != '\0')
	{
		if (format[f->i] == '%')  //MODIFICAR QUE NO SALGA DE ESTE IF HASTA Q NO COMPRUEBE...
		{					//... EL FLAG ENTERO, TANTO preciscion Y WITH COMO %scdxuoX...
			reset_flags(&(*f));
			f->i ++;
			if (format[f->i] == '-' || format[f->i] == '.' || format[f->i] == '*' ||
			(format[f->i] > 47 && format[f->i] < 58))
			{
				if (format[f->i] == '-')
				{
					f->minus = 1;
					f->i++;
				}
				comprobar_flag(format, &(*f));				//LO DEJAREMOS PARA EL FINAL
			}
			if (format[f->i] == 'd' || format[f->i] == 'u' || format[f->i] == 'f' || format[f->i] == 'x'
			|| format[f->i] == 'X' || format[f->i] == 'o' || format[f->i] == 's' || format[f->i] == 'c')
			{
				comprobar_formato(format, *f);
				f->i++;
			}
		}
	write(1, &format[f->i], 1);
	f->i ++;
	}
}

void		comprobar_flag(const char *format, t_flag *f) //OJO CON EL SIGNO - HAY QUE IMPLEMENTARLO !!!!!!!!!!!!!!!!!!!!!!
{			//VIENE DE LA FUNCION COMPROBAR_PERCENT
	if((format[f->i] > 47 && format[f->i] < 58) || format[f->i] == 42 || format[f->i] == 46) //entre 0 y 9 || * || . ||
	{//OJO QUE EN VEZ DE WHILE PODRIA SER IF EN EL EJ: "%s9"
		while((format[f->i] > 47 && format[f->i] < 58) || format[f->i] == 42) //entre 0 y 9 || *  --> WIDTH
		{		//WIDTH
			f->flag_width = 1; 			//¿está bien ponerlo aqui el bool a 1?
			if (format[f->i] == 42) //si es asterisco
			{
//				hay que contar con el siguiente argumento (va_args) que hará de width en este caso.
			}
			else				// si no es asterisco, sera entre 0 y 9
			{
				calculo_width(format, &(*f)); //esta funcion sacará el numero correspondiente al width
			}
		}
		if (format[f->i] == 46) // si es .
		{		//PRECISION
		f->flag_precision = 1;
		f->i ++;
			while((format[f->i] > 47 && format[f->i] < 58) || format[f->i] == 42) //entre 0 y 9 || * --> PRECISION
			{
				if (format[f->i] == 42) //si es asterisco
				{
//					hay que contar con el siguiente argumento (va_args) que hará de width en este caso.
				}
				else				// si no es asterisco, sera entre 0 y 9
				{
					calculo_precision(format, &(*f)); //esta funcion sacará el numero correspondiente al width
				}
			f->i ++;
			}
		}
	}
}

void		calculo_width(const char *format, t_flag *f)
{
	int						j;
	int						l;
	char					*str;

	l = 0;
	j = f->i;
	while ((format[f->i] > 47) && (format[f->i] < 58)) //entre 0 y 9
	{
		f->i++;
		l++;
	}
	f->i = j;
	j = 0;
	str = malloc(l + 1);
	while ((format[f->i] > 47) && (format[f->i] < 58)) //entre 0 y 9
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
	int						j;
	int						l;
	char					*str;

	l = 0;
	j = f->i;
	while ((format[f->i] > 47) && (format[f->i] < 58)) //entre 0 y 9
	{
		f->i++;
		l++;
	}
	f->i = j;
	j = 0;
	str = malloc(l + 1);
	while(format[f->i] > 47 && format[f->i] < 58) //entre 0 y 9
	{
		str[j] = format[f->i];
		j++;
		f->i++;
	}
	str[j] = '\0';
	if (f->flag_precision == 1)
		f->precision = ft_atoi(str); //OJO, ESTO METERLO EN UN IF
	free(str);
}

void		comprobar_formato(const char *format, t_flag f) 	//VIENE DE LA FUNCION COMPROBAR_PERCENT
{	//como una carretera que se desvía en muchas direcciones segun sea %s%c%d%x%p...
//	if (format[f.i] == 'd' || format[f.i] == 'i')
//		comprobar_decimal();			//DENTRO HAY QUE TENER EN CUENTA
//	if (format[f.i] == 'x')				//TANTO PRECISION COMO WIDTH PARA DEVOLVER
//		comprobar_hex();				//UN RESULTADO U OTRO
//	if (format[f.i] == 'X')
//		comprobar_unhex();
//	if (format[f.i] == 'u')
//		comprobar_unsigned();
//	if (format[f.i] == 'c')
//		comprobar_char();
	if (format[f.i] == 's')
		comprobar_string(f);
//	if (format[f.i] == 'p')
//		comprobar_puntero();
}

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

void		reset_flags(t_flag *f)	//esta funcion para hacer reset de los flags...
{							//...y poder tratar el siguiente % que veamos
	f->flag_width = 0;
	f->width = 0;
	f->flag_precision = 0;
	f->precision = 0;
	f->minus = 0;
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* - - HASTA AQUI ES EL PROGRAMA,  LO DE ABAJO NO VALE - - */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
 ---------PRINTF PARA DEBUG:
 ---------comprobar todas las variables_
printf("\nFormat[i]: %c, flagWidth: %d-%d, flagPre: %d-%d, len-i: %d-%d, minus: %d\n", format[f->i], f->flag_width, f->width,
f->flag_precision, f->precision, f->len, f->i, f->minus);


*/
