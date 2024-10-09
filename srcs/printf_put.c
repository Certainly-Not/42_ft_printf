/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elallema <elallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:35:46 by elallema          #+#    #+#             */
/*   Updated: 2023/03/16 15:54:36 by elallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned int nbr, char *base, int sign)
{	
	int	mod;

	if (nbr / 16)
	{	
		ft_putnbr_hexa((nbr / 16), base, sign);
	}	
	mod = (nbr % 16) * sign;
	ft_putchar_fd(base[mod], 1);
}	

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n / 10)
	{	
		ft_putnbr_fd(n / 10, fd);
	}	
	ft_putchar_fd('0' + n % 10, fd);
}	

void	ft_putptr(unsigned long long int n)
{
	char					*base;

	base = "0123456789abcdef";
	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return ;
	}
	if (n >= 16)
	{
		ft_putptr(n / 16);
		n = n % 16;
	}
	ft_putchar_fd(base[n], 1);
}
