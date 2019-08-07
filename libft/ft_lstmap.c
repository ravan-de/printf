/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 18:42:26 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/01 19:24:54 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;

	newlst = (*f)(lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
		ft_lst_append(newlst, (*f)(lst));
	}
	return (newlst);
}
