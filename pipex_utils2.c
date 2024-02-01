/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:23:38 by yrio              #+#    #+#             */
/*   Updated: 2024/01/31 14:02:19 by yrio             ###   ########.fr       */
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
		if (ft_strlen(str) == ft_strlen(argv[2]) + 1 && \
			ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0)
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
		close(fd[0]);
	}
	return (0);
}

int	ft_pipe(int *fd, int index_cmd, int pid, t_pipex *pipex)
{
	if (pid == 0)
	{
		if (index_cmd == pipex->total_cmd - 1)
		{
			dup2(pipex->fd_outfile, 1);
			close(pipex->fd_outfile);
			if (pipex->fd_infile != -1)
				close(pipex->fd_infile);
		}
		else
		{
			if (pipex->fd_infile != -1)
				close(pipex->fd_infile);
			dup2(fd[1], 1);
			close(pipex->fd_outfile);
		}
		exec_child(fd, pipex, index_cmd);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
	}
	return (0);
}

int	ft_pipe_loop(int index_cmd, int *fd, t_pipex *pipex)
{
	char	**path_split;
	char	*path_cmd;
	t_list	*elem;

	while (index_cmd < pipex->total_cmd)
	{	
		path_split = get_paths(pipex->env, pipex);
		elem = lst_index(pipex->list_cmd, index_cmd);
		path_cmd = check_cmd(elem->cmd, path_split);
		if (!path_cmd)
		{
			redirection_empty_fd(index_cmd, path_split, pipex);
			index_cmd++;
			continue ;
		}
		lst_index(pipex->list_cmd, index_cmd)->path_cmd = path_cmd;
		if (pipe(fd) == -1)
			return (close_pipex(fd, pipex));
		pipex->pid[index_cmd] = fork();
		if (pipex->pid[index_cmd] == -1)
			return (close_pipex(fd, pipex));
		ft_pipe(fd, index_cmd, pipex->pid[index_cmd], pipex);
		index_cmd++;
	}
	return (0);
}

void	ft_wait_loop(t_pipex *pipex)
{
	int	index_cmd;

	index_cmd = 0;
	while (index_cmd < pipex->total_cmd)
	{
		if (!lst_index(pipex->list_cmd, index_cmd)->path_cmd)
		{
			index_cmd++;
			continue ;
		}
		waitpid(pipex->pid[index_cmd], NULL, 0);
		index_cmd++;
	}
}
