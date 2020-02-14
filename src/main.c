/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:20:40 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/14 18:45:40 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//voir algo de bresenheim

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		deal_key(int key, void *param)
{
	ft_putchar('X');
	(void)key;
	(void)param;
	//mlx_pixel_put(mlx_ptr, win_ptr, );
	return (0);
}

int		main()
{
	void *mlx_ptr;
	void *win_ptr;

	//renvoie identifiant de connexion au serveur graphique
	mlx_ptr = mlx_init();
	// renvoie identifiant de la nouvelle fenetre
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
