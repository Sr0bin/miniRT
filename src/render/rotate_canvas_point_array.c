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
static void	rotate_around(double (*canvas_point_array)[3],
				size_t nb_rays, double r[3][3]);

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
		rotate_around(canvas_point_array, nb_rays, r1);
	ret = get_r2(r2, direction);
	if (ret != 0)
		rotate_around(canvas_point_array, nb_rays, r2);
	return ;
}

/* This function get then angle 'theta' (and set the appropriate values 
 * for the rotation matrix r1) which is the angle by which
 * a temporary frame is rotated from the 'camera' frame around the
 * 'z' axis of the 'camera' frame (such that this new frame 'x' axis is within
 * the 'x' 'z' plane of the 'world' frame).
 * This frame is also frame rotated by a 'phi' angle (around the 'y' axis)
 * from the 'world' frame.
 *
 * We know how to express the rays from the 'camera' frame in the
 * temporary frame
 *
 * and from these new rays, we can express them in the 'world' frame knowing
 * how much the 'temporary' frame and the 'world' frame are rotated by. (but
 * will be done in get_r1 function)
 *
 * return value :
 *	- if there is no need to rotate : return 1
 *	- if there is a need to rotate : return 0 and set the matrix
 *	to appropriate values
*/
static int	get_r1(double r1[3][3], t_vec3 cam_direction)
{
	double			norm_cam_direction;
	double			angle;

	norm_cam_direction = vector_norm(cam_direction);
	angle = (M_PI / 2.0)
		- acos(vector_get_coord(cam_direction, Y) / norm_cam_direction);
	if ((angle - 0) < 1e-5)
		return (1);
	/* to check but i think thats it ! */
	r1[0][0] = cos(angle);
	r1[0][1] = -sin(angle);
	r1[0][2] = 0;
	r1[1][0] = sin(angle);
	r1[1][1] = cos(angle);
	r1[1][2] = 0;
	r1[2][0] = 0;
	r1[2][1] = 0;
	r1[2][2] = 1;
	return (0);
}

/* this function is similar to get_r1 function, execpt
 * it will get the angle by which the 'temporary' frame is rotated
 * from the the 'world' frame around the 'y' axis
*/
static int	get_r2(double r2[3][3], t_vec3 cam_direction)
{
	double			cam_direction_no_y[3];
	double			norm_cam_direction_no_y;
	double			angle;

	cam_direction_no_y[X] = vector_get_coord(cam_direction, X);
	cam_direction_no_y[Y] = 0;
	cam_direction_no_y[Z] = vector_get_coord(cam_direction, Z);
	norm_cam_direction_no_y = sqrt(cam_direction_no_y[X] * cam_direction_no_y[X]
			+ cam_direction_no_y[Y] * cam_direction_no_y[Y]
			+ cam_direction_no_y[Z] * cam_direction_no_y[Z]);
	if ((norm_cam_direction_no_y - 0) < 1e-5)
		return (1);
	angle = acos(cam_direction_no_y[X] / norm_cam_direction_no_y);
	if (cam_direction_no_y[Z] < 0)
		angle = 2 * M_PI - angle;
	/* to check but i think its that ! */
	r2[0][0] = cos(angle);
	r2[0][1] = 0;
	r2[0][2] = sin(angle);
	r2[1][0] = 0;
	r2[1][1] = 1;
	r2[1][2] = 0;
	r2[2][0] = -sin(angle);
	r2[2][1] = 0;
	r2[2][2] = cos(angle);
	return (0);
}

static void	rotate_around(double (*canvas_point_array)[3],
				size_t nb_rays, double r[3][3])
{
	size_t	i;
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	i = 0;
	while (i < nb_rays)
	{
		tmp_x = r[0][0] * canvas_point_array[i][X]
			+ r[0][1] * canvas_point_array[i][Y]
			+ r[0][2] * canvas_point_array[i][Z];
		tmp_y = r[1][0] * canvas_point_array[i][X]
			+ r[1][1] * canvas_point_array[i][Y]
			+ r[1][2] * canvas_point_array[i][Z];
		tmp_z = r[2][0] * canvas_point_array[i][X]
			+ r[2][1] * canvas_point_array[i][Y]
			+ r[2][2] * canvas_point_array[i][Z];
		canvas_point_array[i][X] = tmp_x;
		canvas_point_array[i][Y] = tmp_y;
		canvas_point_array[i][Z] = tmp_z;
		i++;
	}
	return ;
}
