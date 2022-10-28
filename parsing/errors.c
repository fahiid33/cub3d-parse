/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:32:43 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/28 20:17:56 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	errors(int err)
{
	if (err == 1)
	{
		write(2, "Error in file format\n", 21);
		exit(1);
	}
}

int	print_errors2(t_parse *p)
{
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

int	print_errors1(t_parse *p)
{
	if (p->NO != 1 || p->SO != 1 || p->WE != 1 
		|| p->EA != 1 || p->ceil != 1 || p->floor != 1 || p->flag != 0
		|| p->inv_line != 0 || p->m_end != 0 || p->map_open != 0 || p->no_map != 0
		|| p->no_pos != 0 || p->m_pos != 0 || p->wg_char != 0)
		printf("Error\n");
	if (p->NO <= 0 || p->SO <= 0 || p->EA <= 0 || p->WE <= 0)
	{
		printf("Invalid texture(s) file\n");
		return (1);
	}
	if (p->NO > 1 || p->SO > 1|| p->EA > 1 || p->WE > 1 || p->floor > 1 || p->ceil > 1)
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
	return (0);
}
int	print_errors(t_parse *p)
{
	if (print_errors1(p))
		return (1);
	if (print_errors2(p))
		return (1);
	return (0);
}
