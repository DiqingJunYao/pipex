/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:07:52 by dyao              #+#    #+#             */
/*   Updated: 2024/06/19 16:19:47 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*first;

	if (*lst == NULL)
		*lst = new;
	else
		first = *lst;
	while (first->next != NULL)
		first = first->next;
	new->next = NULL;
	first->next = new;
}