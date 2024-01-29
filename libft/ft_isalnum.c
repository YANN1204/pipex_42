/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:29:27 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:47:59 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) == 1)
		return (8);
	else if (ft_isalpha(c) == 1)
		return (8);
	else
		return (0);
}
/*
int		main(void)
{
	int 	i = 0;

	while (i < 200)
	{
		printf("ft_isalnum %d : %d\n", i, ft_isalnum(i));
		printf("original %d : %d\n", i, isalnum(i));
		i++;
	}
	return (0);
}
*/