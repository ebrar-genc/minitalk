/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:37:15 by egenc             #+#    #+#             */
/*   Updated: 2022/03/08 11:24:38 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	take_bits(int signal)
{
	static char	bits;
	static char	i;

	bits <<= 1;
	if (signal == SIGUSR1)
		bits |= 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", bits);
		bits = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	test;

	(void)ac;
	(void)av;
	test.sa_handler = &take_bits;
	if (sigaction(SIGUSR1, &test, NULL) == -1)
		write(1, "error", 5);
	if (sigaction(SIGUSR2, &test, NULL) == -1)
		write(1, "error", 5);
	ft_printf("Serverinizin id'si: %d\n", getpid());
	while (1)
		continue ;
}
