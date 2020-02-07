/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:01:01 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/07 15:59:22 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_flag	f;

	f.len = 0;
	f.i = 0;
	va_start(f.args, format);
	if (!(ft_strchr(format, '%'))) 	//SI NO HAY %
	{
		ft_putstr(format);
		f.len = ft_strlen(format);
	}
	else							//SI HAY %
	{
		comprobar_percent(format, f); //esto nos lo hará todo, no puede salir de aqui sin terminar el programa

	}
	va_end(f.args);
	return (f.len);
}

void comprobar_percent(const char *format, t_flag f)
{
	while(format[f.i] != '\0')
	{
		if (format[f.i] == '%')  //MODIFICAR QUE NO SALGA DE ESTE IF HASTA Q NO COMPRUEBE...
		{						//... EL FLAG ENTERO, TANTO preciscion Y WITH COMO %scdxuoX...
			f.i ++;
			if (format[f.i] == '-.0123456789')
			{
				f.flag_width = 1;
				comprobar_flag(format, f);				//LO DEJAREMOS PARA EL FINAL
			}
			if (format[f.i] == 'dufxXosc')
			{
				comprobar_formato(format, f);
			}
		}
		AQUI TIENE QUE IR IMPRIMIENTO EL RESTO DEL STRING QUE NO TENGA FLAGS
	}
}

void comprobar_flag(const char *format, t_flag f) //OJO CON EL SIGNO - HAY QUE IMPLEMENTARLO !!!!!!!!!!!!!!!!!!!!!!
{
	while((format[f.i] > 47 && format[f.i] < 58) || format[f.i] == 42 || format[f.i] == 46) //entre 0 y 9 || * || . ||
	{
		while(format[f.i] > 47 && format[f.i] < 58 || format[f.i] == 42) //entre 0 y 9 || *  --> WIDTH
		{
			if (format[f.i] == 42) //si es asterisco
			{
				hay que contar con el siguiente argumento (va_args) que hará de width en este caso.
			}
			else				// si no es asterisco, sera entre 0 y 9
			{
				void calculo_width(format, f); //esta funcion sacará el numero correspondiente al width
				f.i ++;
			}
		}
		if (format[f.i] == 46) // si es .
		{
			f.i ++;
			while(format[f.i] > 47 && format[f.i] < 58 || format[f.i] == 42) //entre 0 y 9 || * --> PRECISION
			{
				if (format[f.i] == 42) //si es asterisco
				{
					hay que contar con el siguiente argumento (va_args) que hará de width en este caso.
				}
				else				// si no es asterisco, sera entre 0 y 9
				{
					f.flag_precision = 1;
					void calculo_precision(format, f); //esta funcion sacará el numero correspondiente al width
					f.i ++;
				}
			}
		}
	}
}

void calculo_width(const char *format, t_flag f)
{
	hay que hacer un atoi en el que tenemos que sacar el '%12' numero que viene como string y guardarlo en la variable
	int width de nuestra struct, de esta manera podemos seguir tratandolo
}

void calculo_precision(const char *format, t_flag f)
{
	hay que hacer un atoi en el que tenemos que sacar el '%12' numero que viene como string y guardarlo en la variable
	int precision de nuestra struct, de esta manera podemos seguir tratandolo
}

void comprobar_formato(const char *format, t_flag f)
{	//como una carretera que se desvía en muchas direcciones segun sea %s%c%d%x%p...
	if (format[f.i] == 'd' || 'i')
		comprobar_decimal();
	if (format[f.i] == 'x')
		comprobar_hex();
	if (format[f.i] == 'X')
		comprobar_unhex();
	if (format[f.i] == 'u')
		comprobar_unsigned();
	if (format[f.i] == 'c')
		comprobar_char();
	if (format[f.i] == 's')
		comprobar_string();
	if (format[f.i] == 'p')
		comprobar_puntero();
}

void reset_flags(t_flag f)	//esta funcion para hacer reset de los flags...
{							//...y poder tratar el siguiente % que veamos
	f.flag_width = 0;
	f.width = 0;
	f.flag_precision = 0;
	f.precision = 0;
}

void atoizador(const char *format, t_flag f) //si despues de % hay width o precision
{
	int						j;
	char					*str;


	j = 0;
	while (format[f.i] > 47 && format[f.i] < 58) //entre 0 y 9 HACER TAMBIEN EL ASTERISCO
	{
		str[j] = format[f.i];
		j++;
		f.i++;
	}
	str[j] = '\0';
	f.flag_width = ft_atoi(str); //OJO, ESTO METERLO EN UN IF
	if(format[f.i] == 46)
	{
		f.i++;
		while(format[f.i] > 47 && format[f.i] < 58) //entre 0 y 9 HACER TAMBIEN EL ASTERISCO
	}
	}

}

int							ft_atoi(char *str)
{
	unsigned long long int	num;
	int						sign;
	int						i;

	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == '\f') || (str[i] == '\r') || (str[i] == '\n'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	num = 0;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		if (num < 9223372036854775807)
			num = num * 10 + str[i++] - 48;
		else
			return (sign == 1 ? -1 : 0);
	}
	return (sign * num);
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* - - HASTA AQUI ES EL PROGRAMA,  LO DE ABAJO NO VALE - - */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

