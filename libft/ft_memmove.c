/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:59:54 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:29:23 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dest2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (dest2 == src2)
		return (dest);
	if (src2 < dest2)
	{
		while (n--)
		{
			*(dest2 + n) = *(src2 + n);
		}
		return (dest);
	}
	while (n--)
		*dest2++ = *src2++;
	return (dest);
}
/*
int 	main(void)
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char 	*out;
	
	out = ft_memmove(s0, s, 7);
	printf("%s", s);
	printf("%s", out);
	printf("%d", !memcmp(s, s0, 7));  //Post 0
	return (0);
}
*/

/*
int 	main(void)
{
	char	src[7] = "bonjour";
	char 	dest[7] = "";
	char 	*dest2;
	char 	*dest3;
	int 	size = 5;

	dest2 = malloc(size + 1 * sizeof(char));
	dest2[5] = '\0'; 
	dest2 = ft_memmove(dest, src, size);
	printf("ft_memmove : %s\n", dest2);

	dest3 = malloc(size + 1 * sizeof(char));
	dest3[5] = '\0';
	dest3 = memmove(dest, src, size);
	printf("original : %s\n", dest3);
	return (0);
}
*/
