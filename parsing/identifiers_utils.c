/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:44:06 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/01 22:36:25 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	i--;
	if (str && str[i] == ' ')
	{
		while (str[i] && str[i] != 'm')
			i--;
		return (i + 1);
	}
	return (i + 1);
}

int	check_textures(char *str, int i)
{
	int		fd;
	int		len;
	char	*file;
	char	*extension;

	if (!is_blank(str[i]) && str[0] == 'W' && str[1] != ' ')
		return (0);
	while (str && is_blank(str[i]))
		i++;
	extension = ft_strrchr(str + i, '.');
	if (extension == NULL || !ft_strncmp(str + i, ".xpm", 4)
		|| ft_strncmp(extension, ".xpm", 4) != 0)
		return (-1);
	len = get_len(str + i);
	file = ft_substr(str + i, 0, len);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(file);
		close(fd);
		return (0);
	}
	free(file);
	close(fd);
	return (1);
}

int	last_color(char *str, int i)
{
	i++;
	if (str[i] == '\0')
		return (0);
	while (is_digit(str[i]) || is_blank(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_range(char **tab)
{
	if (!tab[0] || !tab[1] || !tab[2])
		return (0);
	if (only_space(tab[0]) || only_space(tab[1])
		|| only_space(tab[2]))
		return (0);
	if (!check_space(tab[0]) || !check_space(tab[1])
		|| !check_space(tab[2]))
		return (0);
	if (ft_atoi(tab[0]) > 255 || ft_atoi(tab[0]) < 0
		|| ft_atoi(tab[1]) > 255 || ft_atoi(tab[1]) < 0
		|| ft_atoi(tab[2]) > 255 || ft_atoi(tab[2]) < 0)
		return (0);
	return (1);
}

int	check_colors(char *str, int i)
{
	char	**s;

	if (is_blank(str[i]))
		while (is_blank(str[i]))
			i++;
	s = ft_split(str + i, ',');
	while (is_digit(str[i]) || is_blank(str[i]))
		i++;
	if (str[i] != ',')
		return (0);
	i++;
	while (is_digit(str[i]) || is_blank(str[i]))
		i++;
	if (str[i] != ',')
		return (0);
	if (last_color(str, i) == 0)
		return (0);
	if (check_range(s) == 0)
	{
		free_tab(s);
		return (0);
	}
	free_tab(s);
	return (1);
}
