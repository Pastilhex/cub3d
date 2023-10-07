#include "../includes/cub3d.h"


void	ft_print_t_map(t_map *m)
{
	printf(">>>>>>  t_map struct  <<<<<<<:\n ");
	printf("m->fd: %d\n", m->fd);
	printf("m->ttl_nbr_lines: %d\n", m->ttl_nbr_lines);
	printf("m->map_width: %d\n", m->map_width);
	printf("m->map_length: %d\n", m->map_length);
	printf("m->map_path: %s\n", m->map_path);
	printf("m->north_texture: %s\n", m->north_texture);
	printf("m->south_texture: %s\n", m->south_texture);
	printf("m->west_texture: %s\n", m->west_texture);
	printf("m->east_texture: %s\n", m->east_texture);
	printf("m->floor_texture: %s", m->floor_texture);
	printf("m->ceiling_texture: %s", m->ceiling_texture);
}

void 	ft_print_array(char **arr, int nb_lines)
{
	for (int i = 0; i < nb_lines; i++)
		printf("%s", arr[i]);
	printf("\n");
	
}