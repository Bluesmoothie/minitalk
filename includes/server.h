/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:01:18 by ygille            #+#    #+#             */
/*   Updated: 2024/11/26 19:12:44 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERVER_H
#  define SERVER_H

# include <ft_printf.h>
# include <signal.h>

void	sig_handler(int sig, siginfo_t *info, void *ucontext);

# endif