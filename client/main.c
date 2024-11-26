/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:57 by ygille            #+#    #+#             */
/*   Updated: 2024/11/26 18:41:43 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: %s <SERVER_PID> <MESSAGE>\n", argv[0]);
		return (1);
	}
	return (0);
}
