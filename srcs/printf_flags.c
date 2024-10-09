/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elallema <elallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:31:02 by elallema          #+#    #+#             */
/*   Updated: 2023/03/16 16:06:27 by elallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_s(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	flag_int(int i)
{
	ft_putnbr_fd(i, 1);
	return (get_int_size(i));
}

int	flag_unsigned_int(unsigned int i)
{
	ft_putnbr_unsigned_fd(i, 1);
	return (get_uint_size(i));
}

int	flag_p(unsigned long long int p)
{
	if (p)
		ft_putstr_fd("0x", 1);
	ft_putptr(p);
	return (get_ptr_size(p));
}

int	flag_hexa(unsigned int i, int is_case)
{
	char	*base;
	int		sign;

	sign = 1;
	if (!is_case)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (i < 0)
	{
		sign *= -1;
		ft_putchar_fd('-', 1);
	}
	ft_putnbr_hexa(i, base, sign);
	return (hexa_size(i));
}
