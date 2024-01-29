/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:42:23 by yrio              #+#    #+#             */
/*   Updated: 2023/11/20 12:09:23 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new;
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
	ft_lstadd_back(&list, elem2);
	//printf("%s", (char *)ft_lstlast(list) -> content);
	printf("%s", (char *)list -> next -> next -> content);
	return (0);
}
*/
