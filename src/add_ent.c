/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:46:41 by sjones            #+#    #+#             */
/*   Updated: 2017/06/18 22:33:18 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_db.h"

time_t	get_mktime(char *date)
{
	struct tm	tm;
	time_t		ti;

	if (strptime(date, "%Y-%m-%dT%H:%M:%S", &tm) != NULL)
		ti = mktime(&tm);
	return (ti);
}

void	add_ent_help(t_ent *t1, t_ent *t2)
{
	t_ent		*t3;

	t3 = t1->next;
	t1->next = t2;
	t1->next->next = t3;
}

void	add_ent(t_db *db, char *line)
{
	t_ent		*t1;
	t_ent		*t2;
	time_t		e1;
	time_t		e2;

	if (DE == NULL)
	{
		db->entry_count = 1;
		begin_list(db, line);
		return ;
	}
	t1 = DE;
	t2 = init_ent(line);
	e1 = get_mktime(t1->start_date);
	e2 = get_mktime(t2->start_date);
	while (t1->next != NULL && e1 > e2)
	{
		t1 = t1->next;
		e2 = get_mktime(t2->start_date);
	}
	if (ft_strcmp(t1->event_id, t2->event_id) != 0)
	{
		db->entry_count += 1;
		add_ent_help(t1, t2);
	}
}
