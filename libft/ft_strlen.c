/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:18:57 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/05 19:22:03 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
		char *str = "\0";
		printf("%zu\n", ft_strlen(str));
		printf("%zu", strlen(str));
		return 0;
}
*/
