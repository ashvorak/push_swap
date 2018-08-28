/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:46:37 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/21 15:47:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cheсker.h"

void		print_help(void)
{
	ft_printf("{blue}|************************************\
*************|{eoc}\n");
	ft_printf("{blue}|*{eoc} usage : ./push_swap -[ARGS]                 \
	{blue} *|{eoc}\n");
	ft_printf("{blue}|*{eoc} usage : ./cheker -[FLAGS] -[ARGS]           \
	{blue} *|{eoc}\n");
	ft_printf("{blue}|* {eoc} [FLAGS]: \
-n : number of operations{blue}           *|{eoc}\n");
	ft_printf("{blue}|* {eoc}       :  \
-s : print stacks step by step{blue}      *|{eoc}\n");
	ft_printf("{blue}|* {eoc}       : \
-ss : print stack size(only with -s) {blue}*|{eoc}\n");
	ft_printf("{blue}|* {eoc}       :  \
-o : print every operation{blue}          *|{eoc}\n");
	ft_printf("{blue}|* {eoc}       :  \
-c : make color                     {blue}*|{eoc}\n");
	ft_printf("{blue}|*******************\
******************************|{eoc}\n");
}
