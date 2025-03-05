/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:46:10 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/05 16:24:09 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    toggle_mode(t_fractol *data)
{
    long double   cx;
    long double   cy;
    int32_t mouse_x;
    int32_t mouse_y;

    mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
    if (mouse_x <= data->image->width && mouse_y <= data->image->height)
    {
        data -> cx = pixel_to_complex_x(data, mouse_x);
        data -> cy = pixel_to_complex_y(data, mouse_y);   
        plot(data, 0);
    }
}