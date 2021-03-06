/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:20:40 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/14 19:52:37 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fcntl.h>

int		exit_error(char *str)
{
	ft_putstr(str);
	return (0);
}

void	init_structure(t_fdf *fdf, int fd)
{
	if (!(fdf = ft_memalloc(sizeof(t_fdf))))
		ft_error(fdf, &free_all, MALLOC);
	read_file(fdf, fd);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;

	if (argc != 2)
		return (exit_error(ONE_MAP));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (exit_error(CANT_OPEN));
	init_structure(&fdf, fd);
	return (0);
}
