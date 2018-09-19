/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:29:55 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/19 14:25:29 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	mini_echo(char *argv[])
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("\b\n");
}
