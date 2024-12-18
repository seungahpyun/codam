/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 14:18:47 by spyun         #+#    #+#                 */
/*   Updated: 2024/12/18 10:24:23 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_dimensions(t_game *game, char *file)
{
	char	*line;
	int		fd;

	if (!game || !file)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	game->height = 0;
	game->width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) > 0)
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			if (game->height == 0)
				game->width = ft_strlen(line);
			else if (game->width != (int)ft_strlen(line))
			{
				free(line);
				close(fd);
				return (0);
			}
			game->height++;
		}
		free(line);
	}
	close(fd);
	return (game->width > 0 && game->height > 0);
}


int	parse_map(t_game *game, char *file)
{
	if (!game || !file)
		return (0);
	if (!get_map_dimensions(game, file))
	{
		ft_putendl_fd("Error: Invalid map dimensions", 2);
		return (0);
	}
	if (!allocate_and_fill_map(game, file))
	{
		ft_putendl_fd("Error: Map allocation failed", 2);
		return (0);
	}
	if (!validate_map(game))
	{
		free_allocated_map(game, game->height);
		return (0);
	}
	return (1);
}
