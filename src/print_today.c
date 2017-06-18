/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_today.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:48:45 by sjones            #+#    #+#             */
/*   Updated: 2017/06/17 19:07:10 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_db.h"

int		print_today(t_db *db)
{
	t_ent	*all;
	t_ent	*today;
	t_ent	*all_meds;
	t_ent	*today_meds;

	all = DE;
	all_meds = get_meds(all);
	today = get_today(all);
	today_meds = get_meds(today);
//	all_puts(DE, stdout);
	(void) all;
	(void) today;
	(void) all_meds;
	(void) today_meds;
	return (1);
}
