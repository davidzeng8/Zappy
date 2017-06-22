/*
** world.c for world in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 22 00:17:58 2017 David Zeng
** Last update Thu Jun 22 00:17:58 2017 David Zeng
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "world.h"

static void	generate_map(t_tile **map, t_pos dim)
{
  int		j;
  int		i;

  srand(time(NULL));
  j = -1;
  while (++j < dim.y)
    {
      i = -1;
      while (++i < dim.x)
	{
	  map[j][i].food = rand() % 5;
	  map[j][i].stones[0] = rand() % 5;
	  map[j][i].stones[1] = rand() % 5;
	  map[j][i].stones[2] = rand() % 5;
	  map[j][i].stones[3] = rand() % 5;
	  map[j][i].stones[4] = rand() % 5;
	  map[j][i].stones[5] = rand() % 5;
	  map[j][i].elevation = false;
	  map[j][i].players = vector_new();
	}
    }
}

int	tile_dump(int fd, t_tile *tile, int x, int y)
{
  return (dprintf(fd,
		  "bct %d %d %d %d %d %d %d %d %d\n",
		  x,
		  y,
		  tile->food,
		  tile->stones[LINEMATE],
		  tile->stones[DERAUMERE],
		  tile->stones[SIBUR],
		  tile->stones[MENDIANE],
		  tile->stones[PHIRAS],
		  tile->stones[THYSTAME]));
}

int	world_dump(int fd, t_world *world)
{
  int	i;
  int	j;

  j = -1;
  printf("world dump\n");
  while (++j < world->dimension.y)
    {
      i = -1;
      while (++i < world->dimension.x)
	{
	  if (tile_dump(fd, &world->map[j][i], i, j) == -1)
	    return (-1);
	}
    }
  return (0);
}

t_world		*create_world(t_pos dim)
{
  t_world	*world;
  int		i;

  if (!(world = malloc(sizeof(*world))))
    exit(84);
  world->dimension = dim;
  if (!(world->map = malloc(sizeof(t_tile *) * dim.y)))
    exit(84);
  i = -1;
  while (++i < dim.y)
    {
      world->map[i] = malloc(sizeof(t_tile) * dim.x);
      if (!world->map[i])
	exit(84);
    }
  generate_map(world->map, dim);
  return (world);
}

void		free_world(t_world *world)
{
  int		i;
  int		j;

  j = -1;
  while (++j < world->dimension.y)
    {
      i = -1;
      while (++i < world->dimension.x)
	vector_delete(world->map[j][i].players, NULL); // TODO DELETE PLAYER
      free(world->map[j]);
    }
  free(world->map);
  free(world);
}
