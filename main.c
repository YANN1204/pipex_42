/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:35:57 by yrio              #+#    #+#             */
/*   Updated: 2024/01/29 11:34:27 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **env)
{
	char	**path_split;
	char	*path;
	int		tmp;

	tmp = 0;
	while (env[tmp])
	{
		if (!ft_strncmp(env[tmp], "PATH=", 5))
			path = ft_substr(env[tmp], 5, ft_strlen(env[tmp]) - 5);
		tmp++;
	}
	path_split = ft_split(path, ':');
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

char	*check_cmd(char *cmd, t_pipex *pipex)
{
	char	**path_split;
	char	*path_str;
	int		tmp;

	if (cmd == NULL)
	{
		write(2, "Command '' not found\n", 22);
		return (NULL);
	}
	tmp = 0;
	path_split = get_paths(pipex->env);
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
	if (!ft_strncmp(argv[1], "here_doc", 8))
		init_pipex_here_doc(argc, argv, env, pipex);
	else
		init_pipex_standard(argc, argv, env, pipex);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		fd[2];
	int		index_cmd;

	if (argc < 5 || !env[0] || (ft_strncmp(argv[1], \
		"here_doc", ft_strlen("here_doc")) == 0 && argc < 6))
		exit(0);
	init_pipex(argc, argv, env, &pipex);
	if (pipex.error_init == 1)
		close_pipex(fd, &pipex);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		ft_pipe_here_doc(argv, fd, &pipex);
	else
		if (dup2(pipex.fd_infile, 0) == -1)
			close_pipex(fd, &pipex);
	index_cmd = 0;
	while (index_cmd < pipex.total_cmd)
	{		
		lst_index(pipex.list_cmd, index_cmd)->path_cmd = \
			check_cmd(lst_index(pipex.list_cmd, index_cmd)->cmd, &pipex);
		if (!lst_index(pipex.list_cmd, index_cmd)->path_cmd)
		{
			index_cmd++;
			if (ft_strncmp(pipex.infile_name, "here_doc", 8) \
				&& pipex.fd_infile != -1)
			close(pipex.fd_infile);
			dup2(pipex.recup, 0);
			pipex.fd_infile = 0;
			continue ;
		}
		if (pipe(fd) == -1)
			return (close_pipex(fd, &pipex));
		pipex.pid[index_cmd] = fork();
		ft_pipe(fd, index_cmd, pipex.pid[index_cmd], &pipex);
		index_cmd++;
	}
	index_cmd = 0;
	while (index_cmd < pipex.total_cmd)
	{
		if (!lst_index(pipex.list_cmd, index_cmd)->path_cmd)
		{
			index_cmd++;
			continue ;
		}
		waitpid(pipex.pid[index_cmd], NULL, 0);
		index_cmd++;	
	}
	close_pipex(fd, &pipex);
	return (0);
}
