/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:06:47 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/23 04:06:03 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

#include <stdlib.h> 
#include "GNL/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


typedef struct s_parse
{
    int NO;
    int SO;
    int WE;
    int EA;
    int R;
    int floor;
    int ceil;
    int inv_line;
    int wg_char;
    int no_pos;
    int no_map;
    int map_open;
    int m_pos;
    int m_end;
}   t_parse;

// tools

t_parse	*init_vals(t_parse *p);
int		is_map(char *s);
int		is_blank(char c);
int		is_invalid(char c);
int 	check_file(char *file);
void	errors(int err);
char	**ft_split(char const *s, char c);
int		only_space(char *str);
void	free_tab(char **tab);
int		ft_atoi(const char *str);
int	    is_digit(int c);


// parse

t_parse	*parse_identifiers(char **vals, t_parse *p);
t_parse *check_identifiers(char **tab, t_parse *p);
t_parse *parse_map(char **map, t_parse *p);
char	**fill_identifiers(char **to_fill, char **tab, t_parse *p);
char	**fill_map(char **tab);
int		check_colors(char *str, int i);
int		check_textures(char *str, int i);

#endif