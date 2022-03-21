/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:44:49 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/19 13:26:05 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	left(t_all *all, char *line)
{
	if (line[all->mlx->px - 2] == '0')
	{
		line[all->mlx->px - 2] = 'P';
		line[all->mlx->px - 1] = '0';
		anime(all);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 2] == 'C')
	{
		line[all->mlx->px - 2] = 'P';
		line[all->mlx->px - 1] = '0';
		all->map->c -= 1;
		anime(all);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 2] == 'E' && !all->map->c)
		e2(all, line, 2, 1);
	else
		check_enemy(line[all->mlx->px - 2], all);
}

void	right(t_all *all, char *line)
{
	if (line[all->mlx->px] == '0')
	{
		line[all->mlx->px] = 'P';
		line[all->mlx->px - 1] = '0';
		anime(all);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px] == 'C')
	{
		line[all->mlx->px] = 'P';
		line[all->mlx->px - 1] = '0';
		all->map->c -= 1;
		anime(all);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px] == 'E' && !all->map->c)
		e2(all, line, 0, 1);
	else
		check_enemy(line[all->mlx->px], all);
}

void	up(t_all *all, t_list *ptr)
{
	char	*line;

	line = ptr->prev->content;
	if (line[all->mlx->px - 1] == '0')
	{
		down_utils(all, ptr, line);
		anime(all);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'C')
	{
		down_utils(all, ptr, line);
		all->map->c -= 1;
		anime(all);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'E' && !all->map->c)
		e1(all, line, ptr);
	else
		check_enemy(line[all->mlx->px - 1], all);
}

void	down(t_all *all, t_list *ptr)
{
	char	*line;

	line = ptr->next->content;
	if (line[all->mlx->px - 1] == '0')
	{
		down_utils(all, ptr, line);
		anime(all);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'C')
	{
		down_utils(all, ptr, line);
		all->map->c -= 1;
		anime(all);
		put_map(all);
		printf("moves : %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'E' && !all->map->c)
		e1(all, line, ptr);
	else
		check_enemy(line[all->mlx->px - 1], all);
}
