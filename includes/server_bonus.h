/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:01:18 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 16:04:05 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <ft_printf.h>
# include <libft.h>
# include <signal.h>

# define BUFF 1024

void	sig_handler(int sig, siginfo_t *info, void *context);
void	message_handler(char c, char **msg);
void	print_message(char **msg, int pid);

#endif