/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:22:11 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/05 23:55:15 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	z;
	char			*str;

	str = (char *)s;
	z = 0;
	while (str[z])
	{
		if (str[z] == (char)c)
			return (str + z);
		z++;
	}
	if (c == '\0')
		return (str + z);
	return (0);
}
