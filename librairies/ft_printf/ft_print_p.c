/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:06:06 by irkalini          #+#    #+#             */
/*   Updated: 2024/06/28 16:26:13 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p(unsigned long long ptr, int *len)
{
	if (ptr == 0 || !(ptr))
	{
		write(1, "(nil)", 5);
		*len += 5;
	}
	else
	{
		write(1, "0x", 2);
		*len += 2;
		ft_put_p(ptr, len);
	}
}

void	ft_put_p(unsigned long long ptr, int *len)
{
	if (ptr >= 16)
	{
		ft_put_p(ptr / 16, len);
		ft_put_p(ptr % 16, len);
	}
	else
	{
		if (ptr <= 9)
		{
			ft_print_c(ptr + '0');
			(*len)++;
		}
		else
		{
			ft_print_c(ptr - 10 + 'a');
			(*len)++;
		}
	}
}
