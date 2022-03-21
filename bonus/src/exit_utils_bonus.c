/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:33:15 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/19 13:54:56 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	e1(t_all *all, char *line, t_list *ptr)
{
	down_utils(all, ptr, line);
	mlx_destroy_window(all->mlx->mlx, all->mlx->win);
	printf("-------|| YOU  WIN ||-------\n");
	ft_lstclear(&all->root);
	exit(0);
}

void	e2(t_all *all, char *line, int x, int y)
{
	line[all->mlx->px - x] = 'P';
	line[all->mlx->px - y] = '0';
	mlx_destroy_window(all->mlx->mlx, all->mlx->win);
	printf("-------|| YOU  WIN ||-------\n");
	ft_lstclear(&all->root);
	exit(0);
}
