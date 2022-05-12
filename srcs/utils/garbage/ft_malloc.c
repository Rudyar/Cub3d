/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:09:12 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/12 12:04:01 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	ft_garb_addback(t_data *data, t_garbage *new)
{
	while (data->garbage->next)
		data->garbage = data->garbage->next;
	new->prev = data->garbage;
	data->garbage->next = new;
	while (data->garbage->prev)
		data->garbage = data->garbage->prev;
}

t_garbage	*ft_garb_lstnew(void *ptr, t_data *data)
{
	t_garbage	*new;

	new = malloc(sizeof(*new));
	if (!new)
	{
		free_all(data);
		printf("Error\ncub3d: malloc error\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

void	*ft_malloc(size_t size, t_data *data)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		free_all(data);
		printf("Error\ncub3d: malloc error\n");
		exit(EXIT_FAILURE);
	}
	if (data->garbage && data->garbage->ptr)
		ft_garb_addback(data, ft_garb_lstnew(ptr, data));
	else if (data->garbage)
	{
		data->garbage->prev = NULL;
		data->garbage->ptr = ptr;
		data->garbage->next = NULL;
	}
	return (ptr);
}
