/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:11:45 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:48:15 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int		main(void)
{
	int 	i = -100;

	while (i < 200)
	{
		printf("ft_isascii %d : %d\n", i, ft_isascii(i));
		printf("original %d : %d\n", i, isascii(i));
		i++;
	}
	return (0);
}
*/