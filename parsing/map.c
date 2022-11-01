/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:48:01 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/01 23:05:13 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**fill_map(char **tab, int flag)
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
			while (tab[i] && is_map(tab[i]) && flag)
				map[j++] = ft_strdup(tab[i++]);
			while (tab[i] && !flag)
				map[j++] = ft_strdup(tab[i++]);
			break ;
		}
		i++;
	}
	map[j] = NULL;
	return (map);
}

int	closed_sides(char *str)
{
	int	i;

	i = 0;
	while (str && is_blank(str[i]))
		i++;
	if (str && str[i] && str[i] != '1')
		return (0);
	while (str && str[i])
		i++;
	i--;
	if (is_blank(str[i]))
		while (is_blank(str[i]))
			i--;
	if (str && str[i] != '1')
		return (0);
	return (1);
}

t_parse	*final_check(char **rest, t_parse *p, int pos)
{
	int	i;

	i = 0;
	if (pos == 0 && !p->flag)
		p->no_pos = 1;
	if (pos > 1 && !p->flag)
		p->m_pos = 1;
	while (rest[i] && !p->flag)
	{
		if (rest[i][0] != '\0' && !only_space(rest[i]))
		{
			p->m_end = 1;
			break ;
		}
		i++;
	}
	return (p);
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
			if (i > 0 && map[i][j] == '0' && (map[i][j + 1] == ' '
				|| map[i][j - 1] == ' '))
				return (0);
			else if (i > 0 && is_map(map[i + 1]) && map[i][j] == '0'
				&& (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
				|| map[i - 1][j] == '\0' || map[i + 1][j] == '\0'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_parse	*m_check(char **map, t_parse *p)
{
	if (!p->flag)
		if (!internal_check(map))
			p->map_open = 1;
	return (p);
}

t_parse	*parse_map(char **map, t_parse *p)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	if (map[0] == 0)
		p->no_map = 1;
	else
	{	
		while (map && map[i] && is_map(map[i]) && !p->flag)
		{
			if ((i == 0 && !map_closed(map[i])))
				p->map_open = 1;
			if (i > 0 && map[i + 1] != 0 && !closed_sides(map[i]))
				p->map_open = 1;
			if (map[i + 1] == 0 || !is_map(map[i + 1]))
				if (!map_closed(map[i]))
					p->map_open = 1;
			if (invalid_char(map[i]))
				p->wg_char = 1;
			if (check_position(map[i]))
				pos += check_position(map[i]);
			i++;
		}
		p = final_check(map + i, p, pos);
	}
	return (m_check(map, p));
}
