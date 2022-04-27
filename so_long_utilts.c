/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:11:27 by bdurmus           #+#    #+#             */
/*   Updated: 2022/04/25 13:21:32 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game **game)
{
	int	x;

	x = 0;
	if (!(*game)->map)
	{
		while (x < (*game)->max_y)
			free((*game)->map[x++]);
	}
}

void	printm(char *message, t_game **game)
{
	ft_printf(RED "%s" RESET, message);
	free_map(game);
	exit (0);
}

char	*ft_str_join(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i])
			str[i] = left_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_strndup(char *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((j + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < j && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	exit_hook(t_game **game)
{
	free_map(game);
	free((*game)->playerl);
	free((*game)->playerr);
	free((*game)->coin);
	free((*game)->map);
	free((*game)->rock);
	free((*game)->exit);
	free((*game)->bg);
	mlx_destroy_window((*game)->mlx, (*game)->window);
	exit(0);
}
