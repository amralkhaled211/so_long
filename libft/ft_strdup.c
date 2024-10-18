/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:34:32 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/11 21:34:34 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int main() {
    const char *original = "Hello, World!";
    
    char *duplicate = strdup(original);
    printf("Original String: %s\n", original);
    printf("Duplicate String: %s\n", duplicate);
    
    free(duplicate);
    return 0;
}
*/
