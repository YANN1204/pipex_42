/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:39:47 by yrio              #+#    #+#             */
/*   Updated: 2023/11/21 10:45:04 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dest2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	i = 0;
	if (dest2 == NULL && src2 == NULL)
		return (NULL);
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
/*
int 	main(void)
{
	char	src[7] = "bonjour";
	char 	dest[7] = "test123";
	char 	*dest2;
	char 	*dest3;
	int 	size = 5;

	dest2 = malloc(size + 1 * sizeof(char));
	dest2[5] = '\0'; 
	dest2 = ft_memcpy(dest, src, size);
	//dest2[5] = '\0';
	printf("ft_memcpy : %s\n", dest2);

	dest3 = malloc(size + 1 * sizeof(char));
	dest3[5] = '\0';
	dest3 = memcpy(dest, src, size);
	printf("original : %s\n", dest3);
	return (0);
}
*/