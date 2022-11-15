/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:02:56 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/04 18:02:57 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_runner;

	while (*lst)
	{
		lst_runner = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_runner;
	}
	*lst = NULL;
}
