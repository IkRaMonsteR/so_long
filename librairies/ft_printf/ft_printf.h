/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:33:27 by irkalini          #+#    #+#             */
/*   Updated: 2024/07/15 17:00:05 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_format(const char c, va_list args, int *len);
int		ft_print_c(int c);
int		ft_print_s(char *s, int *len);
void	ft_print_di(int nbr, int *len);
void	ft_print_p(unsigned long long ptr, int *len);
void	ft_put_p(unsigned long long ptr, int *len);
void	ft_print_u(unsigned int nbr, int *len);
void	ft_print_x(unsigned int nbr, int c, int *len);

#endif
