/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:22:29 by yrio              #+#    #+#             */
/*   Updated: 2024/01/29 17:28:46 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirection_empty_fd(int index_cmd, char **path_split, t_pipex *pipex)
{
	if (ft_strncmp(pipex->infile_name, "here_doc", 8) \
		&& pipex->fd_infile != -1)
		close(pipex->fd_infile);
	dup2(pipex->recup, 0);
	pipex->fd_infile = -1;
	if (!lst_index(pipex->list_cmd, index_cmd)->cmd)
		free_split(path_split);
}
