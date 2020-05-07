/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:50:26 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 15:30:11 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*sd;
	t_files			*head;
	t_options		options;
	head = NULL;
	dirp = opendir(".");
	while ((sd = readdir(dirp)))
		ft_add_link_end(&head, ft_strdup(sd->d_name));
	closedir(dirp);
	ft_sort_list(&head);
	ft_files_set_hidden(&head, HIDE);
	ft_options_zero(&options);
	ft_files_stat("./", &head);
	if (argc > 1)
		ft_args(argv, &options, &head);
	ft_print_parse_opt(&options, &head);
	ft_free_list(&head);
	return (0);
}
