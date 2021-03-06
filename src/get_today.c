/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_today.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 15:53:00 by sjones            #+#    #+#             */
/*   Updated: 2017/06/18 22:47:31 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_db.h"

int		grab_hour(char *time)
{
	char	tmp[2];

	sprintf(tmp, "%.2s", time + 11);
	return (ft_atoi(tmp));
}

t_ent	*get_time(t_ent *t, int start, int end)
{
	t_ent		*today;
	t_ent		*head;
	int			dn;

	head = NULL;
	today = t;
	dn = grab_hour(today->start_date);
	if (dn > end)
		return (NULL);
	while (today->next && dn < start)
	{
		today = today->next;
		dn = grab_hour(today->start_date);
	}
	head = today;
	while (today->next && dn < end)
	{
		today = today->next;
		dn = grab_hour(today->start_date);
	}
	if (grab_hour(today->start_date) > end)
		today = NULL;
	return (head);
}

int		date_grab(char *time)
{
	char	tmp[6];

	sprintf(tmp, "%.2s%.2s%.2s", time + 2, time + 5, time + 8);
	return (ft_atoi(tmp));
}

char	*get_today_help(void)
{
	time_t		ti;
	struct tm	*tm;
	char		*date;

	date = ft_memalloc(8);
	ti = time(NULL);
	tm = localtime(&ti);
	sprintf(date, "%.4d%.2d%.2d", tm->tm_year + 1900, tm->tm_mon + 1,
			tm->tm_mday);
	return (date);
}

t_ent	*get_today(t_ent *t)
{
	t_ent		*today;
	t_ent		*head;
	char		*date;
	int			dn1;
	int			dn2;

	today = NULL;
	date = get_today_help();
	dn1 = ft_atoi(date + 2);
	today = t;
	dn2 = date_grab(today->start_date);
	while (today->next && dn2 < dn1)
	{
		today = today->next;
		dn2 = date_grab(today->start_date);
	}
	head = today;
	while (today->next && dn2 == dn1)
	{
		today = today->next;
		dn2 = date_grab(today->start_date);
	}
	if (date_grab(today->start_date) > dn1)
		today = NULL;
	today = head;
	return (today);
}
