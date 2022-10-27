/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:06:17 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/27 07:22:34 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"


int	print_errors(t_parse *p)
{
	if (p->NO != 1 || p->SO != 1 || p->WE != 1 
		|| p->EA != 1 || p->ceil != 1 || p->floor != 1 || p->flag != 0
		|| p->inv_line != 0 || p->m_end != 0 != p->map_open != 0 || p->no_map != 0
		|| p->no_pos != 0 || p->m_pos != 0 || p->wg_char != 0)
		printf("Error\n");
	if (p->NO == -1 || p->SO == -1 || p->EA == -1 || p->WE == -1)
	{
		printf("Invalid texture(s) file\n");
		return (1);
	}
	if (p->NO > 1 || p->SO > 1|| p->EA > 1 || p->WE > 1 || p->floor > 1 | p->ceil > 1)
	{
		printf("Duplication in the identifiers\n");
		return (1);
	}
	if (p->floor == 0 || p->ceil == 0)
	{
		printf("Floor or Ceiling arguments are invalid\n");
		return (1);
	}
	if (p->no_pos == 1 || p->m_pos == 1)
	{
		printf("There is no player or more than one player\n");
		return (1);
	}
	if (p->wg_char == 1)
	{
		printf("Wrong char in the map\n");
		return (1);
	}
	if (p->map_open == 1)
	{
		printf("The map is open\n");
		return (1);
	}
	if (p->m_end == 1)
	{
		printf("The map is not at end of file\n");
		return (1);
	}
	if (p->no_map == 1)
	{
		printf("There is no map int the file\n");
		return (1);
	}
	if (p->inv_line == 1 || p->flag == 1)
	{
		printf("There is an invalid line or a line not in the right place\n");
		return (1);
	}
	return (0);
}

int	to_parse(char **tab)
{
	t_parse *parse;
	char	**identifiers;
	char	**map;

	parse = malloc(sizeof(t_parse));
	identifiers = malloc(sizeof(char *) * 8);
	parse = init_vals(parse);
	parse = check_identifiers(tab, parse);
	identifiers = fill_identifiers(identifiers, tab, parse);
	map = fill_map(tab);
	parse = parse_identifiers(identifiers, parse);
	parse = parse_map(map, parse);
	printf("NO == %d So == %d EA == %d WE == %d", parse->NO, parse->SO, parse->EA, parse->WE);
	printf(" inv_line = %d m_end = %d m_pos = %d map_open = %d ", parse->inv_line, parse->m_end, 
	parse->m_pos, parse->map_open);
	printf("ceiling = %d floor = %d ", parse->ceil, parse->floor);
	printf("no_map = %d no_pos = %d wg_char = %d m_end = %d\n", parse->no_map, 
	parse->no_pos, parse->wg_char , parse->m_end);
	printf("return == %d\n",print_errors(parse));
	return 0;
}

char	**init_file(char *file, int fd)
{
	char	*line;
	int		len;
	int		i;
	char	**tab;

	i = 0;
	fd = check_file(file);
    if (fd == -1)
		errors(1);
	tab = malloc(sizeof(char *) * 100);
	while (1)
	{
		line = get_next_line(fd);
		len = ft_int_strchr(line, '\n');
		if (line == NULL || len == -1)
			break;
		tab[i] = ft_strndup(line, len);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int main(int ac, char **av)
{
    char	**tab;
	int		fd;

	fd = 0;
	(void)ac;
	tab = init_file(av[1], fd);
	if (to_parse(tab) == 0)
	{
		printf("OK\n");
	}
	return 0;
}