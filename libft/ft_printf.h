/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:54:28 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/20 14:29:56 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchr(int c);
int		ft_print_str(char *str);
int		ft_ptr(unsigned long long ptr);
int		ft_putnb(int n);
int		ft_unsigned(unsigned int n);
int		ft_hex_format(unsigned int n, const char format);
char	*ft_itoa_printf(int n);
void	ft_ptstr(char *str);
void	ft_ptchr(char c, int *len);
void	ft_putstrl(char *str, int *len);
void	ft_putchar_fd(char c, int fd);

#endif
