/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:53:36 by yrio              #+#    #+#             */
/*   Updated: 2023/11/21 10:42:10 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_charset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && ft_charset(set, s1[i]) == 1)
		i++;
	j = ft_strlen((char *)s1) - 1;
	while (s1[j] != '\0' && ft_charset(set, s1[j]) == 1)
		j--;
	new_str = ft_substr(s1, i, j + 1 - i);
	return (new_str);
}
/*
int 	main(void)
{
	char const	*s1 = "b onjourf b  ";
	char const	*set = "b ";
	char	*new_str;

	new_str = ft_strtrim(s1, set);
	printf("%s", new_str);
	if (new_str != NULL)
	{
		free(new_str);
		printf("\nbien malloc");
	}
	return (0);
}
*/
