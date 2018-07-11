/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:29:55 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/11 14:00:03 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
//TODO: Handle quoting
int		mini_echo(char *argv[])
{
	argv++;
	while (*argv)
	{
		while (**argv)
		{
				ft_putchar(**argv);
			*argv += 1;
		}
		ft_putchar(' ');
		argv++;
	}
	ft_putstr("\b\n");
	return (0);
}