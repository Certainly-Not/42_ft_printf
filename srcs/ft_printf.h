/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elallema <elallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:13:42 by elallema          #+#    #+#             */
/*   Updated: 2023/03/16 16:07:52 by elallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_printf(const char *str, ...);
int		treat_flag(char flag, va_list ap);
int		is_valid_flag(char c);
int		get_uint_size(unsigned int i);
int		get_int_size(int i);
void	ft_putptr(unsigned long long int n);
int		get_ptr_size(unsigned long long int i);
int		treat_flag(char flag, va_list ap);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	ft_putnbr_hexa(unsigned int nbr, char *base, int sign);
int		ptr_size(unsigned long long int i);
int		hexa_size(unsigned int i);
int		flag_s(char *str);
int		flag_int(int i);
int		flag_unsigned_int(unsigned int i);
int		flag_p(unsigned long long int p);
int		flag_hexa(unsigned int i, int is_case);

#endif