/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:07:00 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 13:07:53 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error_type
{
	IMG_CREAT,
	IMG_2_WINDOW,
	MLX_INIT,
}	t_err;

int	error_manager_exec(t_err err_type);

#endif
