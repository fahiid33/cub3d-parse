/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:30:08 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/23 04:19:33 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"


int	is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}