/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 15:54:55 by sjones            #+#    #+#             */
/*   Updated: 2017/06/18 13:00:37 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_db.h"

t_ent	*get_meds(t_ent *t)
{
	t_ent	*meds;
	t_ent	*head;

	ft_putendl("entering get_meds");
	if (!t)
		return (NULL);
	while (t && t->categoryid != 1)
		t = t->next;
	ft_putendl("got to the first med rec");
	meds = t;
	head = meds;
	while (meds->next)
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
	if (meds->categoryid != 1)
		meds = NULL;
	ft_putendl("survived getting meds");
	return (head);
}
