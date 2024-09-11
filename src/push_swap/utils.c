/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:09:31 by tomek             #+#    #+#             */
/*   Updated: 2024/09/12 00:33:29 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_nbr(char *s)
{
	int	i;

	if (s[0] == '\0')
		return (0);
	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *s)
{
	int		sign;
	long	nbr;

	nbr = 0;
	if (*s == '\0')
		return (0);
	sign = 1;
	while (*s == ' ' || *s == '\f' || *s == '\n' \
	|| *s == '\r' || *s == '\t' || *s == '\v')
	{
		s++;
	}
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		nbr = nbr * 10 + (*s - 48);
		s++;
	}
	return (sign * nbr);
}
