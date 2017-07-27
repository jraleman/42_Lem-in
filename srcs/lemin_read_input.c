#include "libft.h"
#include "lemin.h"

/*
** ...
*/

static int		is_command(char *line)
{
	int ret;

	if (*line != '#')
		ret = 0;
	else if (ft_strequ("##start", line))
		ret = STARTROOM;
	else if (ft_strequ("##end", line))
		ret = ENDROOM;
	else
		ret = NORMAL;
	return (ret);
}

/*
** ...
*/

static int		is_room(char *line)
{
	while (*line && *line != ' ')
		line++;
	if (*line != ' ')
		return (0);
	line++;
	if (*line == '-')
		line++;
	while (*line && ft_isdigit(*line))
		line++;
	if (*line != ' ')
		return (0);
	line++;
	if (*line == '-')
		line++;
	while (*line && ft_isdigit(*line))
		line++;
	if (*line != '\0')
		return (0);
	return (1);
}

/*
** ...
*/

static int		is_path(char *line, t_list *rooms)
{
	t_path		tmp;

	if (ft_strchr(line, '-'))
	{
		tmp.door1 = ft_strsub(line, 0, ft_strlchr(line, '-'));
		tmp.door2 = ft_strdup(line + ft_strlchr(line, '-') + 1);
		if ((get_room_by_name(tmp.door1, rooms)
			&& get_room_by_name(tmp.door2, rooms)))
		{
			free(tmp.door1);
			free(tmp.door2);
			return (1);
		}
		else
		{
			free(tmp.door1);
			free(tmp.door2);
			return (0);
		}
	}
	else
		return (0);
}

int			lemin_read_input(t_list **rooms, t_list **paths)
{
	int		ret;
	char	*line;

	int		flag = NORMAL;
	int		rooms_done = 0;

	while ((ret = get_next_line(0, &line)))
	{

		//if (lemin_validate(*rooms, *paths, line) == ERROR)
		// ret = ERROR;
		//ft_puterror("Invalid file! :(", ERROR);
			//exit(ERROR);
		if (ret == -1)
			ft_memdel((void **)&line);






		if (is_command(line))
			flag = (flag == NORMAL) ? is_command(line) : flag;
		else if (is_room(line) && !rooms_done)
		{
			*rooms = ft_lstpush(*rooms, init_room(line, flag));
			flag = NORMAL;
		}
		else if (is_path(line, *rooms) && (rooms_done = 1))
			*paths = ft_lstpush(*paths, init_path(line));

		else
			break ;
	}
	free(line);
	return (ret);
}
