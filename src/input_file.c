/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:48:24 by sjones            #+#    #+#             */
/*   Updated: 2017/06/15 21:05:28 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_db.h"

int		input_file(t_db *db)
{
	FILE	*fp;
	char	*tmp;
	char	*line;
	int		k;

	fp = fopen("../output_file.json", "r+");
	k = 0;
    line = "";
	db->ents = NULL;
    get_next_line(fileno(fp), &tmp);
	while (get_next_line(fileno(fp), &tmp) > 0)
	{
		if (k % 17 == 1)
            db->entry_count += 1;
		else if (k % 17 == 0)
		{
			line = ft_strjoin(line, tmp);
			add_ent(db, line);
			line = "";
		}
		else
			line = ft_strjoin(line, tmp);
		k += 1;
	}
	fclose(fp);
	return (1);
}
