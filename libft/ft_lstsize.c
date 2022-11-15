/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:03:29 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/04 18:03:31 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*list_runner;
	int		i;

	i = 0;
	list_runner = lst;
	while (list_runner != NULL)
	{
		list_runner = list_runner->next;
		i++;
	}
	return (i);
}
