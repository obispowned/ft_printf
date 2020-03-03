/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:16:54 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 22:37:34 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct	s_flag
{
	va_list		args;
	int			i;
	int			len;
	int			flag_width;
	int			width;
	int			flag_precision;
	int			precision;
	int			minus_width;
	int			minus_precision;
	char		space_zero;
	int			minus;
}				t_flag;

int				ft_printf(const char *format, ...);
void			comprobar_formato(const char *format, t_flag *f);
void			comprobar_flag(const char *format, t_flag *f);
void			comprobar_flag2(const char *format, t_flag *f);
void			comprobar_percent(const char *format, t_flag *f);
void			comprobar_percent2(const char *format, t_flag *f);
void			calculo_precision(const char *format, t_flag *f);
void			calculo_width(const char *format, t_flag *f);
void			reset_flags(t_flag *f);
void			subtracta(t_flag *f);
void			compare_minus(t_flag *f);

void			stranger_things(t_flag *f);

void			comprobar_char(t_flag *f);
void			chr_width(t_flag *f);

void			comprobar_string(t_flag *f);
void			str_width(t_flag *f, int len);
void			print_string(t_flag *f, char *str);

void			comprobar_decimal(t_flag *f);
void			comprobar_decimal2(t_flag *f, char *aux, int len);
void			comprobar_decimal3(t_flag *f, char *aux, int len);
void			decimal_width(t_flag *f, int len);
void			decimal_precision(t_flag *f, int len);
void			print_decimal(t_flag *f, char *aux);

void			comprobar_undecimal(t_flag *f);
void			comprobar_undecimal2(t_flag *f, char *aux, int len);
void			undecimal_width(t_flag *f, int len);
void			undecimal_precision(t_flag *f, int len);
void			print_undecimal(t_flag *f, char *aux);

void			comprobar_hex(t_flag *f, char *digits);
void			comprobar_hex2(t_flag *f, char *digits,
unsigned int argumento, int i);
void			hexa_width(t_flag *f, int i);
void			hexa_precision(t_flag *f, int i);
void			print_hexa(t_flag *f, char *dighex, unsigned int argumento);

void			comprobar_unhex(t_flag *f, char *digits);
void			comprobar_unhex2(t_flag *f, char *digits,
unsigned int argumento, int i);
void			unhexa_width(t_flag *f, int i);
void			unhexa_precision(t_flag *f, int i);
void			print_unhexa(t_flag *f, char *dighex, unsigned int argumento);

void			comprobar_pointer(t_flag *f, char *digits);
void			comprobar_pointer2(t_flag *f, char *digits,
unsigned long int argumento, int i);
void			comprobar_pointer3(t_flag *f, char *digits,
unsigned long int argumento, int i);
void			pointer_width(t_flag *f, int i);
void			pointer_precision(t_flag *f, int i);
void			print_pointer(t_flag *f, char *dighex,
unsigned long int argumento);
int				print_pointer2(unsigned long long resto, int i);

int				ft_atoi(const char *str);
void			ft_putstr(const char *s);
char			*ft_strchr(const char *s, char c);
int				ft_strlen(const char *s);
char			*ft_itoa(unsigned int n);
int				tam(unsigned int n);

#endif
