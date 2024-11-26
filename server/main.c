/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:51 by ygille            #+#    #+#             */
/*   Updated: 2024/11/26 19:13:14 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID : %d\n", getpid());
	act.sa_handler = sig_handler;
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sig == SIGUSR1)
		ft_printf("SIGUSR1 received from client PID : %d\n", info->si_pid);
	else if (sig == SIGUSR2)
		ft_printf("SIGUSR2 received from client PID : %d\n", info->si_pid);
}
