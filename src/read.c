/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:01:22 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/14 20:04:54 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	check_line(t_fdf *fdf, char *line)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		ft_error(fdf, &free_all, MALLOC);
}

void	read_file(t_fdf *fdf, int fd)
{
	char *line;

	while (get_next_line(fd, &line) == 1)
	{
		printf("line = %s\n", line);
		check_line(fdf, line);
		ft_memdel((void*)&line);
	}
}
