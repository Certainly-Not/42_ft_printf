/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_getsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elallema <elallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:28:40 by elallema          #+#    #+#             */
/*   Updated: 2023/03/18 18:18:26 by elallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_ptr_size(unsigned long long int i)
{
	int	size;

	if (!i)
		return (5);
	size = (i == 0);
	while (i)
	{
		size++;
		i /= 16;
	}
	return (size + 2);
}

int	get_int_size(int i)
{
	int	size;

	size = (i == 0);
	if (i < 0)
		size++;
	while (i)
	{
		size++;
		i /= 10;
	}
	return (size);
}

int	get_uint_size(unsigned int i)
{
	int	size;

	size = (i == 0);
	while (i > 0)
	{
		size++;
		i /= 10;
	}
	return (size);
}

int	hexa_size(unsigned int i)
{
	int	size;

	size = (i == 0);
	if (i < 0)
		size++;
	while (i)
	{
		size++;
		i /= 16;
	}
	return (size);
}
