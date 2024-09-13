/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:20:21 by egenc             #+#    #+#             */
/*   Updated: 2022/03/08 11:20:32 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_atoi(const char *str);

int		ft_formats(va_list ap, char c);
int		ft_printf(const char *s, ...);
int		ft_putnbr(int nbr);
int		ft_putstr(char *s);
int		ft_putchar(int c);

#endif