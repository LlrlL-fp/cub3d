/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:56:02 by malmany           #+#    #+#             */
/*   Updated: 2025/12/05 16:14:01 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	ps = s;
	i = 0;
	while (i < n)
	{
		ps[i] = c;
		i++;
	}
	return (s);
}

/*#include <string.h>
#include <stdio.h>

int main()
{
	char s[4] = {'a', 'b', 'c', 'd'};
	int i;

	i = 0;
	while(i < 4)
	{
		printf(" valeur de s avant memset : %c\n", s[i]);
		i++;
	}
	ft_memset(s, 0, 2);
	i = 0;
	while(i < 4)
        {
                printf(" valeur de s apres  memset : %c\n", s[i]);
		i++;
        }



}*/
