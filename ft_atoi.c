/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:57:52 by egenc             #+#    #+#             */
/*   Updated: 2022/03/08 11:07:57 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		neg;

	neg = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		++str;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			neg *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (neg * res > 2147483647)
			return (-1);
		else if (neg * res < -2147483647)
			return (0);
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * neg);
}
/*
int main()
{
	printf("%d", ft_atoi("-121--23"));
    //girilen char degeri inte cevirir
}*/
