/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:12:44 by yrio              #+#    #+#             */
/*   Updated: 2023/11/20 12:11:25 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}
/*
int 	main(void)
{
	char 	*str;
	char	*str2;
	char	*str3;
	t_list *elem;
	t_list *elem2;
	t_list *list;
	
	str = (char *)malloc(6*sizeof(char));
	str = "Hello";
	str2 = (char *)malloc(8*sizeof(char));
	str2 = "Bonjour";
	str3 = (char *)malloc(7*sizeof(char));
	str3 = "Coucou";

	list = ft_lstnew((void *)str);
	elem = ft_lstnew((void *)str2);
	elem2 = ft_lstnew((void *)str3);
	ft_lstadd_front(&list, elem);
	ft_lstadd_front(&list, elem2);
	printf("%s", (char *)ft_lstlast(list) -> content);
	return (0);
}
*/