/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:48:01 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/23 12:53:31 by fstitou          ###   ########.fr       */
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
			{
				map[j++] = ft_strdup(tab[i++]);
			}
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
	if (i >= (int)ft_strlen(previous) - 1 || i >= (int)ft_strlen(next) - 1)
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
			&& s[i] != ' ' && s[i] != '\n')
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

int	not_in_end(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while ((line[i] && line[i] == '\n') || line[i] == ' ')
		i++;
	if (line && line[i])
		return (0);
	return (1);
	
}

t_parse	*final_check(char *line, t_parse *p, int pos)
{
	if (pos == 0)
		p->no_pos = 1;
	if (pos > 1)
		p->m_pos = 1;
	if (!not_in_end(line))
		p->m_end = 1;
	return (p);
}

int	internal_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
			printf("%s", map[i]);
		while (map[i][j])
		{
			if (i == 0 && j > 0 && map[i][j] == '0' && map[i][j + 1] == ' '
				&& map[i][j - 1] == ' ')
			{
				return (0);
			}
			if (map[i + 1] == 0 && map[i][j] == '0' && map[i][j + 1] == ' ')
			{
				return (0);
			}
			if (i > 0 && map[i][j] == '0' && (map[i - 1][j] == ' ' 
				|| map[i + 1][j] == ' '))
			{
				return (0);
			}	
			j++;
		}
		i++;
	}
	return (1);
}

t_parse *parse_map(char **map, t_parse *p)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	if (internal_check(map) == 0)
	{
		printf("WEEe\n");
		p->map_open = 1;
	}
	if (map[0] == 0)
		p->no_map = 1;
	else
	{
		while (map && map[i] && is_map(map[i]))
		{
			if ((i == 0 && !map_closed(map[i])) || !closed_sides(map[i]))
				p->map_open = 1;
			// if (i > 0 && map[i + 1] != 0 && !turn_around(map[i - 1], map[i], map[i + 1]))
			// 	p->map_open = 1;
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