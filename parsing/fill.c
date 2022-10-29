/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:01:17 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/29 12:25:04 by fstitou          ###   ########.fr       */
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
		while(is_blank(str[i]))
			i++;
	len = get_len(str + i);
	file = ft_substr(str + i, 0, len);
	return (file);
}

int	get_color(char *str)
{
	int color;
	int R;
	int	G;
	int	B;
	int	i;

	i = 0;
	if (is_blank(str[i]))
		while(is_blank(str[i]))
			i++;
	R = atoi(str + i);
	while (is_digit(str[i]) || is_blank(str[i]))
		i++;
	i++;
	G = atoi(str + i);
	while (is_digit(str[i]) || is_blank(str[i]))
		i++;
	i++;
	B = atoi(str + i);
	color = (R << 16) + (G << 8) + B;
	return (color);
}

void	print_struct(t_info *info)
{
	printf("NO: %s\n", info->NO);
	printf("SO: %s\n", info->SO);
	printf("WE: %s\n", info->WE);
	printf("EA: %s\n", info->EA);
	printf("F: %d\n", info->floor);
	printf("C: %d\n", info->ceil);
	printf("x = %d | y = %d\n", info->x, info->y);
	for(int k = 0; info->map[k]; k++)
		printf("map[%d] = %s\n", k, info->map[k]);
	
}

t_info	*fill_more_infos(char **tab, t_info *info)
{
	int		*pos;

	info->map = fill_map(tab, 1);
	pos = get_player_position(info->map);
	info->x = pos[0];
	info->y = pos[1];
	free(pos);
	// info->mlx = mlx_init();
	// info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3D");
	// info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	// info->img_add = mlx_get_data_addr(info->img, &info->bpp,
	// 				&info->size, &info->end);
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
			info->NO = get_texture(tab[i] + 2);
		if (is_identifier(tab[i]) == 2)
			info->SO = get_texture(tab[i] + 2);
		if (is_identifier(tab[i]) == 3)
			info->WE = get_texture(tab[i] + 2);
		if (is_identifier(tab[i]) == 4)
			info->EA = get_texture(tab[i] + 2);
		if (is_identifier(tab[i]) == 5)
			info->floor = get_color(tab[i] + 2);
		if (is_identifier(tab[i]) == 6)
			info->ceil = get_color(tab[i] + 2);
		i++;
	}
	info = fill_more_infos(tab, info);
	print_struct(info);
	return (info);
}