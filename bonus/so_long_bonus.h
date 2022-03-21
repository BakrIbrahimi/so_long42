/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:31:54 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/21 13:58:36 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 100000
# define EMPTY_FILE "Error the map is empty" 
# define NOT_RECTANGULAR "Error the map is not rectangular" 
# define NOT_ONE "Error the map is not surrounded by wall" 
# define MORE_COMP "ther is more than 01ECP in map"
# define MISSING "something missing in map"

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	int		px;
	int		py;
}	t_mlx;

typedef struct s_list {
	struct s_list	*prev;
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_map
{
	int	in;
	int	r;
	int	w;
	int	c;
	int	e;
	int	p;
	int	h;
	int	x;
	int	y;
}	t_map;

typedef struct s_enemy {
	int	x[1000];
	int	y[1000];
	int	i;
	int	dir;
}	t_enemy;

typedef struct s_all {
	t_map	*map;
	t_mlx	*mlx;
	t_list	*root;
	t_enemy	*enemy;
}	t_all;
int		check_width(char *line, t_map *map, int s);
int		check_rec(t_map *map, t_list **root);
int		check_name(char *str);
void	left(t_all *all, char *line);
void	right(t_all *all, char *line);
void	check_x(t_all *all, int key);
void	up(t_all *all, t_list *ptr);
void	down(t_all *all, t_list *ptr);
void	down_utils(t_all *all, t_list *ptr, char *line);
void	check_y(t_all *all, int key);
int		key_hook(int key, t_all *all);
void	put_empty(t_all *all, int *x, int *y);
void	put_player(t_all *all, int *x, int *y);
void	put_exit(t_all *all, int *x, int *y);
void	put_wall(t_all *all, int *x, int *y);
void	put_enimy(t_all *all, int *x, int *y);
void	put_collect(t_all *all, int *x, int *y);
int		key_hook(int key, t_all *all);
int		put_map(t_all *all);
int		check_one(char *line1, char *line2);
int		move(t_all *all);
void	reset_map(t_map *map);
int		render(t_all *all);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*read_line(char *path, t_all *all);
int		check_wall(char *line, t_map *map);
int		check_child(char c, t_all *all);
int		check_comp(char *line, t_all *all);
int		check_char(char *line, t_all *all);
int		check_line(char *line, t_all *all);
int		print_error(int n);
char	*ft_strdup(const char *s1);
int		ft_strchr(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	check_enemy(char c, t_all *all);
void	e1(t_all *all, char *line, t_list *ptr);
void	e2(t_all *all, char *line, int x, int y);
void	move1(t_all *all, int i, char *line);
void	move2(t_all *all, int i, char *line);
void	enemy_move(t_all *all);
int		anime(t_all *all);
int		ft_intlen(long n);
char	*ft_itoa(int n);

#endif
