/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:06:17 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/22 23:47:44 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
	return 0;
}

int main(int ac, char **av)
{
    char *line;
    int i;
    char **tab;
	int	fd;

	(void)ac;
	i = 0;
	tab = malloc(sizeof(char *) * 100);
    fd = check_file(av[1]);
    if (fd == 0)
		errors(1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		tab[i] = line;
		i++;
	}
	tab[i] = NULL;
	if (to_parse(tab) == 0)
		printf("OK\n");
	return 0;
}