/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:42:13 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/22 05:43:44 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_identifier(char *s)
{
	int	i;

	i = 0;
	if (s && s[i])
	{
		if (s[i] == 'N' && s[i + 1] == 'O')
			return (1);
		if (s[i] == 'S' && s[i + 1] == 'O')
			return (2);
		if (s[i] == 'W' && s[i + 1] == 'E')
			return (3);
		if (s[i] == 'E' && s[i + 1] == 'A')
			return (4);
		if (s[i] == 'F' && s[i + 1] == ' ')
			return (5);
		if (s[i] == 'C' && s[i + 1] == ' ')
			return (6);
		if (is_invalid(s[i]))
			return (7);
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
			p->NO = 1;
		else if (is_identifier(tab[i]) == 2)
			p->SO = 1;
		else if (is_identifier(tab[i]) == 3)
			p->WE = 1;
		else if (is_identifier(tab[i]) == 4)
			p->EA = 1;
		else if (is_identifier(tab[i]) == 5)
			p->floor = 1;
		else if (is_identifier(tab[i]) == 6)
			p->ceil = 1;
		else if (is_identifier(tab[i]) == 7)
			p->inv_line = 1;
		i++;
	}
	printf("init == p->NO = %d p->SO = %d  p->WE = %d p->EA = %d  p->floor = %d p->ceil = %d\n", p->NO, p->SO, p->WE,p->EA, p->floor, p->ceil);
	return (p);
}

char	**fill_identifiers(char **to_fill, char **tab, t_parse *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (is_identifier(tab[i]) == 1 && p->NO == 1)
			to_fill[j++] = ft_strdup(tab[i]);
		else if (is_identifier(tab[i]) == 2 && p->SO == 1)
			to_fill[j++] = ft_strdup(tab[i]);
		else if (is_identifier(tab[i]) == 3 && p->WE == 1)
			to_fill[j++] = ft_strdup(tab[i]);
		else if (is_identifier(tab[i]) == 4 && p->EA == 1)
			to_fill[j++] = ft_strdup(tab[i]);
		else if (is_identifier(tab[i]) == 5 && p->floor == 1)
			to_fill[j++] = ft_strdup(tab[i]);
		else if (is_identifier(tab[i]) == 6 && p->ceil == 1)
			to_fill[j++] = ft_strdup(tab[i]);
		i++;
	}
	
	to_fill[j] = NULL;
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
	printf("parse == p->NO = %d p->SO = %d  p->WE = %d p->EA = %d  p->floor = %d p->ceil = %d\n", p->NO, p->SO, p->WE,p->EA, p->floor, p->ceil);
	system("leaks cub3D");
	return (p);
}