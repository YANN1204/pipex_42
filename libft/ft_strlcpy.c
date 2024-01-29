/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:05:17 by yrio              #+#    #+#             */
/*   Updated: 2023/11/21 10:43:54 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	// voir strlcat pour la definition de size
	int 	size = 5;
	char src[] = "tripouille";
	
	char 	*dest;
	dest = malloc(13 * sizeof(char));
	//printf("lentotal : %zu", lentotal);
	ft_strlcpy(dest, src, 13);
	free(dest);

	//printf("dest = %s src = %s lenght = %zu\n", \ 
		dest, src, ft_strlcpy(dest, src, size));
	//printf("dest2 = %s src2 = %s lenght = %zu\n", \ 
		dest2, src2, strlcpy(dest2, src2, size));

}
*/
