/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:18:57 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:32:04 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int 	main(void)
{
		char s[] = {-128, 0, 127, 0};
		char s2[] = {0, 0, 127, 0};
		printf("%d", ft_memcmp(s, s2, 1));
		return (0);
}
*/

/*
int 	main(void)
{
	void 	*s1 = "bonhour";
	void 	*s2 = "bonjour";

	printf("ft_memcmp : %d\n", ft_memcmp(s1, s2, 4));
	printf("original : %d\n", memcmp(s1, s2, 4));
	return (0);
}
*/
