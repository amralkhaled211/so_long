/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:06:13 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/13 21:06:16 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*new_str;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
/*
#include <stdio.h>
int	main()
{
	char const s[] = "hello shawty";
	char const b[] = "hello shawty";
	
	char *sub = ft_strjoin(s, b);
	
	printf("%s", sub);
}
*/
