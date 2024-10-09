/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elallema <elallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:21:55 by elallema          #+#    #+#             */
/*   Updated: 2023/03/16 15:53:33 by elallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{	
		ft_putstr_fd("-2147483648", fd);
	}	
	else
	{	
		if (n < 0)
		{		
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n = n * -1, fd);
		}		
		else
		{
			if (n / 10)
			{	
				ft_putnbr_fd(n / 10, fd);
			}	
			ft_putchar_fd('0' + n % 10, fd);
		}	
	}
}
