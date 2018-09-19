/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_launch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:46:46 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/19 14:32:32 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*exec_location(char *path, char **env)
{
	char	**path_env;
	char	*exec;
	size_t	i;

	if (!access(path, F_OK))
		return (ft_strdup(path));
	path_env = ft_strsplit(ft_getenv("PATH", env), ':');
	if (!path_env)
		return (NULL);
	i = 0;
	while (path_env[i])
	{
		exec = ft_strmjoin(3, path_env[i], "/", path);
		if (!access(exec, F_OK))
			break ;
		free(exec);
		exec = NULL;
		i++;
	}
	ft_tabfree(path_env);
	free(path_env);
	return (exec);
}

void		mini_launch(char *argv[], char *env[])
{
	char	*exec;

	exec = exec_location(argv[0], env);
	if (!exec)
	{
		ft_putendl("File not found!");
		return ;
	}
	if (fork())
	{
		wait(NULL);
		free(exec);
	}
	else
		execve(exec, argv, env);
}
