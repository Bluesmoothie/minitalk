/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:51 by ygille            #+#    #+#             */
/*   Updated: 2024/11/27 18:40:17 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID : %d\n", getpid());
	act.sa_handler = sig_handler;
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

	if (sig == SIGUSR1)
		c |= (1 << i);
	else
		c &= ~(1 << i);
	if (i == 7)
	{
		if (c == '\0')
			ft_printf("\nTransmission ended\n");
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	else
		i++;
}
