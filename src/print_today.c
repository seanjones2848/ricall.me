/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_today.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:48:45 by sjones            #+#    #+#             */
/*   Updated: 2017/06/17 20:19:07 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_db.h"

char	*get_mes(t_ent *t)
{
	int		i;
	char	*mes;
	char	*time;

	i = 0;
	while (t->next)
	{
		time = t->start_date + 11;
		time = ft_atoi(time) > 12 ? ft_itoa(ft_atoi(time) - 12) : time;
		sprintf(mes, "you have to %s at %s, ", t->title, time);
		i++;
		t = t->next;
	}
	sprintf(mes, (i > 1) ? "and" : "");
	time = t->start_date + 11;
	time = ft_atoi(time) > 12 ? ft_itoa(ft_atoi(time) - 12) : time;
	sprintf(mes, "you have to %s at %s.", t->title, time);
	return (mes);
}


void	print_meds(FILE *fp, t_ent *morning, t_ent *afternoon, t_ent *evening)
{
	fputs((morning == NULL) ? "0" : "1", fp);
	fputs((afternoon == NULL) ? "0" : "1", fp);
	fputs((evening == NULL) ? "0" : "1", fp);
	fputs((morning == NULL) ? "No morning medication" : get_mes(morning), fp);
	fputs((afternoon == NULL) ? "Medication free afternoon" : get_mes(afternoon), fp);
	fputs((evening == NULL) ? "Evening without medication" : get_mes(evening), fp);
}



int		print_today(t_db *db)
{
	t_ent	*all;
	t_ent	*morning;
	t_ent	*afternoon;
	t_ent	*evening;
	t_ent	*morning_meds;
	t_ent	*afternoon_meds;
	t_ent	*evening_meds;
//	t_ent	*next_event;
	FILE	*fp;

	fp = fopen("today", "w+");
	all = DE;
	morning = get_time(all, 5, 12);
	afternoon = get_time(all, 12, 18);
	evening = get_time(all, 18, 23);
	morning_meds = get_meds(morning);
	afternoon_meds = get_meds(afternoon);
	evening_meds = get_meds(evening);
	print_meds(fp, morning_meds, afternoon_meds, evening_meds);



	fputs(!morning ? "0" : "1", fp);
	fputs(!afternoon ? "0" : "1", fp);
	fputs(!evening ? "0" : "1", fp);

	//	all_puts(DE, stdout);
	return (1);
}
