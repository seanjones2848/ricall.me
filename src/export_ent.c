/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_ent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:47:46 by sjones            #+#    #+#             */
/*   Updated: 2017/06/14 22:41:04 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_db.h"

int		export_ent(t_db *db, char *event_id)
{
	t_ent	*t;
	FILE	*fp;

	printf("exporting %s now\n", event_id);
	t = DE;
	fp = fopen(t->event_id, "w+");
	while (t->event_id != event_id)
		t = t->next;
	if (t)
	{
		all_puts(t, fp);
	}
	else
		printf("There was no entry for %s\n", event_id);
	return (2);
}
