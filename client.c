/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:37:17 by egenc             #+#    #+#             */
/*   Updated: 2022/03/08 11:19:01 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	kill_checker(int signal, pid_t pid)
{
	if (kill(pid, signal) == -1)
	{
		write(1, "error!", 6);
		exit(1);
	}
}

void	send_bits(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill_checker(SIGUSR1, pid);
		else
			kill_checker(SIGUSR2, pid);
		i--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;
	char	*data;

	pid = ft_atoi(av[1]);
	i = 2;
	while (i < ac)
	{
		data = av[i];
		while (*data)
			send_bits(*data++, pid);
		send_bits(' ', pid);
		i++;
	}
	send_bits('\0', pid);
}
