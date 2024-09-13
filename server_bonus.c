/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:21:05 by egenc             #+#    #+#             */
/*   Updated: 2022/03/08 11:32:44 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	kill_checker(int signal, pid_t pid)
{
	if (kill(pid, signal) == -1)
	{
		write(1, "error!", 6);
		exit(1);
	}
}

void	take_bits(int signal, siginfo_t *info, void *ebr)
{
	static char	bits;
	static char	i;

	(void)ebr;
	bits <<= 1;
	if (signal == SIGUSR1)
		bits |= 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", bits);
		if (bits == '\0')
		{
			ft_printf("\nMesajinizin geldigi pid: %d\n", info->si_pid);
			kill_checker(SIGUSR1, info->si_pid);
		}
		bits = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	test;

	(void)ac;
	(void)av;
	test.sa_sigaction = &take_bits;
	if (sigaction(SIGUSR1, &test, NULL) == -1)
		write(1, "error", 5);
	if (sigaction(SIGUSR2, &test, NULL) == -1)
		write(1, "error", 5);
	ft_printf("Serverinizin id'si: %d\n", getpid());
	while (1)
		continue ;
}
