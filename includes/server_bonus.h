/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:01:18 by ygille            #+#    #+#             */
/*   Updated: 2024/12/03 15:34:18 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERVER_H
#  define SERVER_H

# include <ft_printf.h>
# include <libft.h>
# include <signal.h>

void	*sig_handler(int sig, siginfo_t *info, void *context);
void	message_handler(char c, char **msg);
void	print_message(char **msg, int pid);

# endif