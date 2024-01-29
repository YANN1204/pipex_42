/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:23:38 by yrio              #+#    #+#             */
/*   Updated: 2024/01/26 18:09:11 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc_put_in(char **argv, int *fd, t_pipex *pipex)
{
	char		*str;

	close(fd[0]);
	while (1)
	{
		str = get_next_line(0, argv[2]);
		if (!ft_strncmp(str, argv[2], ft_strlen(argv[2])))
		{
			free(str);
			close_pipex(fd, pipex);
			exit(0);
		}
		else
		{
			ft_putstr_fd(str, fd[1]);
			free(str);
		}
	}
}

int	ft_pipe_here_doc(char **argv, int *fd, t_pipex *pipex)
{
	int	pid;

	if (pipe(fd) == -1)
		return (close_pipex(fd, pipex));
	pid = fork();
	if (pid == -1)
		return (close_pipex(fd, pipex));
	if (pid == 0)
		here_doc_put_in(argv, fd, pipex);
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
	return (0);
}

int	ft_pipe(int *fd, int index_cmd, int pid, t_pipex *pipex)
{
	if (pid == -1)
		return (close_pipex(fd, pipex));
	if (pid == 0)
	{
		if (index_cmd == pipex->total_cmd - 1)
			dup2(pipex->fd_outfile, 1);
		else
			dup2(fd[1], 1);
		close(fd[0]);
		exec_child(fd, pipex, index_cmd, pipex->total_cmd);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[1]);
	}
	return (0);
}
