/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:03:21 by yrio              #+#    #+#             */
/*   Updated: 2023/11/20 12:13:07 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
/*
int 	main(void)
{
	char 	*str;
	char	*str2;
	t_list *elem;
	t_list *list;
	
	str = (char *)malloc(6*sizeof(char));
	str = "Hello";
	str2 = (char *)malloc(8*sizeof(char));
	str2 = "Bonjour";

	elem = ft_lstnew((void *)str);
	list = ft_lstnew((void *)str2);
	ft_lstadd_front(&list, elem);
	printf("%d", ft_lstsize(list));
	return (0);
}
*/