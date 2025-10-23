# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 13:51:50 by rorollin          #+#    #+#              #
#    Updated: 2025/10/21 16:11:43 by jweber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

#SOURCES######################

SOURCES_DIR = src

PARSING_DIR = parsing
PARSING_FILES = parsing.c \

PRINTING_DIR = printing
PRINTING_FILES = print_error.c \

SOURCES_NAME = $(addprefix $(PARSING_DIR)/,$(PARSING_FILES)) \
			   $(addprefix $(PRINTING_DIR)/,$(PRINTING_FILES)) \


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

%.o:
	echo in rulle 

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)/$(SOURCES_DIR)/$(PARSING_DIR) $(OBJ_DIR)/$(SOURCES_DIR)/$(PRINTING_DIR) 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(PARSING_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOURCES_DIR)/$(PRINTING_DIR):
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
