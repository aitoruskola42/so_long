/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:29:21 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/21 15:17:01 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
MAC
gcc main.c get_next_line_bonus.c get_next_line_utils_bonus.c 
check_load.c main_load.c map_draw.c 
map_util.c so_long_utils.c minilibx/libmlx.a -framework OpenGL 
-framework AppKit -Werror -Wextra -Wall -fsanitize=address -g3
gcc *.c ../minilibx/libmlx.a -o so_long_bonus \
-framework OpenGL -framework AppKit 
-Werror -Wextra -Wall -fsanitize=address -g3
./so_long_bonus "../maps/ghosts.ber"

UBUNTU
gcc main.c get_next_line_bonus.c get_next_line_utils_bonus.c 
check_load.c main_load.c map_draw.c 
map_util.c so_long_utils.c -lbsd -lmlx -lXext 
-lX11 -fsanitize=address -g3
gcc *.c -lbsd -lmlx -lXext -lX11 -fsanitize=address -g3
gcc *.c -lbsd -lmlx -lXext -lX11  mlx-linux/libmlx_Linux.a 
 gcc *.c -lbsd -lmlx -lXext -lX11  
 mlx-linux/libmlx_Linux.a -o so_long "map"
gcc src\\*.c -lbsd -lmlx -lXext -lX11  
mlx-linux/libmlx_Linux.a -o so_long
gcc src_bonus\\*.c -lbsd -lmlx -lXext -lX11 
mlx-linux/libmlx_Linux.a -o so_long_bonus
./so_long_bonus "maps/ghosts.ber"
*/

#include	"so_long_bonus.h"

int	render(t_data *data)
{	
	int	x;
	int	y;

	if (data->win_ptr == NULL)
		return (1);
	if (data->rending == 1000 && data->you_lost == 0 && data->you_win == 0)
	{	
		data->animation = 1;
		animate_background(data);
		if (data->player.this_pos_x / PIXELS_CELLS > 10)
			x = PIXELS_CELLS * 10;
		else
			x = data->player.this_pos_x ;
		if (data->player.this_pos_y / PIXELS_CELLS > 10)
			y = PIXELS_CELLS * 10;
		else
			y = data->player.this_pos_y ;
		print_image_from_memory(data, witch_frame(1, data), x, y);
		data->rending = 0;
		data->animation = 1;
	}
	data->rending ++;
	move_player(data);
	return (0);
}

/* 	
	ft_putstr("wait");
	usleep(1000000);
	ft_putstr("wait2");
*/
int	main(int argc, char *argv[])
{
	t_data	data;

	check_argc(&data, argc, argv);
	get_map_dimensions(&data);
	make_malloc(&data);
	data.actual_map = data.map;
	load_file(&data, 0);
	check_screen_resolution(&data);
	initial_data_load(&data);
	load_mlx(&data);
	load_screen_images(&data);
	check_closed_map(&data);
	check_map_chars(&data);
	check_collectionables(&data);
	create_threads(&data);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, \
	data.window_height, data.window_width);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
	&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 17, 0, free_malloc, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_window(data.mlx_ptr, data.img.mlx_img);
}
	//system ("leaks so_long");
	//check_enemy(&data);