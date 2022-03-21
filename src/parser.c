/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:56:02 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/12 15:56:06 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_one1(char *line1)
{
	int	i;

	i = 0;
	while (line1[i + 1])
	{
		if (line1[i] != '1')
			return (print_error(3));
		i++;
	}
	return (0);
}

int	check_one2(char *line1)
{
	int	i;

	i = 0;
	while (line1[i])
	{
		if (line1[i] != '1')
			return (print_error(3));
		i++;
	}
	return (0);
}

int	check_map(t_map *map, t_list **root)
{
	int	y;
	int	x;

	if (!map->c || !map->e || map->p != 1)
		return (print_error(5));
	if (check_rec(map, root))
		return (print_error(2));
	x = check_one1((*root)->content);
	y = check_one2(ft_lstlast(*root)->content);
	if (x || y)
		return (3);
	if (check_width(ft_lstlast(*root)->content, map, 1))
		return (print_error(2));
	return (0);
}

char	*read_line(char *path, t_all *all)
{
	char	*line;
	int		fd;
	int		error;

	fd = open(path, O_RDWR);
	line = get_next_line(fd);
	all->root = NULL;
	if (!line)
		print_error(1);
	while (line)
	{
		error = check_line(line, all);
		if (error)
			exit(0);
		line = get_next_line(fd);
	}
	if (check_map(all->map, &all->root))
		exit(0);
	return (NULL);
}
