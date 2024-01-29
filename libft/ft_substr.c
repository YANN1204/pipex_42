/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:15:29 by yrio              #+#    #+#             */
/*   Updated: 2023/11/21 10:42:59 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new_str;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > (unsigned int)ft_strlen(s))
	{
		new_str = malloc(1);
		if (!new_str)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < (unsigned int)len && s[start] != '\0')
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}
/*
int 	main(void)
{
	char const	*s = "bonjour";
	unsigned int	start = 3;
	size_t 	len = 3;
	char *new_str;

	new_str = ft_substr(s, start, len);
	printf("%s\n", new_str);
	if (new_str != NULL)
	{
		free(new_str);
		printf("bien malloc\n");
	}
	return (0);
}
*/
