/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:40:48 by irkalini          #+#    #+#             */
/*   Updated: 2024/06/22 17:14:24 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x(unsigned int nbr, int c, int *len)
{
	if (nbr >= 16)
	{
		ft_print_x(nbr / 16, c, len);
		ft_print_x(nbr % 16, c, len);
	}
	else
	{
		if (nbr <= 9)
		{
			ft_print_c(nbr + '0');
			(*len)++;
		}
		else if (nbr >= 10 && c == 'x')
		{
			ft_print_c(nbr - 10 + 'a');
			(*len)++;
		}
		else if (nbr >= 10 && c == 'X')
		{
			ft_print_c(nbr - 10 + 'A');
			(*len)++;
		}
	}
}
