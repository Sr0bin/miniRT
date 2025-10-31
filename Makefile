# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 16:46:22 by jweber            #+#    #+#              #
#    Updated: 2025/10/29 16:46:24 by jweber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

#SOURCES######################

SOURCES_DIR = src

MATRIX_DIR = matrix
MATRIX_FILES = matrix_core.c matrix_elem.c matrix_operations.c

PARSING_DIR = parsing
PARSING_FILES = parsing.c \
				get_file_content.c \
				fill_obj_content.c \
				fill_obj_ambient.c \
				fill_obj_camera.c \
				fill_obj_light.c \
				fill_obj_sphere.c \
				fill_obj_plane.c \
				fill_obj_cylinder.c \
				fill_coordinates.c \
				fill_colors.c \
				fill_direction.c \
				free_obj_vector.c \
				check_args.c \
				init_msg_atof_failed.c \
				init_msg_atoi_failed.c \

PRINTING_DIR = printing
PRINTING_FILES = print_error.c \
				 print_types.c \
				 print_objects.c \

VECTOR_DIR = vector
VECTOR_FILES = vector_core.c vector_operations.c

POINT_DIR = point
POINT_FILES = point_core.c

RAY_DIR = ray
RAY_FILES = ray_core.c
SOURCES_NAME = $(addprefix $(PARSING_DIR)/,$(PARSING_FILES)) \
			   $(addprefix $(PRINTING_DIR)/,$(PRINTING_FILES)) \
			   $(addprefix $(MATRIX_DIR)/,$(MATRIX_FILES)) \
			   $(addprefix $(VECTOR_DIR)/,$(VECTOR_FILES)) \
			   $(addprefix $(POINT_DIR)/,$(POINT_FILES)) \
			   $(addprefix $(RAY_DIR)/,$(RAY_FILES)) \


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

HEADERS_DIR = includes/ src/libft/includes/ minilibx/

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

CFLAGS_PROD = -Wall -Wextra -Werror -MMD -MP -ggdb3 -O3

CFLAGS = $(CFLAGS_DEBUG)

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
	$(OBJ_DIR)/$(SOURCES_DIR)/$(VECTOR_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(POINT_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(MATRIX_DIR)\
	$(OBJ_DIR)/$(SOURCES_DIR)/$(RAY_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(PARSING_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(PRINTING_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(MATRIX_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(VECTOR_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(POINT_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(RAY_DIR):
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
