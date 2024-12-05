/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:41:03 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 16:09:12 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <ft_printf.h>
# include <libft.h>
# include <signal.h>

void	send_sig(int pid, char *msg);
void	end_of_transmission(int pid);
void	sig_handler(int sig, siginfo_t *info, void *context);

int		g_ack;

#endif