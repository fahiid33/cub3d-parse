/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:44:06 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/23 04:07:52 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_textures(char *str, int i)
{
	int	fd;
	int	len;
	char *file;

	if (is_blank(str[i]))
		while(is_blank(str[i]))
			i++;
	len = ft_strlen(str + i) - 1;
	file = ft_substr(str + i, 0, len);
	fd = open(file , O_RDONLY);
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
	if (str[i] == '\0'|| str[i] == '\n')
		return (0);
	while (is_digit(str[i]) || is_blank(str[i]) || str[i] == '\n')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
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
	||	ft_atoi(tab[2]) > 255 || ft_atoi(tab[2]) < 0)
		return (0);
	return (1);
}

int	check_colors(char *str, int i)
{
	char	**s;

	if (is_blank(str[i]))
		while(is_blank(str[i]))
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