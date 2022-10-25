/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:42:13 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/25 13:22:58 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_identifier(char *s)
{
	int	i;

	i = 0;
	if (s && s[i])
	{
		if (s[i] == 'N' && (s[i + 1] == ' ' ||  s[i + 1] == 'O'))
			return (1);
		if (s[i] == 'S' && (s[i + 1] == ' ' ||  s[i + 1] == 'O'))
			return (2);
		if (s[i] == 'W' &&  (s[i + 1] == ' ' ||  s[i + 1] == 'E'))
			return (3);
		if (s[i] == 'E' &&  (s[i + 1] == ' ' ||  s[i + 1] == 'A'))
			return (4);
		if (s[i] == 'F' &&  s[i + 1] == ' ')
			return (5);
		if (s[i] == 'C' &&  s[i + 1] == ' ')
			return (6);
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

int	is_invalid_line(char *s)
{
	int	i;

	i = 0;
	if (is_identifier(s) != 1 && is_identifier(s) != 2 
		&& is_identifier(s) != 3 && is_identifier(s) != 4 &&
		is_identifier(s) != 5 && is_identifier(s) != 6)
	{
		while (s && s[i])
		{
			if (is_invalid(s[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

t_parse *check_identifiers(char **tab, t_parse *p)
{
	int	i;
	
	i = 0;
	while (tab[i])
	{
		if (is_identifier(tab[i]) == 1)
			p->NO += 1;
		if (is_identifier(tab[i]) == 2)
			p->SO += 1;
		if (is_identifier(tab[i]) == 3)
			p->WE += 1;
		if (is_identifier(tab[i]) == 4)
			p->EA += 1;
		if (is_identifier(tab[i]) == 5)
			p->floor += 1;
		if (is_identifier(tab[i]) == 6)
			p->ceil += 1;
		if (is_invalid_line(tab[i]) == 1)
		{
			p->inv_line = 1;
		}
		i++;
	}
	return (p);
}

char	**fill_identifiers(char **to_fill, char **tab, t_parse *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab && tab[i] && !is_map(tab[i]))
	{
		if (is_identifier(tab[i]) == 1 && p->NO == 1)
		{
			to_fill[j++] = ft_strdup(tab[i]);
		}
		else if (is_identifier(tab[i]) == 2 && p->SO == 1)
		{
			to_fill[j++] = ft_strdup(tab[i]);
		}
		else if (is_identifier(tab[i]) == 3 && p->WE == 1)
		{
			to_fill[j++] = ft_strdup(tab[i]);
		}
		else if (is_identifier(tab[i]) == 4 && p->EA == 1)
		{
			to_fill[j++] = ft_strdup(tab[i]);
		}
		else if (is_identifier(tab[i]) == 5 && p->floor == 1)
		{
			to_fill[j++] = ft_strdup(tab[i]);
		}
		else if (is_identifier(tab[i]) == 6 && p->ceil == 1)
		{
			to_fill[j++] = ft_strdup(tab[i]);
		}
		else if (!only_space(tab[i]))
		{
			to_fill[j++] = ft_strdup(tab[i]);
		}
		i++;
	}
	to_fill[j] = NULL;
	if (map_len(to_fill) != 6)
		p->flag = 1;
	// for (int k = 0; to_fill[k]; k++)
	// 	printf("%s\n", to_fill[k]);
	return (to_fill);
}

t_parse	*parse_identifiers(char **vals, t_parse *p)
{
	int	i;

	i = 0;
	while (vals && vals[i])
	{
		if (is_identifier(vals[i]) == 1 && p->NO == 1)
			p->NO = check_textures(vals[i], 2);
		else if (is_identifier(vals[i]) == 2 && p->SO == 1)
			p->SO = check_textures(vals[i], 2);
		else if (is_identifier(vals[i]) == 3 && p->WE == 1)
			p->WE = check_textures(vals[i], 2);
		else if (is_identifier(vals[i]) == 4 && p->EA == 1)
			p->EA = check_textures(vals[i], 2);
		else if (is_identifier(vals[i]) == 5 && p->floor == 1)
			p->floor = check_colors(vals[i], 2);
		else if (is_identifier(vals[i]) == 6 && p->ceil == 1)
			p->ceil = check_colors(vals[i], 2);
		i++;
	}
	return (p);
}