/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:52:21 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/01 22:39:30 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_position(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
			count++;
		i++;
	}
	return (count);
}

int	invalid_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '0'
			&& s[i] != ' ' && s[i] != 'N'
			&& s[i] != 'E' && s[i] != 'S'
			&& s[i] != 'W')
			return (1);
		i++;
	}
	return (0);
}

int	is_invalid(char c)
{
	if (c != '\0' && c != '1' && c != '0'
		&& c != ' ' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E')
		return (1);
	return (0);
}

int	*get_player_position(char **str)
{
	int	*tab;

	tab = malloc(8);
	tab[0] = 0;
	tab[1] = 0;
	while (str[tab[0]])
	{
		tab[1] = 0;
		while (str[tab[0]][tab[1]])
		{
			if (str[tab[0]][tab[1]] == 'N' || str[tab[0]][tab[1]] == 'S'
				|| str[tab[0]][tab[1]] == 'W' || str[tab[0]][tab[1]] == 'E')
				return (tab);
			tab[1]++;
		}
		tab[0]++;
	}
	exit(0);
	return (NULL);
}

int	map_closed(char *str)
{
	int	i;

	i = 0;
	while (str && is_blank(str[i]))
		i++;
	while (str && str[i] && (str[i] == '1' || str[i] == ' '))
		i++;
	if (str && str[i] != '\0')
	{
		return (0);
	}
	return (1);
}
