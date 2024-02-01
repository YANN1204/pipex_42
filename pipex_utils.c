/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:31:15 by yrio              #+#    #+#             */
/*   Updated: 2024/01/31 12:43:38 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*lst_new(int tmp, char **argv, t_pipex *pipex)
{
	t_list	*new;
	int		fd_error[2];

	new = malloc(sizeof(t_list));
	if (!new)
	{	
		pipex->error_init = 1;
		close_pipex(fd_error, pipex);
	}
	new->index = tmp;
	if (!ft_strncmp(argv[1], "here_doc", 8))
		new->spliting_cmd_args = ft_split(argv[tmp + 3], ' ');
	else
		new->spliting_cmd_args = ft_split(argv[tmp + 2], ' ');
	if (!new->spliting_cmd_args)
	{
		pipex->error_init = 1;
		close_pipex(fd_error, pipex);
	}
	new->cmd = new->spliting_cmd_args[0];
	new->path_cmd = 0;
	new->next = NULL;
	return (new);
}

void	init_pipex_standard(int argc, char **argv, t_pipex *pipex)
{
	pipex->total_cmd = argc - 3;
	pipex->infile_name = argv[1];
	pipex->outfile_name = argv[argc - 1];
	pipex->recup = -1;
	pipex->fd_infile = open(pipex->infile_name, O_RDONLY, 0644);
	pipex->fd_outfile = open(pipex->outfile_name, O_CREAT | \
		O_RDWR | O_TRUNC, 0644);
	if (pipex->fd_infile == -1 || pipex->fd_outfile == -1)
		pipex->error_init = 1;
}

void	init_pipex_here_doc(int argc, char **argv, t_pipex *pipex)
{
	pipex->total_cmd = argc - 4;
	pipex->infile_name = argv[1];
	pipex->outfile_name = argv[argc - 1];
	pipex->recup = -1;
	pipex->fd_infile = -1;
	pipex->fd_outfile = open(pipex->outfile_name, O_CREAT | \
	O_RDWR | O_APPEND, 0644);
	if (pipex->fd_outfile == -1)
		pipex->error_init = 1;
}

void	exec_child(int *fd, t_pipex *pipex, int index_cmd)
{
	int		result;
	t_list	*cmd;

	close(fd[1]);
	close(fd[0]);
	if (pipex->recup != -1)
		close(pipex->recup);
	cmd = lst_index(pipex->list_cmd, index_cmd);
	result = execve(cmd->path_cmd, cmd->spliting_cmd_args, pipex->env);
	if (result == -1)
		close_pipex(fd, pipex);
}

int	close_pipex(int *fd, t_pipex *pipex)
{
	wait(NULL);
	if (pipex->error_init == 0)
		close(fd[0]);
	if (pipex->error_init == 0)
		close(fd[1]);
	if (ft_strcmp(pipex->infile_name, "here_doc") \
		&& pipex->fd_infile > 0)
		close(pipex->fd_infile);
	if (pipex->pid)
		free(pipex->pid);
	if (pipex->fd_outfile != -1)
		close(pipex->fd_outfile);
	lstclear(pipex->list_cmd);
	exit(0);
	return (0);
}
