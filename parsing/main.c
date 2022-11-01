/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:06:17 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/01 22:26:14 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	to_parse(char **tab)
{
	t_parse	*parse;
	char	**identifiers;
	char	**map;

	parse = malloc(sizeof(t_parse));
	identifiers = malloc(sizeof(char *) * 8);
	parse = init_vals(parse);
	parse = check_identifiers(tab, parse);
	identifiers = fill_identifiers(identifiers, tab, parse);
	map = fill_map(tab, 0);
	parse = parse_identifiers(identifiers, parse);
	parse = parse_map(map, parse);
	free_tab(identifiers);
	free_tab(map);
	if (print_errors(parse) == 1)
	{
		free(parse);
		return (1);
	}
	free(parse);
	return (0);
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
			break ;
		tab[i] = ft_strndup(line, len);
		free(line);
		i++;
	}
	free(line);
	tab[i] = NULL;
	return (tab);
}

int	main(int ac, char **av)
{
	char	**tab;
	int		fd;

	fd = 0;
	(void)ac;
	tab = init_file(av[1], fd);
	if (to_parse(tab) != 0)
	{
		close(fd);
		free_tab(tab);
		return (0);
	}
	fill_infos(tab);
	return (0);
}
