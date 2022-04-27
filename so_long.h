/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:20:21 by bdurmus           #+#    #+#             */
/*   Updated: 2022/04/27 13:15:50 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Mlx/mlx.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define RED     "\x1b[31m"
# define RESET   "\x1b[0m"
# define BLUE    "\x1b[34m"
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct l_game
{
	char	**map;
	int		max_x;
	int		max_y;
	int		player_x;
	int		player_y;
	int		coinc;
	int		move;
	int		size;
	void	*window;
	void	*mlx;
	void	*playerr;
	void	*playerl;
	void	*coin;
	void	*exit;
	void	*bg;
	void	*rock;
}	t_game;

char	**ft_split_fs(char *str, char *charset, int *ln);
char	*ft_strndup(char *src, int j);
int		init_map(t_game **game, char **argv);
void	printm(char *message, t_game **game);
int		create_map(t_game **game);
void	convertoxpm(t_game **game);
int		ft_key_events(int key_code, t_game **game);
void	ft_mlx_put_image(t_game **game, void *obj, int x, int y);
char	*ft_str_join(char *left_str, char *buff);
int		exit_hook(t_game **game);
void	free_map(t_game **game);

#endif