#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_flags
{
	va_list		ap;
	int			len;
	int			i;
	int			flag_width;
	int			width;
	int			flag_precision;
	int			precision;
}				t_flags;

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(const char *s)
{
	while (*s)
	{
		write(1, &(*s), 1);
		s++;
	}
}

void	flags_to_zero(t_flags *f)
{
	f->flag_width = 0;
	f->width = 0;
	f->flag_precision = 0;
	f->precision = 0;
}

void	str_printer(t_flags *f, char *s)
{
	int i;
	int aux;

	i = 0;
	aux = ft_strlen(s);
	if (f->flag_precision && f->precision >= 0 && f->precision < aux)
		aux = f->precision;
	while(i < aux)
	{
		write(1, &s[i], 1);
		i++;
		f->len++;
	}
}

void	str_width(t_flags *f, int len)
{
	int i;
	int aux;

	i = 0;
	aux = len;
	if (f->flag_precision && f->precision >= 0 && f->precision < aux)
		aux = f->precision;
	while(i < (f->width - aux))
	{
		write(1, " ", 1);
		i++;
		f->len++;
	}
}

void	format_str(t_flags *f)
{
	int		len;
	char	*s;

	s = va_arg(f->ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (f->flag_width)
		str_width(f, len);
	str_printer(f, s);
}

void	flag_sorting(const char *format, t_flags *f)
{
	while (format[f->i] >= '0' && format[f->i] <= '9')
	{
		f->flag_width = 1;
		f->width = f->width * 10 + format[f->i] - '0';
		f->i++;
	}
	if (format[f->i] == '.')
	{
		f->i++;
		while (format[f->i] >= '0' && format[f->i] <= '9')
		{
			f->flag_precision = 1;
			f->precision = f->precision * 10 + format[f->i] - '0';
			f->i++;
		}
	}
}

int		int_nbrlen(int n, char *base)
{
	int baselen;
	int len;

	len = 0;
	baselen = ft_strlen(base);
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= baselen;
		len++;
	}
	return (len);
}

void	int_width(t_flags *f, int len)
{
	int i;
	int aux;

	i = 0;
	if (f->flag_precision)
	{
		aux = f->precision > len ? f->precision : len;
		if (aux < f->width)
		{
			while (i < f->width - aux)
			{
				write(1, " ", 1);
				f->len++;
				i++;
			}
		}
	}
	else
	{
		while (i < f->width - len)
		{
			write(1, " ", 1);
			f->len++;
			i++;
		}
	}
}

void	int_precision(t_flags *f, int len)
{
	int i;

	i = 0;
	if (len < f->precision)
	{
		while (i < f->precision - len)
		{
			write(1, "0", 1);
			f->len++;
			i++;
		}
	}
}

void	putnbrbase(t_flags *f, int n, char *base, int baselen)
{
	if (n >= baselen)
	{
		putnbrbase(f, n / baselen, base, baselen);
		putnbrbase(f, n % baselen, base, baselen);
	}
	else
	{
		write(1, &base[n], 1);
		f->len++;
	}	
}

void	int_printer(t_flags *f, int n, char *base)
{
	if (f->flag_precision && !f->precision && !n)
	{
		if (f->width)
		{
			write(1, " ", 1);
			f->len++;
		}
	}
	else
		putnbrbase(f, n, base, ft_strlen(base));	
}

void	format_int(t_flags *f, char *base)
{
	int		len;
	int		n;

	n = va_arg(f->ap, int);
	len = int_nbrlen(n, base);
	if (n < 0 && f->flag_precision)
		f->precision++;
	if (f->flag_width)
		int_width(f, len);
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		f->len++;
	}
	if (f->flag_precision)
		int_precision(f, len);
	int_printer(f, n, base);
}







int		hex_nbrlen(unsigned int n, char *base)
{
	int baselen;
	int len;

	len = 0;
	baselen = ft_strlen(base);
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= baselen;
		len++;
	}
	return (len);
}

void	hex_width(t_flags *f, int len)
{
	int i;
	int aux;

	i = 0;
	if (f->flag_precision)
	{
		aux = f->precision > len ? f->precision : len;
		if (aux < f->width)
		{
			while (i < f->width - aux)
			{
				write(1, " ", 1);
				f->len++;
				i++;
			}
		}
	}
	else
	{
		while (i < f->width - len)
		{
			write(1, " ", 1);
			f->len++;
			i++;
		}
	}
}

void	hex_precision(t_flags *f, int len)
{
	int i;

	i = 0;
	if (len < f->precision)
	{
		while (i < f->precision - len)
		{
			write(1, "0", 1);
			f->len++;
			i++;
		}
	}
}

void	hex_putnbrbase(t_flags *f, unsigned int n, char *base, int baselen)
{
	if (n >= baselen)
	{
		hex_putnbrbase(f, n / baselen, base, baselen);
		hex_putnbrbase(f, n % baselen, base, baselen);
	}
	else
	{
		write(1, &base[n], 1);
		f->len++;
	}	
}

void	hex_printer(t_flags *f, unsigned int n, char *base)
{
	if (f->flag_precision && !f->precision && !n)
	{
		if (f->width)
		{
			write(1, " ", 1);
			f->len++;
		}
	}
	else
		hex_putnbrbase(f, n, base, ft_strlen(base));	
}

void	format_hex(t_flags *f, char *base)
{
	int		len;
	int		n;

	n = va_arg(f->ap, int);
	len = hex_nbrlen(n, base);
	if (n < 0 && f->flag_precision)
		f->precision++;
	if (f->flag_width)
		hex_width(f, len);
	if (f->flag_precision)
		hex_precision(f, len);
	hex_printer(f, n, base);
}









void	format_sorting(const char *format, t_flags *f)
{
	if (format[f->i] == 's')
		format_str(f);
	if (format[f->i] == 'd' || format[f->i] == 'i')
		format_int(f, "0123456789");
	if (format[f->i] == 'x')
		format_hex(f, "0123456789abcdef");
	if (format[f->i] == 'X')
		format_hex(f, "0123456789ABCDEF");
}

void	percent_finder(const char *format, t_flags *f)
{
	while (format[f->i])
	{
		if (format[f->i] == '%')
		{
			f->i++;
			flags_to_zero(f);
			if (ft_strchr(".1234567890", format[f->i]))
				flag_sorting(format, f);
			if (ft_strchr("sidxX", format[f->i]))
				format_sorting(format, f);
		}
		else
		{
			write(1, &format[f->i], 1);
			f->len++;
		}
		f->i++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_flags f;

	f.len = 0;
	f.i = 0;
	va_start(f.ap, format);
	if (ft_strchr(format, '%'))
		percent_finder(format, &f);
	else
	{
		ft_putstr(format);
		f.len = ft_strlen(format);
	}	
	va_end(f.ap);
	return (f.len);
}

int		main(void)
{
	char *s = "Mundo";
	int i = 56;
	unsigned int x = 0;

	   printf("Hola <%10.5s><%7.4i><%x>\n", s, i, x);
	ft_printf("Hola <%10.5s><%7.4i><%x>\n", s, i, x);
}