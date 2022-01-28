NAME	= ../miniRT_bonus

SORCES	=	minirt_main_bonus.c \
			ft_keyboard_bonus.c \
			ft_utils_bonus.c

COLOR	=	ft_colors_trace_bonus.c \
			ft_colors_trace_utils_bonus.c \
			ft_colors_utils_bonus.c \
			ft_colors_utils_vec_bonus.c \
			ft_colors_vec_bonus.c

GNL		=	get_next_line_utils_bonus.c \
			get_next_line_bonus.c

PARCER	=	ft_am_light_bonus.c \
			ft_camera_bonus.c \
			ft_cone_bonus.c \
			ft_cylinder_bonus.c \
			ft_lights_bonus.c \
			ft_fill_structs_bonus.c \
			ft_sphere_bonus.c \
			ft_plane_bonus.c \
			ft_parcer_utils_bonus.c \
			ft_parcer_bonus.c

RAY_TR	=	ft_ray_trace_bonus.c \
			ft_cone_bonus.c \
			ft_cone_utils_bonus.c \
			ft_cylinder_utils_bonus.c \
			ft_cylinder_bonus.c \
			ft_plane_bonus.c \
			ft_sphere_bonus.c \
			ft_sphere_utils_bonus.c

VECTORS	=	ft_vectors_bonus.c \
			ft_vectors_oper_bonus.c \
			ft_vectors_rotate_bonus.c
			
DIRINCL	=	./includes_bonus/

DIR_SRCS	= ./srcs_bonus
DIR_COLOR	= $(DIR_SRCS)/color_bonus
DIR_GNL		= $(DIR_SRCS)/gnl_bonus
DIR_PARCER	= $(DIR_SRCS)/parcer_bonus
DIR_RAY_TR	= $(DIR_SRCS)/ray_trace_bonus
DIR_VECTORS	= $(DIR_SRCS)/vectors_bonus

SRC_SRCS	= $(addprefix $(DIR_SRCS)/,$(SORCES))
SRC_COLOR	= $(addprefix $(DIR_COLOR)/,$(COLOR))
SRC_GNL		= $(addprefix $(DIR_GNL)/,$(GNL))
SRC_PARCER	= $(addprefix $(DIR_PARCER)/,$(PARCER))
SRC_RAY_TR	= $(addprefix $(DIR_RAY_TR)/,$(RAY_TR))
SRC_VECTORS	= $(addprefix $(DIR_VECTORS)/,$(VECTORS))

OBJ_SRCS	= $(SRC_SRCS:.c=.o)
OBJ_COLOR	= $(SRC_COLOR:.c=.o)
OBJ_GNL		= $(SRC_GNL:.c=.o)
OBJ_PARCER	= $(SRC_PARCER:.c=.o)
OBJ_RAY_TR	= $(SRC_RAY_TR:.c=.o)
OBJ_VECTORS	= $(SRC_VECTORS:.c=.o)

HEAD	=	$(DIRINCL)minirt_bonus.h \
			$(DIRINCL)color_bonus.h \
			$(DIRINCL)structs_bonus.h \
			$(DIRINCL)get_next_line_bonus.h \
			$(DIRINCL)parcer_bonus.h \
			$(DIRINCL)ray_trace_bonus.h \
			$(DIRINCL)scene_bonus.h \
			$(DIRINCL)vectors_bonus.h

DIRL	=	../libft

DIR_M		= ../mlx

LIB		= $(DIRL)/libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I$(DIRINCL)

RM		= rm -f

all: $(NAME)

$(OBJ_SRCS) $(OBJ_COLOR) $(OBJ_GNL) $(OBJ_PARCER) $(OBJ_RAY_TR) $(OBJ_VECTORS) : $(HEAD)

$(NAME):	$(OBJ_SRCS) $(OBJ_COLOR) $(OBJ_GNL) $(OBJ_PARCER) $(OBJ_RAY_TR) $(OBJ_VECTORS) $(HEAD)
	$(MAKE) -C $(DIRL)
	$(MAKE) -C $(DIR_M)
	$(CC) $(CFLAGS) $(OBJ_SRCS) $(OBJ_COLOR) $(OBJ_GNL) $(OBJ_PARCER) $(OBJ_RAY_TR) $(OBJ_VECTORS) $(LIB) -L. -L../mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo '\033[4;1m' $(NAME) '\033[0;1m' is compiled! '\033[0m''\xF0\x9F\x91\x80'

clean:
	$(MAKE) clean -C $(DIRL)
	$(MAKE) clean -C $(DIR_M)
	$(RM) $(OBJ_SRCS) $(OBJ_COLOR) $(OBJ_GNL) $(OBJ_PARCER) $(OBJ_RAY_TR) $(OBJ_VECTORS) \
	@echo '\033[1m' Objects files cleaned! '\033[0m'

fclean: clean
	$(MAKE) fclean -C $(DIRL)
	$(RM) $(NAME)
	@echo '\033[1m' All cleaned! '\033[0m'

re: fclean all
