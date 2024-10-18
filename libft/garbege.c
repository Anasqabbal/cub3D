/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbege.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:03:28 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/10/18 17:04:26 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_garb **get_last_node()
{
    static t_garb *node = NULL;
    return &node;
}
void gc_free_all()
{
	t_garb **head = get_last_node();
	t_garb *node = *head;

	while (node != NULL)
	{
		t_garb *next_n = node->next;
		free(node->ptr);
		free(node);
		node = next_n;
	}
	head = NULL;
}
void *gc_malloc(int size)
{
    t_garb **head = get_last_node();
    t_garb *node;
    char *ptr;

    ptr = malloc(size);
    if (!ptr)
        return NULL;
    node = (t_garb *)malloc(sizeof(t_garb));
    if (!node)
        return (free (ptr), NULL);
    node->ptr = ptr;
    node->next = *head;
    *head = node;
    return ptr;
}

