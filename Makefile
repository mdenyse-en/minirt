NAME	= miniRT

SORCES	=	minirt_main.c \
			ft_keyboard.c \
			ft_utils.c

COLOR	=	ft_colors_trace.c \
			ft_colors_utils.c \
			ft_colors_vec.c

GNL		=	get_next_line_utils.c \
			get_next_line.c

PARCER	=	ft_am_light.c \
			ft_camera.c \
			ft_cylinder.c \
			ft_lights.c \
			ft_fill_structs.c \
			ft_sphere.c \
			ft_plane.c \
			ft_parcer_utils.c \
			ft_parcer.c

RAY_TR	=	ft_ray_trace.c \
			ft_cylinder_utils.c \
			ft_cylinder.c \
			ft_plane.c \
			ft_sphere.c

VECTORS	=	ft_vectors.c \
			ft_vectors_oper.c
			
DIRINCL	=	./includes/

DIR_SRCS	= ./srcs
DIR_COLOR	= $(DIR_SRCS)/color
DIR_GNL		= $(DIR_SRCS)/gnl
DIR_PARCER	= $(DIR_SRCS)/parcer
DIR_RAY_TR	= $(DIR_SRCS)/ray_trace
DIR_VECTORS	= $(DIR_SRCS)/vectors

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

HEAD	=	$(DIRINCL)minirt.h \
			$(DIRINCL)color.h \
			$(DIRINCL)structs.h \
			$(DIRINCL)get_next_line.h \
			$(DIRINCL)parcer.h \
			$(DIRINCL)ray_trace.h \
			$(DIRINCL)scene.h \
			$(DIRINCL)vectors.h

#bonus part

DIR_B	= ./bonus

DIRM	= ./minilibx

# B_NAME	= ../miniRT_bonus

# B_SORCES	=	minirt_main.c \
# 			ft_keyboard.c \
# 			ft_utils.c

# B_COLOR	=	ft_colors_trace.c \
# 			ft_colors_utils.c \
# 			ft_colors_vec.c

# B_GNL		=	get_next_line_utils.c \
# 			get_next_line.c

# B_PARCER	=	ft_am_light.c \
# 			ft_camera.c \
# 			ft_cylinder.c \
# 			ft_lights.c \
# 			ft_fill_structs.c \
# 			ft_sphere.c \
# 			ft_plane.c \
# 			ft_parcer_utils.c \
# 			ft_parcer.c

# B_RAY_TR	=	ft_ray_trace.c \
# 			ft_cylinder_utils.c \
# 			ft_cylinder.c \
# 			ft_plane.c \
# 			ft_sphere.c

# B_VECTORS	=	ft_vectors.c \
# 			ft_vectors_oper.c
			
# B_DIRINCL	=	$(DIR_B)/includes/

# B_DIR_SRCS		= $(DIR_B)/srcs
# B_DIR_COLOR		= $(B_DIR_SRCS)/color
# B_DIR_GNL		= $(B_DIR_SRCS)/gnl
# B_DIR_PARCER	= $(B_DIR_SRCS)/parcer
# B_DIR_RAY_TR	= $(B_DIR_SRCS)/ray_trace
# B_DIR_VECTORS	= $(B_DIR_SRCS)/vectors

# B_SRC_SRCS		= $(addprefix $(B_DIR_SRCS)/,$(B_SORCES))
# B_SRC_COLOR		= $(addprefix $(B_DIR_COLOR)/,$(B_COLOR))
# B_SRC_GNL		= $(addprefix $(B_DIR_GNL)/,$(B_GNL))
# B_SRC_PARCER	= $(addprefix $(B_DIR_PARCER)/,$(B_PARCER))
# B_SRC_RAY_TR	= $(addprefix $(B_DIR_RAY_TR)/,$(B_RAY_TR))
# B_SRC_VECTORS	= $(addprefix $(B_DIR_VECTORS)/,$(B_VECTORS))

