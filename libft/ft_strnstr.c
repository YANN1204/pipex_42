/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:14:22 by yrio              #+#    #+#             */
/*   Updated: 2023/11/21 10:43:16 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	i = 0;
	if (str == NULL && n == 0)
		return (NULL);
	if (to_find[i] == '\0')
		return ((char *)&str[i]);
	while (str[i] && i < n)
	{
		if (ft_strncmp(&str[i], to_find, ft_strlen(to_find)) == 0)
		{
			if (i + ft_strlen(to_find) > n)
				return (0);
			return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
/*
int 	main(void)
{
	char 	*str = "bonjour";
	char 	*to_find = "njo";

	printf("%s\n", ft_strnstr(str, to_find, 3));
	printf("%s", strnstr(str, to_find, 3));
	return (0);
}
*/
