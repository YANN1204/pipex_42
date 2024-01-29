/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:40:15 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:22:35 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n)
	{
		*str++ = '\0';
		--n;
	}
}
/*
int 	main(void)
{
	t_list *elem;
	void 	*str;
	int 	len;

	str = ft_strdup("Hello");
	elem = ft_lstnew((void *)str);

	len = ft_strlen((char *)elem -> content);
	printf("%s\n", (char *)elem -> content);
	
	ft_bzero((void *)elem -> content, len);
	printf("%s", (char *)elem -> content);
	return (0);
}
*/

/*
#include <stdio.h>
#include <unistd.h>

int 	main(void)
{
	char	str[] = "bonjour";
	int 	i; 

	i = 0;

	while (i < 7)
	{
		write(1, &str[i], 1);
		i++;
	}
	i = 0;
	
	ft_bzero(str, 4);

	printf("%c", '\n');
	while (i < 7)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
*/
