/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:01:01 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/28 22:26:48 by agutierr         ###   ########.fr       */
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
			reset_flags(f);
			f->i++;
			while((format[f->i] == '0' && format[f->i+1] == '-') || (format[f->i] == '0' && format[f->i+1] == '0'))
				f->i++;
			if (format[f->i] == '0')
				f->space_zero = '0';
			if (format[f->i] == '-' || format[f->i] == '.' || format[f->i] == '*' ||
			(format[f->i] > 47 && format[f->i] < 58))
			{
				if (format[f->i] == '-')
				{
					f->minus_width = 1;
					f->i++;
				}
				comprobar_flag(format, &(*f));
			}
			if (format[f->i] == 'd' || format[f->i] == 'u' || format[f->i] == 'f' || format[f->i] == 'x'
			|| format[f->i] == 'X' || format[f->i] == 'o' || format[f->i] == 's' || format[f->i] == 'c'
			|| format[f->i] == 'p')
			{
				comprobar_formato(format, f);
			}
		}
		else
			f->len += write(1, &format[f->i], 1);
	f->i++;
	}
}

void		comprobar_formato(const char *format, t_flag *f) 	//VIENE DE LA FUNCION COMPROBAR_PERCENT
{
	if (format[f->i] == 'd' || format[f->i] == 'i')
		comprobar_decimal(f);			//DENTRO HAY QUE TENER EN CUENTA
	if (format[f->i] == 'x')				//TANTO PRECISION COMO WIDTH PARA DEVOLVER
		comprobar_hex(f, "0123456789abcdef");				//UN RESULTADO U OTR
	if (format[f->i] == 'X')
		comprobar_unhex(f, "0123456789ABCDEF");
	if (format[f->i] == 'u')
		comprobar_undecimal(f);
	if (format[f->i] == 'c')
		comprobar_char(f);
	if (format[f->i] == 's')
		comprobar_string(f);  // ---> //ARCHIVO ft_printf_strings.c
	if (format[f->i] == 'p')
		comprobar_puntero(f);
}

void		comprobar_flag(const char *format, t_flag *f)
{
	if((format[f->i] > 47 && format[f->i] < 58) || format[f->i] == 42 || format[f->i] == 46) //entre 0 y 9 || * || . ||
	{//OJO QUE EN VEZ DE WHILE PODRIA SER IF EN EL EJ: "%s9"
		while((format[f->i] > 47 && format[f->i] < 58) || format[f->i] == 42) //entre 0 y 9 || *  --> WIDTH
		{		//WIDTH
			f->flag_width = 1; 			//¿está bien ponerlo aqui el bool a 1?
			if (format[f->i] == 42) //si es asterisco
			{
				f->width = va_arg(f->args, int);
				subtracta(&(*f)); // esta funcion solo pone f->minus a 1 si es <0
				f->i++;
			}
			else				// si no es asterisco, sera entre 0 y 9
			{
				calculo_width(format, f); //esta funcion sacará el numero correspondiente al width
			}
		}
		if (format[f->i] == 46) // si es .
		{		//PRECISION
			f->flag_precision = 1;
			f-> space_zero = ' ';
			f->i++;
			if (format[f->i] == '-')
				{
					f->minus_width = 1;
					f->i++;
				}
			while((format[f->i] > 47 && format[f->i] < 58) || format[f->i] == 42) //entre 0 y 9 || * --> PRECISION
			{
				if (format[f->i] == 42) //si es asterisco
				{
					f->precision = va_arg(f->args, int);
					subtracta(&(*f)); // esta funcion solo pone f->minus a 1 si es <0
					f->i++;
				}
				else
				{
					calculo_precision(format, f);
				}
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
	while ((format[j] > 47) && (format[j] < 58)) //entre 0 y 9
	{
		j++;
		l++;
	}
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
	while ((format[j] > 47) && (format[j] < 58)) //entre 0 y 9
	{
		j++;
		l++;
	}
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

void		reset_flags(t_flag *f)	//esta funcion para hacer reset de los flags...
{							//...y poder tratar el siguiente % que veamos
	f->flag_width = 0;
	f->width = 0;
	f->flag_precision = 0;
	f->precision = 0;
	f->minus_width = 0;
	f->minus_precision = 0;
	f->space_zero = ' ';
}

void subtracta(t_flag *f)
{
	if (f->width < 0)
		f->minus_width = 1;
	if (f->precision < 0)
		f->minus_precision = 1;
}
