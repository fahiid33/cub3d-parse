/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:01:17 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/03 02:02:08 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_texture(char *str)
{
	int		i;
	int		len;
	char	*file;

	i = 0;
	if (is_blank(str[i]))
		while (is_blank(str[i]))
			i++;
	len = get_len(str + i);
	file = ft_substr(str + i, 0, len);
	return (file);
}

int	get_color(char *str)
{
	int	color;
	int	red;
	int	green;
	int	blue;
	int	i;

	i = 0;
	if (is_blank(str[i]))
		while (is_blank(str[i]))
			i++;
	red = atoi(str + i);
	while (is_digit(str[i]) || is_blank(str[i]))
		i++;
	i++;
	green = atoi(str + i);
	while (is_digit(str[i]) || is_blank(str[i]))
		i++;
	i++;
	blue = atoi(str + i);
	color = (red << 16) + (green << 8) + blue;
	return (color);
}

void	print_struct(t_info *info)
{
	printf("no: %s\n", info->no);
	printf("so: %s\n", info->so);
	printf("we: %s\n", info->we);
	printf("ea: %s\n", info->ea);
	printf("F: %d\n", info->floor);
	printf("C: %d\n", info->ceil);
	printf("x = %d | y = %d\n", info->x, info->y);
	printf("map_x = %d | map_y = %d\n", info->map_x, info->map_y);
	printf("map_p = %c\n", info->dir);
	for (int k = 0; info->map[k]; k++)
		printf("map[%d] = %s\n", k, info->map[k]);
	for (int j = 0; info->map[j]; j++)
		printf("new_map[%d] = %s\n", j, info->new_map[j]);
	
}

// char	**get_themap(char **map, int len)
// {
	
// }

char	*fill_spaces(char *map_x, char *to_fill, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map_x[i])
	{
		to_fill[j] = map_x[i];
		j++;
		i++;	
	}
	while (j <= size)
	{
		to_fill[j] = ' ';
		j++;
	}
	to_fill[j] = '\0';
	printf("to_fill[j]==%s\n", to_fill);
	// exit(0);
	return (to_fill);
}

char	**rec_map(char **map, int y, int x)
{
	int		i;
	int		j;
	char	**new_map;

	j = 0;
	i = 0;
	new_map = malloc(sizeof(char *) * y);
	while (map[i++])
		new_map[j++] = malloc(sizeof(char) * x + 1);
	i = 0;
	j = 0;
	while (map[i])
	{
		new_map[j] = fill_spaces(map[i], new_map[j], x);
		j++;
		i++;
	}
	return (new_map);
}

t_info	*fill_more_infos(char **tab, t_info *info)
{
	int		*pos;

	info->map = fill_map(tab, 1);
	pos = get_player_position(info->map);
	info->y = pos[0];
	info->x = pos[1];
	info->map_y = map_len(info->map);
	info->map_x = map_y(info->map);
	info->dir = get_player(info->map);
	
	// print_struct(info);
	info->new_map = rec_map(info->map, info->y, info->x);
	print_struct(info);
	// free(pos);
	return (info);
}

t_info	*fill_infos(char **tab)
{
	t_info	*info;
	int		i;

	i = 0;
	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	while (tab && tab[i])
	{
		if (is_identifier(tab[i]) == 1)
			info->no = get_texture(tab[i] + 2);
		if (is_identifier(tab[i]) == 2)
			info->so = get_texture(tab[i] + 2);
		if (is_identifier(tab[i]) == 3)
			info->we = get_texture(tab[i] + 2);
		if (is_identifier(tab[i]) == 4)
			info->ea = get_texture(tab[i] + 2);
		if (is_identifier(tab[i]) == 5)
			info->floor = get_color(tab[i] + 2);
		if (is_identifier(tab[i]) == 6)
			info->ceil = get_color(tab[i] + 2);
		i++;
	}
	return (fill_more_infos(tab, info));
}
