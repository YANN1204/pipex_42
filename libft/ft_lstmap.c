/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:49:19 by yrio              #+#    #+#             */
/*   Updated: 2023/11/21 11:03:09 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	*strupper(void *el)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)el;
	while (str[i] != '\0')
	{
		str[i] = (char)ft_toupper((int)str[i]);
		i++;
	}
	return (el);
}

static void	delelem(void *del)
{
	int	len;

	len = ft_strlen((const char *)del);
	ft_bzero(del, len);
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	head = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew(f(lst -> content));
		if (new == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst -> next;
	}
	return (head);
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
	ft_lstmap(list, strupper, delelem);
	printf("%s", (char *)list -> content);
	return (0);
}
*/