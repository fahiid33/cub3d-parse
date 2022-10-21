/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:06:17 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/21 20:10:10 by fstitou          ###   ########.fr       */
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
	return (to_fill);
}

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
				printf("%s\n", tab[i -1]);
			}
			break ;
		}
		i++;
	}
	map[j] = NULL;
	return (map);
}

int	check_textures(char *str, int i)
{
	int	fd;

	if (is_blank(str[i]))
	{
		while(is_blank(str[i]))
			i++;
	}
	printf("str = %s\n", str + i);
	fd = open(&str[i], O_RDONLY);
	
	if (fd == -1)
	{
		printf("Error\nInvalid texture path\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_last_color(char *str, int i)
{
	while (str[i] && isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (3);
}

int	check_colors(char *str, int i)
{
	if (is_blank(str[i]))
	{
		while(is_blank(str[i]))
			i++;
	}
	if (str && str[i])
		printf("atoi = %d\n", atoi(str + i));
		if (atoi(str + i) >= 0 && atoi(str + i) <= 255)
		{
			while (str[i] && isdigit(str[i]))
				i++;
			if (str[i] && str[i] == ',')
			{
				i++;
				if (atoi(str + i) >= 0 && atoi(str + i) <= 255)
				{
					while (str[i] &&isdigit(str[i]))
						i++;
					if (str[i] && str[i] == ',')
					{
						i++;
						if (atoi(str + i) >= 0 && atoi(str + i) < 255)
							return (ft_last_color(str, i));
					}
				}
			}
		}
	return (3);
}

t_parse	*parse_identifiers(char **vals, t_parse *p)
{
	int	i;

	i = 0;
	while (vals && vals[i])
	{
		if (is_identifier(vals[i]) == 1 && p->NO == 1)
			p->NO = check_textures(vals[i], 2);
		else if (is_identifier(vals[i]) == 1 && p->SO == 1)
			p->SO = check_textures(vals[i], 2);
		else if (is_identifier(vals[i]) == 1 && p->WE == 1)
			p->WE = check_textures(vals[i], 2);
		else if (is_identifier(vals[i]) == 1 && p->EA == 1)
			p->EA = check_textures(vals[i], 2);
		else if (is_identifier(vals[i]) == 1 && p->floor == 1)
			p->floor = check_colors(vals[i], 2);
		else if (is_identifier(vals[i]) == 1 && p->ceil == 1)
			p->ceil = check_colors(vals[i], 2);
		printf("%d-- %d--%d--%d\n", p->NO, p->SO, p->WE, p->EA);
		i++;
	}
	return (p);
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
	
	// parse = parse_map(map, parse);
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