/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:07:26 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/01 22:27:11 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_parse	*init_vals(t_parse *p)
{
	p->no = 0;
	p->so = 0;
	p->we = 0;
	p->ea = 0;
	p->floor = 0;
	p->ceil = 0;
	p->inv_line = 0;
	p->no_pos = 0;
	p->no_map = 0;
	p->wg_char = 0;
	p->map_open = 0;
	p->m_pos = 0;
	p->m_end = 0;
	p->flag = 0;
	return (p);
}

int	check_file(char *file)
{
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = strrchr(file, '.');
	if (str == NULL || strcmp(str, ".cub") != 0 || !strcmp(file, ".cub"))
		return (-1);
	return (fd);
}

int	is_map(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (is_blank(s[i]))
	{
		while (is_blank(s[i]))
			i++;
	}
	if (s[i] == '1' || s[i] == '0')
		return (1);
	return (0);
}

int	map_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (is_blank(str[i]))
		i++;
	while (str && is_digit(str[i]))
		i++;
	while (is_blank(str[i]))
		i++;
	if (is_digit(str[i]))
		return (0);
	return (1);
}
