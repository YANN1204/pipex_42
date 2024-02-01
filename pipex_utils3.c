/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:22:29 by yrio              #+#    #+#             */
/*   Updated: 2024/01/31 15:28:49 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirection_empty_fd(int index_cmd, char **path_split, t_pipex *pipex)
{
	pipex->recup = open("tmp_for_pipex_build_id_8327508157271", O_CREAT | \
		O_RDWR | O_TRUNC, 0644);
	if (ft_strncmp(pipex->infile_name, "here_doc", 8) \
		&& pipex->fd_infile != -1)
		close(pipex->fd_infile);
	dup2(pipex->recup, 0);
	pipex->fd_infile = -1;
	if (!lst_index(pipex->list_cmd, index_cmd)->cmd)
		free_split(path_split);
	close(pipex->recup);
	unlink("tmp_for_pipex_build_id_8327508157271");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**splitting_path(char *path, char **path_split, t_pipex *pipex)
{
	int	error_fd[2];

	path_split = ft_split(path, ':');
	if (!path_split)
	{
		pipex->error_init = 1;
		free(path);
		close_pipex(error_fd, pipex);
	}
	return (path_split);
}
