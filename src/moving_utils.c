/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:43:40 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/18 17:13:26 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	down_utils(t_all *all, t_list *ptr, char *line)
{
	line[all->mlx->px - 1] = 'P';
	line = ptr->content;
	line[all->mlx->px - 1] = '0';
}

void	check_y(t_all *all, int key)
{
	int		i;
	t_list	*ptr;

	i = -1;
	ptr = all->root;
	while (ptr && ++i < all->mlx->py - 1)
		ptr = ptr->next;
	if (key == 13 || key == 126)
		down(all, ptr);
	if (key == 1 || key == 125)
		up(all, ptr);
}

void	check_x(t_all *all, int key)
{
	char	*line;
	t_list	*ptr;
	int		i;

	i = -1;
	ptr = all->root;
	while (ptr && (++i < all->mlx->py - 1))
		ptr = ptr->next;
	line = ptr->content;
	if (key == 0 || key == 123)
		left(all, line);
	if (key == 2 || key == 124)
		right(all, line);
}

int	key_hook(int key, t_all *all)
{
	if (key == 0 || key == 123)
		check_x(all, key);
	if (key == 1 || key == 125)
		check_y(all, key);
	if (key == 2 || key == 124)
		check_x(all, key);
	if (key == 13 || key == 126)
		check_y(all, key);
	if (key == 53)
	{
		ft_lstclear(&all->root);
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		printf ("--------|| EXIT GAME ||--------\n");
		exit(0);
	}
	return (0);
}
