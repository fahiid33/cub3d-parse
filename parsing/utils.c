/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:07:26 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/23 23:35:18 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_parse	*init_vals(t_parse *p)
{
	p->NO = 0;
	p->SO = 0;
	p->WE = 0;
	p->EA = 0;
	p->R = 0;
	p->floor = 0;
	p->ceil = 0;
	p->inv_line = 0;
	p->no_pos = 0;
	p->no_map = 0;
	p->wg_char = 0;
	p->map_open = 0;
	p->m_pos = 0;
	p->m_end = 0;
	return (p);
}

int check_file(char *file)
{
    char *str;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (0);
    str = strrchr(file, '.');
    if (str == NULL || strcmp(str, ".cub") != 0 || !strcmp(file, ".cub")) 
        return (0);
    return (fd);
}


int	is_map(char *s)
{
	int	i;

	i = 0;
	if (is_blank(s[i]))
	{
		while (is_blank(s[i]))
			i++;
	}
	if (s[i] == '1' || s[i] == '0')
		return (1);
	return (0);
}

