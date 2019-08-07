/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_append.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 18:49:19 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/01 19:25:48 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_append(t_list *alst, t_list *new)
{
	while (alst->next != NULL)
		alst = alst->next;
	alst->next = new;
}
