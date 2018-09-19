/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unsetenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:31:46 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/19 13:37:54 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	mini_unsetenv(char *argv[], char ***env)
{
	if (ft_getenv(argv[1], *env))
		ft_unsetenv(argv[1], env);
}
