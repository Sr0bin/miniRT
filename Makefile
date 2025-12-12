# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 17:14:59 by jweber            #+#    #+#              #
#    Updated: 2025/12/11 18:57:30 by rorollin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

#SOURCES######################

SOURCES_DIR = src

MATRIX_DIR = matrix
MATRIX_FILES = matrix_core.c matrix_elem.c matrix_operations.c

MLX_SETUP_DIR = mlx_setup
MLX_SETUP_FILES = mlx_setup.c \
				  mlx_start.c \
				  mlx_free_all.c \


PARSING_DIR = parsing
PARSING_FILES = parsing.c \
				get_file_content.c \
				parse_file_content.c \
				check_objects.c \
				fill_obj_content.c \
				fill_obj_ambient.c \
				fill_obj_camera.c \
				fill_obj_light.c \
				fill_obj_sphere.c \
				fill_obj_plane.c \
				fill_plane_coef.c \
				fill_obj_cylinder.c \
				fill_coordinates.c \
				fill_colors.c \
				fill_direction.c \
				free_obj_vector.c \
				check_args.c \
				fail_add_msg.c \
				init_msg_atof_failed.c \
				init_msg_atoi_failed.c \
				init_msg_wrong_color_value.c \
				is_normed.c \

PRINTING_DIR = printing
PRINTING_FILES = print_error.c \
				 print_types.c \
				 print_objects.c \
				 print_mlx_stats.c \

RENDER_DIR = render
RENDER_FILES = render.c \
			   prepare_rays.c \
			   free_rays.c \
			   fill_canvas_point_arrays_distance_variation.c \
			   fill_canvas_point_arrays_angle_variation.c \
			   normalize_canvas_point_array.c \
			   rotate_canvas_point_array.c \
			   rotate_double3.c \
			   set_rotation_matrix.c \
			   test_intersection_jules.c \
			   my_dot_product.c \
			   my_norm_from_vec.c \
			   color_operations.c \
			   light_coeff.c \

VEC3_DIR = utils/vec3
VEC3_FILES = vec3_core.c vec3_operations.c

VEC4_DIR = utils/vec4
VEC4_FILES = vec4_core.c vec4_operations.c

POINT3_DIR = utils/point3
POINT3_FILES = point3_core.c point3_operations.c

POINT4_DIR = utils/point4
POINT4_FILES = point4_core.c point4_operations.c

MAT3_DIR = utils/mat3
MAT3_FILES = mat3_core.c mat3_elem.c mat3_operations.c

MAT4_DIR = utils/mat4
MAT4_FILES = mat4_core.c mat4_elem.c mat4_operations.c

RAY_DIR = $(RENDER_DIR)/ray
RAY_FILES = ray_core.c

INTERSECTION_DIR = $(RENDER_DIR)/intersection
INTERSECTION_FILES = intersection.c check_intersect_sphere.c check_intersect_plane.c\
					 intersect_operations.c \
					 polynomial.c\
					check_intersect_cylinder.c \


SCN_OBJ_DIR = scene_objects
SCN_OBJ_FILES = search_object.c scene_core.c

OBJECT_DIR = object
OBJ_FILES = object_normal.c object_color.c

SOURCES_NAME = $(addprefix $(PARSING_DIR)/,$(PARSING_FILES)) \
			   $(addprefix $(PRINTING_DIR)/,$(PRINTING_FILES)) \
			   $(addprefix $(MLX_SETUP_DIR)/,$(MLX_SETUP_FILES)) \
			   $(addprefix $(MATRIX_DIR)/,$(MATRIX_FILES)) \
			   $(addprefix $(VEC3_DIR)/,$(VEC3_FILES)) \
			   $(addprefix $(VEC4_DIR)/,$(VEC4_FILES)) \
			   $(addprefix $(POINT3_DIR)/,$(POINT3_FILES)) \
			   $(addprefix $(POINT4_DIR)/,$(POINT4_FILES)) \
			   $(addprefix $(MAT3_DIR)/,$(MAT3_FILES)) \
			   $(addprefix $(MAT4_DIR)/,$(MAT4_FILES)) \
			   $(addprefix $(RAY_DIR)/,$(RAY_FILES)) \
			   $(addprefix $(INTERSECTION_DIR)/,$(INTERSECTION_FILES)) \
			   $(addprefix $(SCN_OBJ_DIR)/,$(SCN_OBJ_FILES)) \
			   $(addprefix $(OBJECT_DIR)/,$(OBJ_FILES)) \
			   $(addprefix $(RENDER_DIR)/, $(RENDER_FILES)) \


