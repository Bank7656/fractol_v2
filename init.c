/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:17:03 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/08 00:47:16 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot_init(t_fractol *data);
static void	julia_init(t_fractol *data);
static void	burning_ship_init(t_fractol *data);
static void	tricorn_init(t_fractol *data);

void    plot_init(t_fractol *data)
{
	if (data->plot == MANDELBROT)
		mandelbrot_init(data);
	else if (data->plot == JULIA)
		julia_init(data);
	else if (data->plot == BURNING_SHIP)
		burning_ship_init(data);
	else if (data->plot == TRICORN)
		tricorn_init(data);
}

static void    mandelbrot_init(t_fractol *data)
{
	data->range.x_min = -2;
	data->range.x_max = 1.0;
	data->range.y_min = -1.5;
	data->range.y_max = 1.5;
	data->zoom = 1.0;
	data->max_iteration = 100.0;
	data->cx = 0;
	data->cy = 0;
}

static void    julia_init(t_fractol *data)
{
	data->range.x_min = -2.0;
	data->range.x_max = 2.0;
	data->range.y_min = -2.0;
	data->range.y_max = 2.0;
	data->zoom = 1.0;
	data->max_iteration = 100.0;
}

static  void    burning_ship_init(t_fractol *data)
{
	data->range.x_min = -2.5;
	data->range.x_max = 2.0;
	data->range.y_min = -1;
	data->range.y_max = 2;
	data->zoom = 1.0;
	data->max_iteration = 100.0;
	data->cx = 0;
	data->cy = 0; 
}

static void	tricorn_init(t_fractol *data)
{
	data->range.x_min = -2;
	data->range.x_max = 1.0;
	data->range.y_min = -1.5;
	data->range.y_max = 1.5;
	data->zoom = 1.0;
	data->max_iteration = 100.0;
	data->cx = 0;
	data->cy = 0;
}