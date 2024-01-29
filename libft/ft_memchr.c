/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:54:27 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:30:46 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t	n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}
/*
int 	main(void)
{
	void 	*str = "bonjour";
	void 	*result;
	char 	*result2;
	
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	result = ft_memchr(str, 'o', 3);
	printf("%s", (char *)result);
	//printf("%d", ft_memchr(s, 2 + 256, 3) == s + 2);
	return (0);
}
*/