# B_OBJ_SRCS		= $(B_SRC_SRCS:.c=.o)
# B_OBJ_COLOR		= $(B_SRC_COLOR:.c=.o)
# B_OBJ_GNL		= $(B_SRC_GNL:.c=.o)
# B_OBJ_PARCER	= $(B_SRC_PARCER:.c=.o)
# B_OBJ_RAY_TR	= $(B_SRC_RAY_TR:.c=.o)
# B_OBJ_VECTORS	= $(B_SRC_VECTORS:.c=.o)

# B_HEAD	=	$(B_DIRINCL)minirt.h \
# 			$(B_DIRINCL)color.h \
# 			$(B_DIRINCL)structs.h \
# 			$(B_DIRINCL)get_next_line.h \
# 			$(B_DIRINCL)parcer.h \
# 			$(B_DIRINCL)ray_trace.h \
# 			$(B_DIRINCL)scene.h \
# 			$(B_DIRINCL)vectors.h

#end of bonus part

DIRL	=	./libft

DIRM	=	./mlx

LIB		= $(DIRL)/libft.a

MLX		= $(DIRM)/libmlx.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I$(DIRINCL)

RM		= rm -f

# %.o:	%.c
# 	$(CC) $(CFLAG) -I$(DIRINCL) -I$(B_DIRINCL) -c $< -o $@


.PHONY:	all, clean, fclean, re, bonus

all: $(NAME)

$(OBJ_SRCS) $(OBJ_COLOR) $(OBJ_GNL) $(OBJ_PARCER) $(OBJ_RAY_TR) $(OBJ_VECTORS) : $(HEAD)

$(NAME):	$(OBJ_SRCS) $(OBJ_COLOR) $(OBJ_GNL) $(OBJ_PARCER) $(OBJ_RAY_TR) $(OBJ_VECTORS) $(HEAD)
	$(MAKE) -C $(DIRL)
	$(MAKE) -C $(DIRM)
	$(CC) $(CFLAGS) $(OBJ_SRCS) $(OBJ_COLOR) $(OBJ_GNL) $(OBJ_PARCER) $(OBJ_RAY_TR) $(OBJ_VECTORS) $(LIB) -L. -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo '\033[4;1m' $(NAME) '\033[0;1m' is compiled! '\033[0m''\xF0\x9F\x91\x80'

clean:
	$(MAKE) clean -C $(DIRL)
	$(MAKE) clean -C $(DIRM)
	$(MAKE) clean -C $(DIR_B)
	$(RM) $(OBJ_SRCS) $(OBJ_COLOR) $(OBJ_GNL) $(OBJ_PARCER) $(OBJ_RAY_TR) $(OBJ_VECTORS) \
		$(B_OBJ_SRCS) $(B_OBJ_COLOR) $(B_OBJ_GNL) $(B_OBJ_PARCER) $(B_OBJ_RAY_TR) $(B_OBJ_VECTORS)
	@echo '\033[1m' Objects files cleaned! '\033[0m'

fclean: clean
	@$(MAKE) fclean -C $(DIRL)
	@$(MAKE) fclean -C $(DIR_B)
	$(RM) $(NAME) $(BNAME)
	@echo '\033[1m' All cleaned! '\033[0m'

re: fclean all

#$(B_OBJ_SRCS) $(B_OBJ_COLOR) $(B_OBJ_GNL) $(B_OBJ_PARCER) $(B_OBJ_RAY_TR) $(B_OBJ_VECTORS) : $(B_HEAD)

# $(B_NAME): $(B_OBJ_SRCS) $(B_OBJ_COLOR) $(B_OBJ_GNL) $(B_OBJ_PARCER) $(B_OBJ_RAY_TR) $(B_OBJ_VECTORS) $(B_HEAD)
# 	$(MAKE) -C $(DIRL)
# 	$(CC) $(CFLAGS) $(B_OBJ_SRCS) $(B_OBJ_COLOR) $(B_OBJ_GNL) $(B_OBJ_PARCER) $(B_OBJ_RAY_TR) $(B_OBJ_VECTORS) $(LIB) -L. -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(B_NAME)
# 	@echo '\033[1m' bonus $(B_NAME) is compiled! '\033[0m'

bonus:
	@$(MAKE) -C $(DIR_B)
