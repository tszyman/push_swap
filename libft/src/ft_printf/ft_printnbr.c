/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:54:37 by tomek             #+#    #+#             */
/*   Updated: 2024/09/10 22:12:21 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_printnbr(long n, int base, char *symbols)
{
	int		count;

	if (n < 0)
	{
		ft_printchar('-');
		return (ft_printnbr(-n, base, symbols) + 1);
	}
	else if (n < base)
		return (ft_printchar(symbols[n]));
	else
	{
		count = ft_printnbr(n / base, base, symbols);
		return (count + ft_printnbr(n % base, base, symbols));
	}
}
