/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:51 by ygille            #+#    #+#             */
/*   Updated: 2024/12/04 16:55:05 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID : %d\n", getpid());
	act.sa_handler = sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}

void	sig_handler(int sig)
{
	static char	c = 0;
	static int	i = 0;
	static char	*msg = NULL;

	if (sig == SIGUSR1)
		c |= (1 << i);
	else
		c &= ~(1 << i);
	if (i == 7)
	{
		if (c == '\0')
			print_message(&msg);
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

	size = ft_strlen(*msg) + 2;
	if (!(*msg))
	{
		*msg = malloc(size);
		if (!*msg)
			exit(1);
		(*msg)[0] = c;
		(*msg)[1] = '\0';
	}
	else
	{
		tmp = ft_strdup(*msg);
		free(*msg);
		*msg = NULL;
		*msg = malloc(size);
		if (!*msg)
			exit(1);
		ft_strlcpy(*msg, tmp, size);
		free(tmp);
		(*msg)[size - 2] = c;
		(*msg)[size - 1] = '\0';
	}
}

void	print_message(char **msg)
{
	ft_printf("Message received :\n");
	ft_printf("%s\n", *msg);
	ft_printf("Transmission ended\n");
	free(*msg);
	*msg = NULL;
}
