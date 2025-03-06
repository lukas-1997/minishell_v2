/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:39:47 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/12 13:05:09 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fills the memory area pointed to with zeroes (0)
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
		*ptr++ = 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//    void *ft_memory = malloc(10);
//    ft_bzero(ft_memory, 3);
//    printf("%s\n", (char *)ft_memory);
// }