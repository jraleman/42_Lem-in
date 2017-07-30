/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:58:54 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/27 16:58:55 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Print the rooms.
*/

static void	print_room(void *room)
{
	t_room	*tmp;

	if (room != NULL)
	{
		tmp = (t_room *)room;
		if (tmp->flag == STARTROOM)
			ft_putendl_fd("##start", FT_STD_OUT);
		else if (tmp->flag == ENDROOM)
			ft_putendl_fd("##end", FT_STD_OUT);
		ft_mini_printf("%s %d %d", tmp->name, RESET_COLOUR, \
						tmp->x, RESET_COLOUR, tmp->y, RESET_COLOUR);
	}
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}

/*
** Print the paths.
*/

static void	print_path(void *tunnel)
{
	t_path	*path;

	path = (t_path *)tunnel;
	ft_mini_printf("%s-%s\n", path->door1, RESET_COLOUR, \
					path->door2, RESET_COLOUR);
	return ;
}

/*
** Print the paths.
*/

static void	print_room_colored(void *room)
{
	t_room	*tmp;

	if (room != NULL)
	{
		tmp = (t_room *)room;
		if (tmp->flag == STARTROOM)
			ft_putendl_fd("##start", FT_STD_OUT);
		else if (tmp->flag == ENDROOM)
			ft_putendl_fd("##end", FT_STD_OUT);
		ft_mini_printf("%s %d %d", tmp->name, LIGHT_RED, \
						tmp->x, LIGHT_GREEN, tmp->y, LIGHT_GREEN);
	}
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}

/*
** Print the rooms.
*/

static void	print_path_colored(void *tunnel)
{
	t_path	*path;

	path = (t_path *)tunnel;
	ft_mini_printf("%s-%s\n", path->door1, LIGHT_BLUE, \
					path->door2, LIGHT_BLUE);
	return ;
}

/*
** Print to the stdout the rooms and paths.
*/

void		lemin_print(t_lemin *lemin)
{
	if (lemin->param.ant_colored == FALSE)
		ft_mini_printf("%d\n", lemin->ant_total, RESET_COLOUR);
	else
		ft_mini_printf("%d\n", lemin->ant_total, LIGHT_YELLOW);
	if (lemin->param.room_colored == FALSE)
		ft_lstforeach(lemin->room_list, print_room);
	else
		ft_lstforeach(lemin->room_list, print_room_colored);
	if (lemin->param.path_colored == FALSE)
		ft_lstforeach(lemin->path_list, print_path);
	else
		ft_lstforeach(lemin->path_list, print_path_colored);
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}
