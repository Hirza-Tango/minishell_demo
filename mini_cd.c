/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:54:46 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/19 14:22:28 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		mini_cd(char *argv[], char ***env)
{
	char		*pwd;

	pwd = getcwd(NULL, 0);
	if (!argv[1])
		chdir(ft_getenv("HOME", *env));
	else if (ft_strequ(argv[1], "-"))
		chdir(ft_getenv("OLDPWD", *env));
	else
		chdir(argv[1]);
	ft_setenv("OLDPWD", pwd, env);
	free(pwd);
	pwd = getcwd(NULL, 0);
	ft_setenv("PWD", pwd, env);
	free(pwd);
}
