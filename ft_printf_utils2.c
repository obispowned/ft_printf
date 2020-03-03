/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:37:15 by agutierr          #+#    #+#             */
/*   Updated: 2020/03/03 20:40:28 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char						*ft_itoa(unsigned int n)
{
	char					*num;
	unsigned int			nu;
	int						len;
	int						i;

	nu = n;
	len = tam(n);
	if (!(num = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	num[len] = '\0';
	i = (nu < 0 ? 1 : 0);
	if (nu < 0)
	{
		num[0] = '-';
		nu = nu * -1;
	}
	while (len-- > i)
	{
		num[len] = (nu % 10) + 48;
		nu = (nu / 10);
	}
	return (num);
}

int							tam(unsigned int n)
{
	int						len;
	unsigned				num;

	len = (n < 0 ? 1 : 0);
	num = n;
	while (num / 10)
	{
		num = num / 10;
		len++;
	}
	len++;
	return (len);
}

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
