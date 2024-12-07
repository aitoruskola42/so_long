/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:51:14 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/07 16:26:12 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	check_enemy_pos2(t_data *data, t_enemy *wolf)
{
	int		i;
	int		j;
	int		counter;

	counter = 0;
	i = 0;
	while (i <= data->rows)
	{
		while (j < data->cols)
		{
			if (data->map[i][j] == ENEMY_KEY)
			{
				wolf[counter].x = i;
				wolf[counter].y = j;
				counter ++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (counter);
}

int	check_enemy_pos(t_data *data)
{
	t_enemy	*wolf;
	int		k;
	int		counter;

	k = 0;
	wolf = (t_enemy *)malloc(check_char(data, ENEMY_KEY) * sizeof(t_enemy));
	counter = check_enemy_pos2(data, wolf);
	while (k < check_char(data, ENEMY_KEY))
	{
		check_enemy_move(data, wolf[k].x, wolf[k].y);
		k++;
	}
	free(wolf);
	return (counter);
}

void	create_threads(t_data *data)
{
	pthread_create(&data->pthread_enemy, NULL, move_enemy, (void *) data);
}
