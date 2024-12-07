/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 09:51:45 by spyun         #+#    #+#                 */
/*   Updated: 2024/12/05 16:23:36 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

char 	**parse_cmd(char *str);
void	error_exit(int status);
char	*find_path(char *cmd, char **envp);
void	execute_cmd(char *cmd, char **envp);
void	free_array(char **array);

void	child_process(char **argv, char **envp, int *pipe_fd);
void	parent_process(char **argv, char **envp, int *pipe_fd);
void	create_pipe(char **argv, char **envp);

void	check_args(int argc, char **argv);
void	check_infile(char *infile);
void	check_outfile(char *outfile);

#endif
