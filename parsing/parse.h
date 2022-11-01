/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:06:47 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/31 22:05:30 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define WIDTH 766
# define HEIGHT 766

# include <stdlib.h> 
# include "GNL/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <mlx.h>

typedef struct s_parse
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	floor;
	int	ceil;
	int	inv_line;
	int	wg_char;
	int	no_pos;
	int	no_map;
	int	map_open;
	int	m_end;
	int	m_pos;
	int	flag;
}	t_parse;

typedef struct s_infos
{
	int		x;
	int		y;
	int		ceil;
	int		floor;
	void	*win;
	void	*img;
	void	*mlx;
	void	*img_add;
	int		*bpp;
	int		*size;
	int		*end;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_info;

// tools

t_parse	*init_vals(t_parse *p);
int		is_map(char *s);
int		get_len(char *str);
int		is_blank(char c);
int		is_invalid(char c);
int		check_file(char *file);
void	errors(int err);
char	**ft_split(char const *s, char c);
int		only_space(char *str);
void	free_tab(char **tab);
int		ft_atoi(const char *str);
int		is_digit(int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(char *str, unsigned int n);
int		ft_int_strchr(const char *s, int c);
int		map_len(char **map);

// parse

t_parse	*parse_identifiers(char **vals, t_parse *p);
t_parse	*check_identifiers(char **tab, t_parse *p);
t_parse	*parse_map(char **map, t_parse *p);
t_parse	*check_map(t_parse *p, char **map);
t_info	*fill_infos(char **tab);
char	**fill_identifiers(char **to_fill, char **tab, t_parse *p);
char	**fill_map(char **tab, int flag);
int		check_colors(char *str, int i);
int		check_textures(char *str, int i);
int		map_closed(char *str);
int		*get_player_position(char **str);
int		invalid_char(char *s);
int		check_position(char *s);
int		check_space(char *str);
int		is_identifier(char *s);
int		print_errors(t_parse *p);

#endif
