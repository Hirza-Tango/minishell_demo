/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:54:46 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/13 15:16:16 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	is_dir(const char *path)
{
	struct stat	s;

	stat(path, &s);
	if ((s.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

//	TODO: handle quoting
int		mini_cd(char *argv[], char *env[])
{
	const char	*command = SHELL_NAME ": cd";
	const char	*oldpwd = getcwd(NULL, 0);

	if (!argv[1])
	{
		if ((chdir(ft_getenv("HOME", env))))
			return (ft_puterr(command, "", "HOME not set", 1));
	}
	else if (ft_strlen(argv[1]) > MAXNAMLEN)
		return (ft_puterr(command, argv[1], "File name too long", 1));
	else if (ft_strequ(argv[1], "-"))
	{
		if (chdir(ft_getenv("OLDPWD", env)))
			return (ft_puterr(command, "", "OLDPWD not set", 1));
	}
	else if (chdir(argv[1]))
	{
		if (access(argv[1], F_OK))
			return (ft_puterr(command, argv[1], "No such file or directory", 1));
		if (access(argv[1], R_OK))
			return (ft_puterr(command, argv[1], "Permission denied", 1));
		if (!is_dir(argv[1]))
			return (ft_puterr(command, argv[1], "Not a directory", 1));
		return (ft_puterr(command, argv[1], "System error", 1));
		//TODO: Cases:
		// System:
		//		EFAULT:	Path is outside process adress space
		//		EIO:	IO Error
		//		ELOOP:	Symlink loop
	}
	ft_setenv("OLDPWD", oldpwd, 1, env);
	return (0);
}
