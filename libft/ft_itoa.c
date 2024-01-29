/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:26:49 by yrio              #+#    #+#             */
/*   Updated: 2023/11/21 10:34:09 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nombredigit(long int n)
{
	int	nbr;

	nbr = 0;
	if (n < 0)
	{
		nbr++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		nbr++;
	}
	nbr++;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = nombredigit(n);
	nbr = malloc((i + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	nbr[i] = '\0';
	i--;
	while (n >= 10)
	{
		nbr[i] = (n % 10) + 48;
		n = (n / 10);
		i--;
	}
	nbr[i] = (n % 10) + '0';
	return (nbr);
}

/*
int 	main(void)
{
	char	*str;

	str = ft_itoa(INT_MIN);
	printf("%s", str);
	if (str != NULL)
		free(str);
	return (0);
}
*/
