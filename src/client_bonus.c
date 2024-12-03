/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:57 by ygille            #+#    #+#             */
/*   Updated: 2024/12/03 15:24:36 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: %s <MESSAGE> <SERVER_PID>\n", argv[0]);
		return (1);
	}
	ft_printf("Sending : %s to %s\n", argv[1], argv[2]);
	send_sig(ft_atoi(argv[2]), argv[1]);
	ft_printf("Message sent\n");
	return (0);
}

void	send_sig(int pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			if (msg[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(DELAY);
		}
		i++;
	}
	j = 0;
	end_of_transmission(pid);
}

void	end_of_transmission(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		i++;
		usleep(DELAY);
	}
}
