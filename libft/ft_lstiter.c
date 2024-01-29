/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:52 by yrio              #+#    #+#             */
/*   Updated: 2024/01/23 16:06:38 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	strupper(void *el)
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
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
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
	ft_lstiter(list, strupper);
	printf("%s", (char *)list -> next -> next -> content);
	return (0);
}
*/