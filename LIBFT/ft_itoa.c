/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 07:30:21 by smadie            #+#    #+#             */
/*   Updated: 2021/12/26 21:19:16 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_itoa(int n)
{
	int				size;
	unsigned int	unbr;
	char			*str;

	size = ft_count_digit(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	unbr = n;
	if (n < 0)
	{
		str[0] = '-';
		unbr = -unbr;
	}
	str[size] = '\0';
	size--;
	while ((n < 0 && size >= 1) || (n >= 0 && size >= 0))
	{
		str[size] = (unbr % 10 + '0');
		unbr = unbr / 10;
		size--;
	}
	return (str);
}
