/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:04:50 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/19 14:33:43 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <get_next_line.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>

void		mini_echo(char *argv[]);
void		mini_cd(char *argv[], char ***env);
void		mini_env(char **env);
void		mini_setenv(char *argv[], char ***env);
void		mini_unsetenv(char *argv[], char ***env);
void		mini_launch(char *argv[], char **env);

const char	*ft_getenv(const char *name, char **env);
int			ft_setenv(const char *name, const char *value, char ***env);
int			ft_unsetenv(const char *name, char ***env);
void		substitutions(char **tab, char **env);

#endif
