/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:37:38 by irkalini          #+#    #+#             */
/*   Updated: 2024/07/15 18:33:12 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char c, va_list args, int *len)
{
	if (c == 'c')
	{
		++(*len);
		ft_print_c(va_arg(args, int));
	}
	else if (c == 's')
		ft_print_s(va_arg(args, char *), len);
	else if (c == 'd' || c == 'i')
		ft_print_di(va_arg(args, int), len);
	else if (c == 'p')
		ft_print_p(va_arg(args, unsigned long long), len);
	else if (c == 'u')
		ft_print_u(va_arg(args, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_print_x(va_arg(args, unsigned int), c, len);
	else if (c != 0)
	{
		++(*len);
		ft_print_c(c);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_print_c(format[i]);
			len++;
		}
		else
			ft_format(format[++i], args, &len);
		i++;
	}
	va_end(args);
	return (len);
}
