/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:51:34 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/19 14:31:04 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*abs_to_rel(char *old, char **env, int reverse)
{
	const char	*find = reverse ? "~" : ft_getenv("HOME", env);
	const char	*replace = (!reverse) ? "~" : ft_getenv("HOME", env);

	if (!env || !ft_getenv("HOME", env))
		return (ft_strdup(old));
	if (!ft_strncmp(old, find, ft_strlen(find)))
		return (ft_strjoin(replace, old + ft_strlen(find)));
	return (ft_strdup(old));
}

void	substitutions(char **tab, char **env)
{
	while (*tab)
	{
		if (**tab == '~')
			ft_swapnfree((void **)tab, abs_to_rel(*tab, env, 1));
		if (**tab == '$')
			ft_swapnfree((void **)tab, ft_getenv(*tab + 1, env) ?
				ft_strdup(ft_getenv(*tab + 1, env)) : ft_strdup(""));
		tab++;
	}
}
