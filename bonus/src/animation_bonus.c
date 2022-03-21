/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:47:13 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/21 13:37:48 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move1(t_all *all, int i, char *line)
{
	char	c;

	c = line[all->enemy->x[i]];
	if (all->enemy->dir == 1)
	{
		if (c == '0')
		{
			line[all->enemy->x[i]] = 'X';
			line[all->enemy->x[i] - 1] = '0';
			all->enemy->x[i]++;
		}
		else if (c != '0')
		{
			if (c == 'P')
				exit(0);
			all->enemy->dir = 0;
		}
	}
	else
		move2(all, i, line);
}

void	move2(t_all *all, int i, char *line)
{
	char	c;

	c = line[all->enemy->x[i] - 2];
	if (all->enemy->dir == 0)
	{
		if (c == '0')
		{
			line[all->enemy->x[i] - 2] = 'X';
			line[all->enemy->x[i] - 1] = '0';
			all->enemy->x[i]--;
		}
		else if (c != '0')
		{
			if (c == 'P')
				exit(0);
			all->enemy->dir = 1;
		}
	}
	else
		move1(all, i, line);
}

void	enemy_move(t_all *all)
{
	static int	pp = 0 ;
	char		*line;
	t_list		*p;
	int			d;

	if (!all->enemy->i)
		return ;
	if (pp == all->enemy->i)
		pp = 0;
	p = all->root;
	d = 0;
	while (++d < all->enemy->y[pp])
		p = p->next;
	line = p->content;
	move1(all, pp, line);
	pp++;
}

int	anime(t_all *all)
{
	enemy_move(all);
	return (0);
}
