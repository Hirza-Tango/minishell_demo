/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:21:15 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/19 13:37:12 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	mini_setenv(char *argv[], char ***env)
{
	ft_setenv(argv[1], argv[2], env);
}
