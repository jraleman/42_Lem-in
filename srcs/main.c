/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 03:44:41 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/27 03:44:41 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Let's rock and roll!
*/

int			main(void)
{
	t_lemin	*lemin;

	lemin = lemin_init();
	lemin_print(lemin->rooms_list, lemin->paths_list, lemin->ants_total);
	lemin_start(lemin->rooms_list, lemin->paths_list);
	if (lemin_validate(lemin) != TRUE)
	{
		lemin_end(lemin);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}
	lemin_loop(lemin, lemin->ants_list, lemin->ants_total);
	return (0);
}
