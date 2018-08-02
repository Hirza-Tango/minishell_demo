/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_launch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:46:46 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/02 15:54:45 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*exec_location(char *path, char **env)
{
	char	**path_env;
	char	**dup;
	char	*exec;

	if (!access(path, F_OK))
		return (ft_strdup(path));
	path_env = ft_strsplit(ft_getenv("PATH", env), ':');
	dup = path_env;
	if (!dup)
		return (NULL);
	while (*dup)
	{
		if (!(exec = ft_strmjoin(3, *dup, "/", path)))
			break ;
		if (!access(exec, F_OK))
		{
			free(exec);
			break ;
		}
		free(exec);
		exec = NULL;
		dup++;
	}
	ft_tabfree(path_env);
	free(path_env);
	return (exec);
}

int			mini_launch(char *argv[], char *env[])
{
	char	*exec;
	pid_t	pid;
	int		status;

	status = 0;
	exec = exec_location(argv[0], env);
	if (!exec)
		return (ft_puterr(SHELL_NAME, argv[0], "command not found", 1));
	if (access(exec, X_OK))
		return (ft_puterr(SHELL_NAME, argv[0], "permission denied", 1));
	if ((pid = fork()))
	{
		wait4(pid, &status, 0, NULL);
		free(exec);
		return (status);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		return (execve(exec, argv, env));
	}
}
