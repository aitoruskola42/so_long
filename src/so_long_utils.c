/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:54:53 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/06 15:54:57 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

//speed didnt move, is need to refresh manually.
int	count_images(t_data *data, char key)
{
	int	x;
	int	y;
	int	num;

	if (key == 'K')
		return (data->pos_change_speed);
	x = 0;
	y = 0;
	num = 0;
	while (x < data->rows)
	{
		while (y < data->cols)
		{
			if (data->actual_map[x][y] == key)
				num++;
			y++;
		}
		y = 0;
		x++;
	}
	return (num);
}

//default value steps_counter_height to make two line less in key='S'
/*
 	if (key == ENEMY_KEY)
		height = ENEMY_COUNTER_HEIGHT;
	if (key == 'K')
		height = VELOCIMETER_COUNTER_HEIGHT;
 
*/
void	print_desc(t_data *data, char key)
{
	int		number;
	int		pos;
	int		height;

	pos = 0;
	height = STEPS_COUNTER_HEIGHT;
	if (key == 'C')
		height = COLLECTIONABLES_COUNTER_HEIGHT;
	if (key == 'E')
		height = EXIT_COUNTER_HEIGHT;
	if (key == 'S')
		number = data->presed_keys;
	else
		number = count_images(data, key);
	if (number == 0)
		print_image_from_memory(data, \
		data->numbers_pic[0], data->window_width - 45 - pos, height);
	while (number > 0)
	{
		print_image_from_memory(data, data->numbers_pic[number % 10], \
		data->window_width - 45 - pos, height);
		pos = pos + 40;
		number = number / 10;
	}
}
/*
// This function needs to exist, but it is useless for the moment
int	handle_no_event()
{
	return (0);
}
*/
