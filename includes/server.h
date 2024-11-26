/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:01:18 by ygille            #+#    #+#             */
/*   Updated: 2024/11/26 19:06:23 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERVER_H
#  define SERVER_H

# include <ft_printf.h>
# include <signal.h>

typedef struct sigaction	t_sigaction;

void	sig_handler(int sig, siginfo_t *info, void *ucontext);

# endif