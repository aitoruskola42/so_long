/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:55:02 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/06 15:55:04 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

t_img	*witch_frame( int change, t_data *data)
{
	t_img	*player;

	player = data->player_pic;
	if (data->frames > 0 && data->frames <= 4)
	{
		if (data->s_move_x < 0)
			player = data->player_pic_a[0][data->frames - 1];
		if (data->s_move_x > 0)
			player = data->player_pic_a[1][data->frames - 1];
		if (data->s_move_y < 0)
			player = data->player_pic_a[2][data->frames - 1];
		if (data->s_move_y > 0)
			player = data->player_pic_a[3][data->frames - 1];
	}
	if (change)
		data->frames ++;
	if (data->frames > 4)
		data->frames = 1;
	return (player);
}
