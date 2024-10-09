/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elallema <elallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:34:56 by elallema          #+#    #+#             */
/*   Updated: 2023/03/18 19:33:23 by elallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_flag(char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'd')
		return (1);
	else if (c == 'i')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == '%')
		return (1);
	return (0);
}

int	treat_flag(char flag, va_list ap)
{
	if (flag == 'c')
	{
		ft_putchar_fd((char)va_arg(ap, int), 1);
		return (1);
	}
	else if (flag == 's')
		return (flag_s(va_arg(ap, char *)));
	else if (flag == 'p')
		return (flag_p(va_arg(ap, unsigned long long int)));
	else if (flag == 'd' || flag == 'i')
		return (flag_int(va_arg(ap, int)));
	else if (flag == 'u')
		return (flag_unsigned_int(va_arg(ap, unsigned int)));
	else if (flag == 'x')
		return (flag_hexa(va_arg(ap, unsigned int), 0));
	else if (flag == 'X')
		return (flag_hexa(va_arg(ap, unsigned int), 1));
	else
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_valid_flag(str[i++]))
			count += treat_flag(str[i++], ap);
		else
		{
			ft_putchar_fd(str[i++], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}


/*
int main()
{
    ft_printf("%%");
    return (0);
}*/
