/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:35:57 by yrio              #+#    #+#             */
/*   Updated: 2024/01/31 15:21:44 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **env, t_pipex *pipex)
{
	char	**path_split;
	char	*path;
	int		tmp;
	int		error_fd[2];

	tmp = 0;
	path = NULL;
	path_split = NULL;
	while (env[tmp])
	{
		if (!ft_strncmp(env[tmp], "PATH=", 5))
		{
			path = ft_substr(env[tmp], 5, ft_strlen(env[tmp]) - 5);
			if (!path)
			{
				pipex->error_init = 1;
				close_pipex(error_fd, pipex);
			}
		}
		tmp++;
	}
	path_split = splitting_path(path, path_split, pipex);
	free(path);
	return (path_split);
}

char	**free_split(char **char_tab)
{
	int	tmp;

	tmp = 0;
	while (char_tab[tmp])
		free(char_tab[tmp++]);
	free(char_tab);
	return (NULL);
}

char	*check_cmd(char *cmd, char **path_split)
{
	char	*path_str;
	int		tmp;

	if (cmd == NULL)
	{
		write(2, "Command '' not found\n", 22);
		return (NULL);
	}
	tmp = 0;
	while (path_split[tmp])
	{
		path_str = ft_strjoin2(ft_strjoin(path_split[tmp], "/"), cmd);
		if (access(path_str, F_OK) == 0)
		{
			free_split(path_split);
			return (path_str);
		}
		free(path_str);
		tmp++;
	}
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 21);
	free_split(path_split);
	return (NULL);
}

void	init_pipex(int argc, char **argv, char **env, t_pipex *pipex)
{
	t_list	*lst;
	t_list	*new;
	int		*pid;
	int		tmp;

	pipex->env = env;
	pipex->error_init = 0;
	if (!ft_strcmp(argv[1], "here_doc"))
		init_pipex_here_doc(argc, argv, pipex);
	else
		init_pipex_standard(argc, argv, pipex);
	tmp = 0;
	lst = lst_new(tmp, argv, pipex);
	pipex->list_cmd = lst;
	tmp++;
	while (tmp < pipex->total_cmd)
	{
		new = lst_new(tmp, argv, pipex);
		lstadd_back(new, lst);
		tmp++;
	}
	pid = malloc((pipex->total_cmd) * sizeof(int));
	pipex->pid = pid;
	if (!pipex->pid)
		pipex->error_init = 1;
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		fd[2];
	int		index_cmd;

	if (!env[0] || argc < 5 || (ft_strncmp(argv[1], \
		"here_doc", ft_strlen("here_doc")) == 0 && argc < 6))
		exit(0);
	init_pipex(argc, argv, env, &pipex);
	if (pipex.error_init == 1)
		close_pipex(fd, &pipex);
	if (!ft_strcmp(argv[1], "here_doc"))
		ft_pipe_here_doc(argv, fd, &pipex);
	else
		if (dup2(pipex.fd_infile, 0) == -1)
			close_pipex(fd, &pipex);
	index_cmd = 0;
	ft_pipe_loop(index_cmd, fd, &pipex);
	ft_wait_loop(&pipex);
	close_pipex(fd, &pipex);
	return (0);
}
