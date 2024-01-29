/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:24:27 by yrio              #+#    #+#             */
/*   Updated: 2023/11/20 12:10:35 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void 	delelem(void *del)
{
	int 	len;

	len = ft_strlen((const char *)del);
	ft_bzero(del, len);
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*first;
	t_list	*second;

	if (lst == NULL || del == NULL)
		return ;
	first = *lst;
	while (first != NULL)
	{
		second = first;
		first = first -> next;
		del(second -> content);
		free(second);
	}
	*lst = NULL;
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
	
	str = ft_strdup("Hello");
	str2 = ft_strdup("Bonjour");
	str3 = ft_strdup("Coucou");

	list = ft_lstnew((void *)str);
	elem = ft_lstnew((void *)str2);
	elem2 = ft_lstnew((void *)str3);
	ft_lstadd_back(&list, elem);
	ft_lstadd_back(&list, elem2);
	ft_lstclear(&list, delelem);
	//printf("%s", (char *)list -> content);
	printf("%d", list == 0);
	return (0);
}
*/