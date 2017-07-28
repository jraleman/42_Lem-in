/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 05:05:24 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/27 05:05:25 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Delete all the rooms.
*/

static void	delete_rooms(void *data)
{
	t_room	*room;

	room = (t_room *)data;
	ft_strdel(&room->name);
	ft_lst_rec_free(room->paths);
	free(data);
	data = NULL;
	return ;
}

/*
** Delete all the paths.
*/

static void	delete_paths(void *data)
{
	t_path	*path;

	path = (t_path *)data;
	ft_strdel(&path->door1);
	ft_strdel(&path->door2);
	free(data);
	data = NULL;
	return ;
}

/*
** This is the end.
** Free everything, so we don't have memory leaks. :)
*/

void		lemin_end(t_lemin *lemin)
{
	if (lemin->rooms_list)
	{
		ft_lstforeach(lemin->rooms_list, delete_rooms);
		ft_lst_rec_free(lemin->rooms_list);
	}
	if (lemin->paths_list)
	{
		ft_lstforeach(lemin->paths_list, delete_paths);
		ft_lst_rec_free(lemin->paths_list);
	}
	free(lemin);
	return ;
}
