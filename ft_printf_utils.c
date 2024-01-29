/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:51:35 by yrio              #+#    #+#             */
/*   Updated: 2024/01/18 15:20:40 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putunsignednbr(unsigned int n)
{
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	putnbr_hexa_int(unsigned int nbr, char c)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += putnbr_hexa_int(nbr / 16, c);
	if (c == 'X')
		count += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	else
		count += write(1, &"0123456789abcdef"[nbr % 16], 1);
	return (count);
}

int	putnbr_hexa_long(unsigned long nbr, char c)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += putnbr_hexa_long(nbr / 16, c);
	if (c == 'X')
		count += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	else
		count += write(1, &"0123456789abcdef"[nbr % 16], 1);
	return (count);
}

int	ft_print_ptr(void *ptr, char c)
{
	unsigned long	nbr;
	int				count;

	count = 0;
	nbr = (unsigned long)ptr;
	if (nbr == 0 && c == 'p')
		return (write(1, "(nil)", 5));
	else
	{
		count += write(1, "0x", 2);
		count += putnbr_hexa_long(nbr, c);
	}
	return (count);
}

int	ft_print_hexa(void *ptr, char c)
{
	unsigned long	nbr;
	int				count;

	nbr = (unsigned long)ptr;
	count = 0;
	count += putnbr_hexa_int((unsigned int)nbr, c);
	return (count);
}
