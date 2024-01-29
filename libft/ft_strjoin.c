/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:06:18 by yrio              #+#    #+#             */
/*   Updated: 2023/11/21 10:41:28 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_total(char const *s1, char const *s2)
{
	int	count;
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	count = i;
	i = 0;
	while (s2[i] != '\0')
		i++;
	count = count + i;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lentotal;
	char	*str;

	lentotal = len_total(s1, s2) + 1;
	str = malloc(lentotal * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, lentotal);
	ft_strlcat(str, s2, lentotal);
	return ((char *)str);
}
/*
int 	main(void)
{
	char const 	*s1 = "tripouille";
	char const	*s2 = "42";
	char 	*str;

	printf("malloc exemple : %lu", strlen(s1) + strlen(s2) + 1);
	str = ft_strjoin(s1, s2);
	//printf("%s\n", str);
	if (str != NULL)
	{
		free(str);
		printf("bien malloc\n");
	}
	return (0);
}
*/
