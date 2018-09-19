/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:16:43 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/19 14:31:36 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	call_handler(char *argv[], char ***env)
{
	if (ft_strequ(argv[0], "echo"))
		mini_echo(argv);
	else if (ft_strequ(argv[0], "cd"))
		mini_cd(argv, env);
	else if (ft_strequ(argv[0], "setenv"))
		mini_setenv(argv, env);
	else if (ft_strequ(argv[0], "unsetenv"))
		mini_unsetenv(argv, env);
	else if (ft_strequ(argv[0], "env"))
		mini_env(*env);
	else if (ft_strequ(argv[0], "exit"))
	{
		ft_tabfree(*env);
		exit(argv[1] ? ft_atoi(argv[1]) : 0);
	}
	else
		mini_launch(argv, *env);
}

int			input_handler(const char *input, char ***env)
{
	char		**args;

	args = ft_strqotsplit(input);
	if (!args)
		return (0);
	substitutions(args, *env);
	call_handler(args, env);
	ft_tabfree(args);
	free(args);
	return (0);
}

int			main(int argc, char *argv[], char *envv[])
{
	char	*input;
	char	**env;

	(void)(argv && argc);
	env = ft_tabdup(envv);
	ft_putstr("$>");
	input = NULL;
	while (1)
	{
		get_next_line(0, &input);
		input_handler(input, &env);
		free(input);
		input = NULL;
		ft_putstr("$>");
	}
}
