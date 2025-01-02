/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:21:00 by irkalini          #+#    #+#             */
/*   Updated: 2024/06/22 13:25:09 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_di(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_print_c('-');
		nbr = -nbr;
		(*len)++;
	}
	if (nbr >= 10)
	{
		ft_print_di(nbr / 10, len);
		ft_print_di(nbr % 10, len);
	}
	else
	{
		ft_print_c(nbr + '0');
		(*len)++;
	}
}
