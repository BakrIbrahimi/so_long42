/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:52:43 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/17 13:53:16 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_empty(t_all *all, int *x, int *y)
{
	all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/0.xpm", x, y);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img,
		all->map->x, all->map->y);
}
