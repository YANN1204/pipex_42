/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:47:02 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:48:39 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}

/*
int		main(void)
{
	int 	i = 0;

	while (i < 200)
	{
		printf("ft_isprint %d : %d\n", i, ft_isprint(i));
		printf("original %d : %d\n", i, isprint(i));
		i++;
	}
	return (0);
}
*/
