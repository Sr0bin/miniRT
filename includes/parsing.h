/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:43:09 by jweber            #+#    #+#             */
/*   Updated: 2025/10/23 16:42:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "ft_vectors.h"

# define WHITE_SPACE " \f\n\r\t\v"

int	parsing(int argc, char **argv, t_vector *ptr_objects);
int	check_args(int argc, char **argv);
int	get_file_content(char *filename, t_vector *ptr_file_content);

#endif // !PARSING_H
