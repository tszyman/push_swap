/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:19:43 by tomek             #+#    #+#             */
/*   Updated: 2024/03/14 21:02:14 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr);

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		nbr;

	nbr = 0;
	if (*nptr == '\0')
		return (0);
	sign = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' \
	|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + (*nptr - 48);
		nptr++;
	}
	return (sign * nbr);
}
