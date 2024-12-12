/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 14:18:47 by spyun         #+#    #+#                 */
/*   Updated: 2024/12/12 20:29:08 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

static int	get_map_dimensions(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		line_len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	game->height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	game->width = ft_strlen(line) - 1;
	while (line)
	{
		game->height++;
		line_len = ft_strlen(line) - 1;
		if (line_len != game->width)
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

static void	free_allocated_map(t_game *game, int last_row)
{
	int	i;

	i = 0;
	while (i < last_row)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

static int	allocate_map(t_game *game)
{
	int	i;

	game->map = (char **)malloc(sizeof(char *) * game->height);
	if (!game->map)
		return (0);
	i = 0;
	while (i < game->height)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (game->width + 1));
		if (!game->map[i])
		{
			free_allocated_map(game, i);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	fill_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (0);
		}
		ft_strlcpy(game->map[i], line, game->width + 1);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}

int	parse_map(t_game *game, char *file)
{
	if (!get_map_dimensions(game, file))
		return (0);
	if (!allocate_map(game))
		return (0);
	if (!fill_map(game, file))
	{
		free_allocated_map(game, game->height);
		return (0);
	}
	if (!validate_map(game))
	{
		free_allocated_map(game, game->height);
		return (0);
	}
	return (1);
}
