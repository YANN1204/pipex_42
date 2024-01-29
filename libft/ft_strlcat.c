/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:51:24 by yrio              #+#    #+#             */
/*   Updated: 2024/01/17 10:29:33 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen((const char *)dest);
	j = dest_len;
	if (size <= dest_len || size == 0)
		return (size + src_len);
	while (src[i] != '\0' && j + 1 < size)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}

/*
int	main(void)
{
	int		size = 0;
	char	*src = NULL;
	char	*dest = NULL;

	char	*src2 = NULL;
	char	*dest2 = NULL;

	printf("dest = %s src = %s lenght = %zu\n", \
		dest, src, ft_strlcat(dest, src, size));
	//printf("dest2 = %s src2 = %s lenght = %zu\n", \
		//dest2, src2, strlcat(dest2, src2, size));
}
*/
