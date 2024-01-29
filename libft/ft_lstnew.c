/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:08:54 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:05:05 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

/*
int	main(void)
{
	char	*str;

	t_list	*elem;
	str = (char *)malloc(6*sizeof(char));
	str = "Hello";
	elem = ft_lstnew((void *)str);
	printf("%s\n", (char *)elem->next);
	free(elem);
}
*/