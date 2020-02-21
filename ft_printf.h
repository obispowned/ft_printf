/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:16:54 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/21 15:42:47 by agutierr         ###   ########.fr       */
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
//# include </Users/agutierr/Desktop/C/printf/libft/libft.h>

typedef struct	s_flag
{
	va_list		args;			//Esta variable la usamos para coger los argumentos (. . .)
	int			i;				//Posición de recorrido de lectura, lo q viene siendo un índice
	int			len;			//Retorno de printf (bytes, o cantidad de caracteres)
	int			flag_width;		//Comprobar si hay width, lo usaremos de BOOL
	int			width;			//Numero, cantidad de width primer numero delante del .
	int			flag_precision; //Comprobar si hay precision, lo usaremos de BOOL
	int			precision;		//Numero, cantidad de precision segundo numero detras del .
	int			minus_width;	//Bool para comprobar si hay signo negativo en width
	int			minus_precision;//Bool para comprobar si hay signo negativo en precision
}t_flag;


/*** FUNCIONES MÍAS ***/
int				ft_printf(const char *format, ...);
void			comprobar_formato(const char *format, t_flag f);
void			comprobar_flag(const char *format, t_flag *f);
void			comprobar_percent(const char *format, t_flag *f);
void			calculo_precision(const char *format, t_flag *f);
void			calculo_width(const char *format, t_flag *f);
void			reset_flags(t_flag *f);
void 			subtracta(t_flag *f);

void			comprobar_string(t_flag f);
void			str_width(t_flag *f, int len);
void			print_string(t_flag *f, char *str);

void			comprobar_decimal(t_flag f);
void			decimal_width(t_flag *f, int len);
void			print_decimal(t_flag *f, char *aux);

void			comprobar_char(t_flag f);
void			chr_width(t_flag *f);
void			print_chr(t_flag *f, char chr);

void			comprobar_hex(t_flag f);
void 			hexa_width(t_flag *f, int l);
void			hexa_convert(t_flag *f, char *digHex, unsigned int argumento);
//, int i, char *hexaPrint);

/*void			comprobar_unhex(t_flag f);
void			un_hex_printer(t_flag *f, unsigned int argumento);*/

//void			comprobar_puntero(t_flag f);
//void			pointer_printer(t_flag *f, unsigned int argumento);

/*** UTILS ***/
int				ft_atoi(const char *str);
void			ft_putstr(const char *s);
char			*ft_strchr(const char *s, char c);
int				ft_strlen(const char *s);
char			*ft_itoa(int n);
static int		tam(int n);




				/***FUNCIONES DEL LIBFT***/

/*void				ft_putstr(const char *s);
ssize_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
char				*ft_strchr(const char *s, char c);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
*/

#endif
