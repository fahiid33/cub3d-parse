/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:19:53 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/21 23:15:02 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	extract_line_modify_save(char **save, char **line)
{
	char	*temp;

	*line = ft_substr(*save, 0, (ft_strchr(*save, '\n') + 1));
	temp = *save;
	*save = ft_substr(*save, (ft_strchr(*save, '\n') + 1), (ft_strlen(*save)));
	free(temp);
}

char	*ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			l;
	char		*temp;

	while (ft_strchr(save, '\n') == -1)
	{
		l = read(fd, buf, BUFFER_SIZE);
		if (l == 0 || l == -1)
		{
			if ((save && save[0] == '\0'))
				return (ft_free(save));
			temp = save;
			save = NULL;
			return (temp);
		}
		buf[l] = '\0';
		temp = save;
		save = ft_strjoin(save, buf);
		ft_free(temp);
	}
	extract_line_modify_save(&save, &line);
	return (line);
}
// int main()
// {
// 	int fd = open("test", O_RDONLY);
// 	char *str;
// 	int fd1 = open("test1", O_)
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// }