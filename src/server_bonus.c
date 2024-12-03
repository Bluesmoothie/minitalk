/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/03 15:46:21 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server_bonus.h>

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID : %d\n", getpid());
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;
	static char	*msg = NULL;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << i);
	else
		c &= ~(1 << i);
	if (i == 7)
	{
		if (c == '\0')
			print_message(&msg, info->si_pid);
		message_handler(c, &msg);
		i = 0;
		c = 0;
	}
	else
		i++;
}

void	message_handler(char c, char **msg)
{
	int		size;
	char	*tmp;

	if (!(*msg))
	{
		size = 2;
		*msg = malloc(size);
		(*msg)[0] = c;
		(*msg)[1] = '\0';
	}
	else
	{
		size = ft_strlen(*msg) + 2;
		tmp = ft_strdup(*msg);
		free(*msg);
		*msg = malloc(size);
		ft_strlcpy(*msg, tmp, size);
		(*msg)[size - 2] = c;
		(*msg)[size - 1] = '\0';
	}
}

void	print_message(char **msg, int pid)
{
	ft_printf("Message received from %i :\n", pid);
	ft_printf("%s\n", *msg);
	ft_printf("Transmission ended\n");
	free(*msg);
	*msg = NULL;
}
