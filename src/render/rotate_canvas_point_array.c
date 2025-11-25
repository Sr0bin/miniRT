/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_canvas_point_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:38:11 by jweber            #+#    #+#             */
/*   Updated: 2025/11/25 12:35:40 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "render.h"
#include "vector.h"
#include <math.h>

static int	get_r1(double r1[3][3], t_vec3 direction);
static int	get_r2(double r1[3][3], t_vec3 direction);

/* this function will transform all canvas point array from the camera frame
 * (where it is currently expressed) to the world frame by doing two rotation.
 *
 * explanation of the two rotation :
 *
 * at this point :
 *		- we know the coordinates of the ray in the camera frame.
 *		- we expressed our rays, where 'y' axis represent the height of the 
 *		screen
 *		and the 'z' axis representing the width of the screen
 *			(so the center point of the screen (if there is one) is a ray aligned
 *			with the 'x' axis (1, 0, 0) in the camera frame)
 *
 * But we whant to explain them in the world frame (where we know all objects
 * coordinates)
 *
 * suppose we know two frame, R1 and R2, expressed int the same point and 
 * having an axis in common, 'z' for example. And R2 is rotated by a positive
 * theta angle from R2 around that 'z' axis. 
 * Knowing that suppose we know a vector in R2, We can express it in R1.
 *
 * Using this, the idea is to do several rotation, to express the rays
 * int the 'world' frame.
 *
 * The idea is to find to rotation to make the 'world' 'x' axis to be aligned
 * with the 'camera' direction (which correspond to the direction of the 'x' 
 * axis of the camera expressed in terms of the 'world' frame)
 *
 * Visualisation of the two rotation :  
 *	- one around the 'y' axis of the 'world' frame to align 'x' axis with 
 *	the projection of the camera direction on the 'x' 'z' plane.
 *
 *	- then one in this new frame around the new 'z' axis to make the new 'x' 
 *	be aligned with the camera direction
 *	
 * So the center vector if there is one, should exactly equal the camera
 * direction
*/
void	rotate_canvas_point_array(double (*canvas_point_array)[3],
			size_t nb_rays, t_vec3 direction)
{
	double	r1[3][3];
	double	r2[3][3];
	int		ret;

	ret = get_r1(r1, direction);
	if (ret != 0)
		rotate_around(canvas_point_array, r1);
	ret = get_r2(r2, direction);
	if (ret != 0)
		rotate_around(canvas_point_array, r2);
	return ;
}

/* This function get then angle 'theta' which is the angle by which
 * a temporary frame is rotated from the 'camera' frame around the
 * 'z' axis of the 'camera' frame.
 * This frame is a frame rotated by a 'phi' angle from the 'world' frame.
 *
 * then, we know how to express the rays from the 'camera' frame in the
 * temporary frame
 *
 * and from these new rays, we can express them in the 'world' frame knowing
 * how much the 'temporary' frame and the 'world' frame are rotated by.
 *
 * return value :
 *	- if there is no need to rotate : return 1
 *	- if there is a need to rotate : return 0 and set the matrix
 *	to appropriate values
*/
static int	get_r1(double r1[3][3], t_vec3 direction)
{
	// a supprimer tout ça
	double			direction_no_y[3];
	double			norm;
	double			angle;

	direction_no_y[X] = vector_get_coord(direction, X);
	direction_no_y[Y] = 0;
	direction_no_y[Z] = vector_get_coord(direction, Z);
	norm = sqrt(direction_no_y[X] * direction_no_y[X]
			+ direction_no_y[Y] * direction_no_y[Y]
			+ direction_no_y[Z] * direction_no_y[Z]);
	if ((norm - 0) < 1e-5)
		return (1);
	angle = acos(direction_no_y[X] / norm);
	if (direction_no_y[Z] < 0)
		angle = 2 * M_PI - angle;
	r1[0][0] = cos(angle);
	r1[0][1] = 0;
	r1[0][2] = sin(angle);
	r1[1][0] = 0;
	r1[1][1] = 1;
	r1[1][2] = 0;
	r1[2][0] = -sin(angle);
	r1[2][1] = 0;
	r1[2][2] = cos(angle);
	return (0);
}

/* this function is similar to get_r1 function, execpt
 * it will get the angle by which to rotate point around
 * 'z' axis (from the calculated point rotated, wait i'm not good here ?
*/
static int	get_r2(double r2[3][3], t_vec3 direction)
{
	double			norm;
	double			angle;
}
