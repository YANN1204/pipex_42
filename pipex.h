/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:35:16 by yrio              #+#    #+#             */
/*   Updated: 2024/01/31 15:28:34 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list {
	int				index;
	char			*cmd;
	char			*path_cmd;
	char			**spliting_cmd_args;
	struct s_list	*next;
}				t_list;

typedef struct s_pipex {
	struct s_list	*list_cmd;
	char			*infile_name;
	char			*outfile_name;
	char			**env;
	int				*pid;
	int				total_cmd;
	int				fd_infile;
	int				fd_outfile;
	int				error_init;
	int				recup;
}				t_pipex;

int		ft_putchar(char c);
int		ft_putstr(char const *s);
int		ft_putnbr(int n);
int		ft_printf(const char *format, ...);
int		ft_putunsignednbr(unsigned int n);
int		ft_print_ptr(void *ptr, char c);
int		ft_print_hexa(void *ptr, char c);

size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*test(char *s1);
char	*ft_strjoin2(char *s1, char *s2);	
char	*get_next_line(int fd, char *delimiteur);

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char const *s, int fd);

void	lstadd_back(t_list *new, t_list *lst_cmd);
void	lstclear(t_list *lst);
t_list	*lst_index(t_list *lst, int index);

char	**get_paths(char **env, t_pipex *pipex);
char	**free_split(char **char_tab);
char	*check_cmd(char *cmd, char **path_split);
t_list	*lst_new(int tmp, char **argv, t_pipex *pipex);
void	init_pipex_standard(int argc, char **argv, t_pipex *pipex);
void	init_pipex_here_doc(int argc, char **argv, t_pipex *pipex);
void	exec_child(int *fd, t_pipex *pipex, int index_cmd);
int		close_pipex(int *fd, t_pipex *pipex);
int		ft_pipe(int *fd, int index_cmd, int pid, t_pipex *pipex);
int		ft_pipe_here_doc(char **argv, int *fd, t_pipex *pipex);
int		ft_pipe_loop(int index_cmd, int *fd, t_pipex *pipex);
void	ft_wait_loop(t_pipex *pipex);
void	redirection_empty_fd(int index_cmd, char **path_split, t_pipex *pipex);
int		ft_strcmp(const char *s1, const char *s2);
char	**splitting_path(char *path, char **path_split, t_pipex *pipex);

#endif