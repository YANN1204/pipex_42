/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:32:56 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:21:29 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void	*s, int c, size_t n)
{
	unsigned long	i;
	char			*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}
/*

#include <stdio.h>
#include <unistd.h>

int 	main(void)
{
	char	str[] = "bonjour";
	void	*final;
	int 	i; 

	i = 0;

	while (i < 7)
	{
		write(1, &str[i], 1);
		i++;
	}
	
	final = ft_memset(str, 'A', 42);

	printf("%c", '\n');
	i = 0;
	while (i < 7)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
*/