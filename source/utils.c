/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:02:51 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 19:39:01 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_file(char *p)
{
	int	fd;

	fd = open(p, O_RDONLY);
	if (fd < 0)
	{
		printf("Eroor\n file aint valid\n");
		exit(1);
	}
	return (fd);
}

t_element_num	ft_counter(void)
{
	t_element_num	count;

	count.collecting = 0;
	count.exit = 0;
	count.empty = 0;
	count.start = 0;
	count.moves = 0;
	return (count);
}

void	count_element(t_element_num *count, char c)
{
	if (c == 'C')
		count->collecting++;
	else if (c == 'E')
		count->exit++;
	else if (c == 'P')
		count->start++;
	else if (c == '0')
		count->empty++;
}
