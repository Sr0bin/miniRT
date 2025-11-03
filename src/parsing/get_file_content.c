/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:41:53 by jweber            #+#    #+#             */
/*   Updated: 2025/10/28 19:01:35 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_vectors.h"
#include "parsing.h"
#include "minirt.h"
#include <fcntl.h>
#include <unistd.h>

static int	get_each_line(int fd, t_vector *ptr_file_content);
static void	free_file_content(t_vector *ptr_vec);
static int	gnl_failure(int ret);

int	get_file_content(char *filename, t_vector *ptr_file_content)
{
	int		ret;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (FAILURE_OPEN);
	ret = ft_vector_init(ptr_file_content, 10, sizeof(t_line),
			free_file_content);
	if (ret != SUCCESS)
	{
		close(fd);
		return (FAILURE_MALLOC);
	}
	ret = get_each_line(fd, ptr_file_content);
	close(fd);
	if (ret != SUCCESS)
		ft_vector_free(ptr_file_content);
	return (ret);
}

static int	get_each_line(int fd, t_vector *ptr_file_content)
{
	t_line	line;
	int		ret;
	size_t	line_i;

	line_i = 1;
	line.content = (char *)0x1;
	while (line.content != NULL)
	{
		line.line_nbr = line_i;
		line.content = get_next_line(fd, &ret);
		if (ret != SUCCESS)
			return (gnl_failure(ret));
		if (line.content != NULL
			&& (line.content[0] != '\n' && line.content[1] != '\0'))
		{
			ret = ft_vector_add_single(ptr_file_content, &line);
			if (ret != SUCCESS)
				return (FAILURE_MALLOC);
		}
		else if (line.content != NULL)
			free(line.content);
		line_i++;
	}
	return (SUCCESS);
}

static int	gnl_failure(int ret)
{
	if (ret == -3)
		return (FAILURE_MALLOC);
	else
		return (FAILURE_READ);
}

static void	free_file_content(t_vector *ptr_vec)
{
	size_t	i;

	i = 0;
	while (i < ptr_vec->size)
	{
		free(((t_line *)ptr_vec->data)[i].content);
		i++;
	}
	free(ptr_vec->data);
	ptr_vec->size = 0;
	ptr_vec->data_size = 0;
}
