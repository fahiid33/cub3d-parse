/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:26:27 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/02 20:28:03 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	map_y(char **map)
{
	int		i;
	size_t	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		if (y < strlen(map[i]))
			y = strlen(map[i]);
		i++;
	}
	return (y);
}

char	get_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
				return (map[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_player(char p)
{
	if (p == 'N' || p == 'S' || p == 'E' || p == 'W')
		return (1);
	return (0);
}

int	internal_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i] && is_map(map[i]))
	{
		j = 0;
		while (map[i][j])
		{
			if (i > 0 && (map[i][j] == '0' || is_player(map[i][j])) && (map[i][j + 1] == ' '
				|| map[i][j - 1] == ' '))
				return (0);
			else if (i > 0 && is_map(map[i + 1]) && (map[i][j] == '0' || is_player(map[i][j]))
				&& (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
				|| map[i - 1][j] == '\0' || map[i + 1][j] == '\0'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
