/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:44:10 by yrio              #+#    #+#             */
/*   Updated: 2024/01/18 15:20:46 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i--);
}

int	ft_putnbr(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_output(const char *format, va_list args, int count)
{
	char	*test_str;

	if (*format == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*format == 's')
	{
		test_str = va_arg(args, char *);
		if (test_str == NULL)
			count = write(1, "(null)", 6);
		else
			count = ft_putstr(test_str);
	}
	else if (*format == 'p')
		count = ft_print_ptr(va_arg(args, void *), 'p');
	else if (*format == 'd' || *format == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count = ft_putunsignednbr(va_arg(args, unsigned int));
	else if (*format == 'x')
		count = ft_print_hexa(va_arg(args, void *), 'x');
	else if (*format == 'X')
		count = ft_print_hexa(va_arg(args, void *), 'X');
	else if (*format == '%')
		count = ft_putchar(*format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += ft_output(format, args, count);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
