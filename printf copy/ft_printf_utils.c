/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:56:23 by agutierr          #+#    #+#             */
/*   Updated: 2020/02/13 12:57:25 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_atoi(const char *str)
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

void	ft_putstr(const char *s)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

char	*ft_strchr(const char *s, char c)
{
	char *x;

	x = (char *)s;
	while (*x && *x != c)
		x++;
	return ((*x == c) ? x : NULL);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
