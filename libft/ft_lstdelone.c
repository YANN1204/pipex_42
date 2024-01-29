/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:58:38 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:04:20 by yrio             ###   ########.fr       */
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
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst -> content);
	free(lst);
}

/*
int 	main(void)
{
	t_list *elem;
	void 	*str;

	str = ft_strdup("Hello");
	elem = ft_lstnew((void *)str);

	ft_lstdelone(elem, delelem);
	//printf("%s", (char *)elem -> content);
	return (0);
}
*/