/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:48:01 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/22 23:47:24 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**fill_map(char **tab)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = malloc(sizeof(char *) * 100);
	if (!map)
		return (NULL);
	while (tab && tab[i])
	{
		if (is_map(tab[i]))
		{
			while (tab[i])
				map[j++] = ft_strdup(tab[i++]);
			break ;
		}
		i++;
	}
	map[j] = NULL;
	return (map);
}

int	map_closed(char *str)
{
	int	i;

	i = 0;
	while (str && is_blank(str[i]))
		i++;
	while (str && str[i] && str[i] == '1')
		i++;
	if (str && str[i] != '\0' && str[i] != '\n')
		return (0);
	return (1);
}

int	closed_sides(char *str)
{
	int i;

	i = 0;
	while (str && is_blank(str[i]))
		i++;
	if (str && str[i] && str[i] != '1')
		return (0);
	while (str && str[i] && str[i] != '\n')
		i++;
	i--;
	if (str && str[i] != '1')
		return (0);
	return (1);
}

int	turn_around(char *previous, char *line, char *next)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	while (line && line[i] != '0' && i > 0)
		i--;
	if (i >= (int)ft_strlen(previous) || i >= (int)ft_strlen(next))
		return (0);
	return (1);
}

int	invalid_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'N'
			&& s[i] != 'S' && s[i] != 'E' && s[i] != 'W' 
			&& s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
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

t_parse	*final_check(char *line, t_parse *p, int pos)
{
	if (pos == 0)
		p->no_pos = 1;
	if (pos > 1)
		p->m_pos = 1;
	if (line != 0)
		p->m_end = 1;
	return (p);
}

t_parse *parse_map(char **map, t_parse *p)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
    if (map[0] == 0)
		p->no_map = 1;
	else
	{
		while (map && map[i] && is_map(map[i]))
		{
			if ((i == 0 && !map_closed(map[i])) || !closed_sides(map[i]))
				p->map_open = 1;
			if (i > 0 && map[i + 1] != 0 && !turn_around(map[i - 1], map[i], map[i + 1]))
				p->map_open = 1;
			if (map[i + 1] == 0)
				if (!map_closed(map[i]))
					p->map_open = 1;
			if (invalid_char(map[i]))
				p->wg_char = 1;
			if (check_position(map[i]))
				pos += check_position(map[i]);
			i++;
		}
		p = final_check(map[i], p, pos);
	}
	return (p);
}