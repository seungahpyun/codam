/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 07:10:55 by spyun         #+#    #+#                 */
/*   Updated: 2024/12/12 09:24:57 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdbool.h>
# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

typedef struct s_pipex
{
	int		cmd_count;
	int		pipe_count;
	int		**pipes;
	pid_t	*pids;
	char	*infile;
	char	*outfile;
	char	**cmds;
	bool	here_doc;
	char	*limiter;
}	t_pipex;

typedef struct s_parse
{
	char	**args;
	int		i;
	int		arg_count;
	int		error;
}	t_parse;

void	init_pipex(t_pipex *pipex, int argc, char **argv);
void	create_pipes(t_pipex *pipex);
void	execute_commands(t_pipex *pipex, char **envp);
void	cleanup_pipex(t_pipex *pipex);
void	error_exit(char *msg, t_pipex *pipex);
void	perror_exit(const char *msg, t_pipex *pipex);
char	*find_path(char *cmd, char **envp);
char	**parse_cmd(char *str);
void	free_array(char **array);
void	handle_here_doc(t_pipex *pipex);
void	execute_cmd(char *cmd, char **envp, t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
int		is_quote(char c);
char	*parse_quoted_arg(char *str, int *i);
char	*parse_non_quoted_arg(char *str, int *i);
char	**init_args(char *str, int *arg_count);

#endif
