/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:50:52 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 04:48:26 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_argc(t_fractol *data, int argc, char *argv[]);

int32_t	parser(t_fractol *data, int argc, char *argv[])
{
	if (ft_strncmp(argv[1], "Mandelbrot", -1) == 0
		|| ft_strncmp(argv[1], "mandelbrot", -1) == 0)
		data->plot = MANDELBROT;
	else if (ft_strncmp(argv[1], "Julia", -1) == 0
		|| ft_strncmp(argv[1], "julia", -1) == 0)
		data->plot = JULIA;
	else if (ft_strncmp(argv[1], "Burning ship", -1) == 0
		|| ft_strncmp(argv[1], "burning ship", -1) == 0)
		data->plot = BURNING_SHIP;
	else if (ft_strncmp(argv[1], "Tricorn", -1) == 0
		|| ft_strncmp(argv[1], "tricorn", -1) == 0)
		data->plot = TRICORN;
	else
		return (-1);
	check_argc(data, argc, argv);
	return (1);
}

static void	check_argc(t_fractol *data, int argc, char *argv[])
{
	if (argc != 2 && (data->plot == MANDELBROT
			|| data->plot == BURNING_SHIP || data->plot == TRICORN))
		exit(usage_prompt());
	else if (argc != 4 && data->plot == JULIA)
		exit(usage_prompt());
	if (data->plot == JULIA)
	{
		data->cx = my_atof(argv[2]);
		data->cy = my_atof(argv[3]);
		if ((data->cx < -10 || data->cx > 10)
			|| (data->cy < -10 || data->cy > 10))
			exit(usage_prompt());
	}
}
