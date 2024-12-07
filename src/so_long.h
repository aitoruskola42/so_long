/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:52:28 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/21 14:02:55 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef MLX_H
#  include "../minilibx/mlx.h"
# endif

# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

typedef unsigned long	t_size_t;

typedef struct s_node
{
	int	valid;
	int	position_x;
	int	position_y;
	int	value;
	int	found;
}	t_node;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	int		this_pos_x;
	int		n_p_x;
	int		this_pos_y;
	int		n_p_y;
}	t_player;

typedef struct s_data
{
	char		*argv_map;
	void		*mlx_ptr;
	void		*win_ptr;
	int			rows;
	int			cols;
	int			res;
	int			frames;
	int			window_width;
	int			window_height;
	int			s_move_x;
	int			s_move_y;
	int			presed_keys;
	int			enemy;
	int			cats;
	int			exit;
	int			you_win;
	int			you_lost;
	char		**line_file;
	char		**map;
	char		**actual_map;
	t_img		img;
	t_img		*background_img;
	t_img		*collecionable_img;
	t_player	player;
	t_player	p_m;
	t_img		*player_pic;	
	t_img		*player_pic_a[4][4];
	t_img		*numbers_pic[10];
	t_img		*wall_pic;
	t_img		*object_pic;
	t_img		*exit_pic;
	t_img		*exit2_pic;
	t_img		*enemy_pic;
	t_img		*enemy2_pic;
	t_img		*free_pic;
	t_img		*left_pic;
	t_img		*win_pic;
	t_img		*lost_pic;
	t_img		*right_pic;
	t_img		*up_pic;
	t_img		*down_pic;	
	t_img		*end_pic;
	t_img		*background_pic;
	t_img		*speed;
	t_img		*walk_pic;	
	int			p_st_p_x;
	int			p_st_p_y;
	int			end_move;
	int			finished;
	long		rending;
	int			animation;
	int			pos_change_speed;
	int			p_sc_p_x;
	int			p_sc_p_y;
	int			screen_changed;
	int			move_user;
	char		move_key;
	int			move_value_x;
	int			move_value_y;
	int			move_value_x2;
	int			move_value_y2;
	int			game_finish_time;
	int			i;
	int			j;
}	t_data;

# define MLX_ERROR 1
# define START_SPEED 30
# define ENEMY_KEY 'G'
# define WINDOW_WIDTH_CELLS 20
# define WINDOW_HEIGHT_CELLS 12
# define WAIT_RIGHT_CELLS 30
# define WAIT_DOWN_CELLS 30
# define PIXELS_CELLS 64
# define PANEL_WIDTH 140
# define LEFT 1
# define RIGHT 2
# define UP 4
# define DOWN 8
# define STEPS_IMAGE_HEIGHT 25
# define STEPS_COUNTER_HEIGHT 85
# define COLLECTIONABLES_IMAGE_HEIGHT 163
# define COLLECTIONABLES_COUNTER_HEIGHT 240
# define EXIT_IMAGE_HEIGHT 315
# define EXIT_COUNTER_HEIGHT 385
# define ENEMY_IMAGE_HEIGHT 460
# define ENEMY_COUNTER_HEIGHT 530
# define VELOCIMETER_IMAGE_HEIGHT 605
# define VELOCIMETER_COUNTER_HEIGHT 675
# define UP_IMAGE_HEIGHT 745
# define LEFT_IMAGE_HEIGHT 780
# define RIGHT_IMAGE_HEIGHT 780
# define DOWN_IMAGE_HEIGHT 815

void	button_pressed(t_data *data);
void	initial_data_load(t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	animate_background(t_data *data);
t_img	*witch_frame(int change, t_data *data);
void	move_player(t_data *data);
void	write_numbers(t_data *data);
int		render(t_data *data);
void	file_to_map(t_data *data, int x, char *values);
int		load_file(t_data *data, int i);
int		count_images(t_data *data, char key);
void	print_desc(t_data *data, char key);
void	print_image_on_screen(t_data *data, char *image_filename, int x, int y);
void	print_panel(t_data *data);
void	print_text_on_screen(t_data *data, char *text, int x, int y);
void	print_image_from_memory(t_data *data, t_img *image, int x, int y);
char	*ft_strdup_array(char *str, int pos, char number);
void	load_screen_images(t_data *data);
void	check_screen_resolution(t_data *data);
void	get_map_dimensions(t_data *data);
int		check_collectionables(t_data *data);
int		check_map(t_data *data, char *text);
int		check_closed_map(t_data *data);
int		check_map_chars(t_data *data);
t_node	***create_map(t_node ***maps, int rows, int cols);
void	set_map(t_node ***map, int rows, int cols);
void	set_cell_values(t_node ***map, t_node *temp, int rows, int cols);
void	free_map(t_node ***map, int rows, int cols);
void	clean_valid(t_node ***maps, int rows, int cols);
void	can_move_check(t_node ***map, t_node *this_one, int rows, int cols);
void	iniciar_pasos(t_node ***map, int rows, int cols);
t_node	*can_move_left(t_node ***map, t_node *this_one);
t_node	*can_move_right(t_node ***map, t_node *this_one, int cols);
t_node	*can_move_down(t_node ***map, t_node *this_one, int rows);
t_node	*can_move_up(t_node ***map, t_node *this_one);
int		new_move(t_node *this_one, int steps);
t_node	*can_do_move(t_node ***map, t_node *this_one, int rows, int cols);
int		can_continue(t_node ***map, t_node *temp, int rows, int cols);
t_node	*can_do_move(t_node ***map, t_node *this_one, int rows, int cols);
t_node	*move_up(t_node ***map, t_node *this_one, int rows, int cols);
t_node	*move_down(t_node ***map, t_node *this_one, int rows, int cols);
t_node	*move_right(t_node ***map, t_node *this_one, int rows, int cols);
t_node	*move_left(t_node ***map, t_node *this_one, int rows, int cols);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	map_error(char *description);
void	load_memory_images(t_data *data);
void	load_memory_images2(t_data *data);
void	make_malloc(t_data *data);
int		free_malloc(t_data *data);
void	animate_array_images(t_data *data, int x, int y);
void	animate_patch_lines(t_data *data, int x, int y);
void	is_game_finished(t_data *data, char value);
void	finish_move(t_data *data);
void	print_panel2(t_data *data);
void	can_move(t_data *data, char key);
void	load_mlx(t_data *data);
void	animate_finish(t_data *data);
void	image_exit_patch(t_data *data, int x, int y);
char	*ft_itoa(int valor);
char	*convert_str(char *str, long n, int numbers, int counter);
int		characters(long n);
size_t	ft_strlen(char	*text);
void	move_player_2(t_data *data);
void	handle_keypress_2(int keysym, t_data *data);
int		check_argc(t_data *data, int number, char *argv[]);
void	wait_temp(t_data *data);
int		check_valid_road(t_data *data);
int		check_mark(t_data *data, t_data *map, int x, int y);
int		check_map_finished(t_data *new_map, t_data *data);
#endif