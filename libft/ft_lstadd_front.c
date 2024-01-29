/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:45:11 by yrio              #+#    #+#             */
/*   Updated: 2023/11/20 12:09:38 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
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
	printf("%s", (char *)list->next);
	ft_lstadd_front(&list, elem);
	printf("%s", (char *)list->next->content);
	return (0);
}
*/
