/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:03:14 by yrio              #+#    #+#             */
/*   Updated: 2024/01/29 11:31:44 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	lstadd_back(t_list *new, t_list *list_cmd)
{
	t_list	*tmp;

	tmp = list_cmd;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	lstclear(t_list *lst)
{
	t_list	*first;
	t_list	*second;

	if (lst == NULL)
		return ;
	first = lst;
	while (first != NULL)
	{
		second = first;
		first = first -> next;
		free_split(second->spliting_cmd_args);
		if (second->path_cmd)
			free(second -> path_cmd);
		free(second);
	}
	lst = NULL;
}

t_list	*lst_index(t_list *lst, int index)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->index == index)
			return (lst);
		lst = lst -> next;
	}
	return (NULL);
}
