/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_today.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:48:45 by sjones            #+#    #+#             */
/*   Updated: 2017/06/18 22:40:23 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_db.h"

char	*get_mes(t_ent *t)
{
	int		i;
	char	mes[2048];
	char	*ret;
	char	hour[2];

	i = 0;
	if (t == NULL)
		return ("Nothing here\n");
	while (t->next)
	{
		sprintf(hour, "%.2s", t->start_date + 11);
		sprintf(mes, "you have %s at %s o'clock, ", t->title, hour);
		i++;
		if (t->next != NULL)
			t = t->next;
	}
	sprintf(mes, (i > 1) ? "and" : "");
	sprintf(hour, "%.2s", t->start_date + 11);
	sprintf(mes, "your going to %s at around %d o'clock.\n",
			ft_strcmp(t->title, "") == 0 ? "an event" : t->title,
			ft_atoi(hour) % 12);
	ret = ft_strdup(mes);
	return (ret);
}

void	print_meds(FILE *fp, t_ent *morning, t_ent *afternoon, t_ent *evening)
{
	fputs((morning == NULL) ? "0\n" : "1\n", fp);
	fputs((afternoon == NULL) ? "0\n" : "1\n", fp);
	fputs((evening == NULL) ? "0\n" : "1\n", fp);
	fputs(get_mes(morning), fp);
	fputs(get_mes(afternoon), fp);
	fputs(get_mes(evening), fp);
}

void	print_next(FILE *fp, t_ent *today)
{
	time_t		ti;
	struct tm	*tm;
	char		now[4];
	int			n1;
	int			n2;

	ti = time(NULL);
	tm = localtime(&ti);
	n1 = (tm->tm_hour * 100) + tm->tm_min;
	printf("%d\n", n1);
	sprintf(now, "%.2d%.2d", tm->tm_hour, tm->tm_min);
	n1 = ft_atoi(now);
	printf("%d\n", n1);
	n2 = ((ft_atoi(ft_strdup(today->start_date + 11)) * 100) +
			(ft_atoi(ft_strdup(today->start_date + 14))));
	while (today && (n1 / 100) > (n2 / 100))
	{
		if (today->next)
			today = today->next;
		n2 = ((ft_atoi(ft_strdup(today->start_date + 11)) * 100) +
				(ft_atoi(ft_strdup(today->start_date + 14))));
	}
	if (today == NULL)
		fputs("0\nnothing coming up\n", fp);
	else
	{
		fprintf(fp,
			"1\nwithin the hour your event %s is coming up at %.2d:%.2d\n",
			today->title, n2 / 100, n2 % 100);
	}
}

void	print_impending(FILE *fp, t_ent *today)
{
	time_t		ti;
	struct tm	*tm;
	char		now[4];
	int			n1;
	int			n2;

	ti = time(NULL);
	tm = localtime(&ti);
	n1 = (tm->tm_hour * 100) + tm->tm_min;
	printf("%d\n", n1);
	sprintf(now, "%.2d%.2d", tm->tm_hour, tm->tm_min);
	n1 = ft_atoi(now);
	printf("%d\n", n1);
	n2 = ((ft_atoi(ft_strdup(today->start_date + 11)) * 100) +
			(ft_atoi(ft_strdup(today->start_date + 14))));
	while (today && n1 / 100 > n2 / 100)
	{
		if (today->next)
			today = today->next;
		n2 = ((ft_atoi(ft_strdup(today->start_date + 11)) * 100) +
				(ft_atoi(ft_strdup(today->start_date + 14))));
	}
	if (today == NULL)
		fputs("0\nnothing coming up\n", fp);
	else if (n1 % 100 + 10 > n2 % 100)
	{
		fprintf(fp, "1\nyour event %s is coming up in the next 10 minutes\n",
				today->title);
	}
	else
		fputs("0\nnothing coming up\n", fp);
}

int		print_today(t_db *db)
{
	t_ent	*all;
	t_ent	*today;
	t_ent	*morning;
	t_ent	*afternoon;
	t_ent	*evening;
	t_ent	*morning_meds;
	t_ent	*afternoon_meds;
	t_ent	*evening_meds;
	FILE	*fp;

	all = DE;
	all_puts(all, stdout);
	today = all == NULL ? NULL : get_today(all);
	all_puts(today, stdout);
	morning = today == NULL ? NULL : get_time(today, 5, 12);
	all_puts(morning, stdout);
	afternoon = today == NULL ? NULL : get_time(today, 12, 18);
	all_puts(afternoon, stdout);
	evening = today == NULL ? NULL : get_time(today, 18, 23);
	all_puts(evening, stdout);
	morning_meds = morning == NULL ? NULL : get_meds(morning);
	all_puts(morning_meds, stdout);
	afternoon_meds = afternoon == NULL ? NULL : get_meds(afternoon);
	all_puts(afternoon_meds, stdout);
	evening_meds = evening == NULL ? NULL : get_meds(evening);
	all_puts(evening_meds, stdout);
	fp = fopen("../today.txt", "w+");
	print_meds(fp, morning_meds, afternoon_meds, evening_meds);
	fclose(fp);
	fp = fopen("../today.txt", "a+");
	print_meds(fp, morning, afternoon, evening);
	print_next(fp, today);
	print_impending(fp, today);
	fclose(fp);
	return (1);
}
