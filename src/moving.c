/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:44:49 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/18 17:15:46 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	left(t_all *all, char *line)
{
	if (line[all->mlx->px - 2] == '0')
	{
		line[all->mlx->px - 2] = 'P';
		line[all->mlx->px - 1] = '0';
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 2] == 'C')
	{
		line[all->mlx->px - 2] = 'P';
		line[all->mlx->px - 1] = '0';
		all->map->c -= 1;
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 2] == 'E' && !all->map->c)
	{
		line[all->mlx->px - 2] = 'P';
		line[all->mlx->px - 1] = '0';
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		printf("-------|| YOU  WIN ||-------\n");
		ft_lstclear(&all->root);
		exit(0);
	}
}

void	right(t_all *all, char *line)
{
	if (line[all->mlx->px] == '0')
	{
		line[all->mlx->px] = 'P';
		line[all->mlx->px - 1] = '0';
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px] == 'C')
	{
		line[all->mlx->px] = 'P';
		line[all->mlx->px - 1] = '0';
		all->map->c -= 1;
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px] == 'E' && !all->map->c)
	{
		line[all->mlx->px] = 'P';
		line[all->mlx->px - 1] = '0';
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		printf("-------|| YOU  WIN ||-------\n");
		ft_lstclear(&all->root);
		exit(0);
	}
}

void	down(t_all *all, t_list *ptr)
{
	char	*line;

	line = ptr->prev->content;
	if (line[all->mlx->px - 1] == '0')
	{
		down_utils(all, ptr, line);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'C')
	{
		down_utils(all, ptr, line);
		all->map->c -= 1;
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'E' && !all->map->c)
	{
		down_utils(all, ptr, line);
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		printf("-------|| YOU  WIN ||-------\n");
		ft_lstclear(&all->root);
		exit(0);
	}
}

void	up(t_all *all, t_list *ptr)
{
	char	*line;

	line = ptr->next->content;
	if (line[all->mlx->px - 1] == '0')
	{
		down_utils(all, ptr, line);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'C')
	{
		down_utils(all, ptr, line);
		all->map->c -= 1;
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'E' && !all->map->c)
	{
		down_utils(all, ptr, line);
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		printf("-------|| YOU  WIN ||-------\n");
		ft_lstclear(&all->root);
		exit(0);
	}
}