#SOURCES_GRAPHIC = 

SOURCES = main.c \
		  $(addprefix $(SOURCES_DIR)/,\
		  $(SOURCES_NAME)\
		  )
		  # $(addprefix graphic/, $(SOURCES_GRAPHIC))\
		  # $(addprefix .test/, $(SOURCES_DEBUG))\
		  


#OBJECTS#######################

OBJ_DIR = .obj

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

#DEPS##########################

DEPS = $(OBJECTS:%.o=%.d)

#INCLUDES#######################

HEADERS_DIR = includes/ $(LIBFT_DIR)/includes/ $(MINILIBX_DIR)/

INCLUDES = $(addprefix -I , $(HEADERS_DIR))

#LIBFT########################

LIBFT_DIR = $(SOURCES_DIR)/libft

LIBFT_PATH = $(LIBFT_DIR)/libft.a

#MINILIBX#####################

MINILIBX_DIR = $(SOURCES_DIR)/minilibx-linux

MINILIBX = libmlx.a

MINILIBX_PATH = $(MINILIBX_DIR)/$(MINILIBX)

#CC#####################

CC = cc

CFLAGS_DEBUG = -Wall -Wextra -Werror -MMD -MP -ggdb3 -Wshadow -Wconversion -Wsign-conversion -Wmissing-prototypes \
-Wformat=2 -Wformat-security -Wnull-dereference -Wstack-protector -Wfloat-equal -Wpointer-arith \
-Wcast-align -Wundef -Wbad-function-cast -Wstrict-overflow=4 -Wdouble-promotion -Walloca -Wvla \
-Wwrite-strings -Wuninitialized -fno-delete-null-pointer-checks -fno-omit-frame-pointer -std=c11

CFLAGS_DEBUG_NO_CASE_ALIGN = -Wall -Wextra -Werror -MMD -MP -ggdb3 -Wshadow -Wconversion -Wsign-conversion -Wmissing-prototypes \
-Wformat=2 -Wformat-security -Wnull-dereference -Wstack-protector -Wfloat-equal -Wpointer-arith \
-Wundef -Wbad-function-cast -Wstrict-overflow=4 -Wdouble-promotion -Walloca -Wvla \
-Wwrite-strings -Wuninitialized -fno-delete-null-pointer-checks -fno-omit-frame-pointer -std=c11 -O3

CFLAGS_PROD = -Wall -Wextra -Werror -MMD -MP -g3

CFLAGS = $(CFLAGS_PROD)

export CFLAGS

# first:
# 	@echo "OBJECTS = $(OBJECTS)"

all: make_libft make_minilibx $(NAME)

$(NAME):  $(OBJECTS) $(LIBFT_PATH) $(MINILIBX_PATH)
	$(CC) $(CFLAGS) -lc -lm -lXext -lX11 $(INCLUDES) $^ -o $@
	@echo "$(NAME) built succesfully."

-include $(DEPS)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)/$(SOURCES_DIR)/$(PARSING_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(PRINTING_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(VEC3_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(VEC4_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(MLX_SETUP_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(POINT3_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(POINT4_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(MAT3_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(MAT4_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(MATRIX_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(RAY_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(INTERSECTION_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(SCN_OBJ_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(OBJECT_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(RENDER_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJ_DIR)/$(SOURCES_DIR)/$(RENDER_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(MLX_SETUP_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(PARSING_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(PRINTING_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(MATRIX_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(VEC3_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(VEC4_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(POINT3_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(POINT4_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(MAT3_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(MAT4_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(RAY_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(INTERSECTION_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(SCN_OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(OBJECT_DIR):
	mkdir -p $@

git_init:
	git submodule update --init

git_update:
	git submodule update --init --remote --recursive

#git: 
#	@git submodule update --init --remote --recursive

make_libft:
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)"
	
make_minilibx:
	@$(MAKE) -C $(MINILIBX_DIR);

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@rm -rf .cache/
	@echo "Cleaned !"

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) clean
	@rm -f $(NAME)
	@echo "Fcleaned !"

re:	
	$(MAKE) fclean 
	$(MAKE) all


.PHONY: all clean fclean re make_libft make_minilibx git
