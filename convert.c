/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:46:00 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/07 22:44:38 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double pixel_to_complex_x(t_fractol *data, int32_t x_pixel)
{
	long double min;
	long double max;
	long double complex_x;
	
	min = data->range.x_min;
	max = data->range.x_max;
	complex_x = min + (max - min) * ((long double)x_pixel / data->mlx->width);
	return (complex_x);    
}

long double pixel_to_complex_y(t_fractol *data, int32_t y_pixel)
{
	long double max;
	long double complex_y;
	long double aspect_ratio;
	long double y_range;

	aspect_ratio = data->image->width / data->image->height;
	y_range = (data->range.x_max - data->range.x_min) / aspect_ratio;	
	max = data->range.y_min + y_range;
	complex_y = max - y_range * ((long double)y_pixel/data->mlx->height);
	return (complex_y);    
}