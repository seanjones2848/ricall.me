/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 15:54:55 by sjones            #+#    #+#             */
/*   Updated: 2017/06/18 20:49:03 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_db.h"

t_ent	*get_meds(t_ent *t)
{
	t_ent	*meds;
	t_ent	*head;

	if (!t)
		return (NULL);
	while (t && t->categoryid != 1)
		t = t->next;
	meds = t;
	head = !meds ? NULL : meds;
	all_puts(head, stdout);
	while (meds && meds->categoryid == 1)
	{
		if (meds->categoryid == 1)
		{
			all_puts(meds, stdout);
			if (meds->next && meds->next->categoryid != 1)
				meds->next = meds->next->next;
		}
		if (meds->next)
			meds = meds->next;
	}
	return (head);
}
