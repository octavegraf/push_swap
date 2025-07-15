CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
#F_SANITIZE	=	-fsanitize=address
DEBUG_FLAGS =	-g $(F_SANITIZE)
NAME		=	push_swap
HEADER		=	push_swap.h
PF_FOLDER	=	ft_printf/
PF_LIB		=	$(PF_FOLDER)libftprintf.a
LFT_FOLDER	=	$(PF_FOLDER)libft/
LFT_LIB		=	$(LFT_FOLDER)libft.a
LIBS		=	$(PF_LIB) $(LFT_LIB)

SRC			=	push_swap.c push_swap__parsing.c push_swap__radix.c \
				push_swap__rrotate.c push_swap__utils2.c \
				push_swap__normalize.c push_swap__push.c push_swap__rotate.c \
				push_swap__swap.c push_swap__utils.c
OBJ			=	$(SRC:.c=.o)

all			:	submodules $(NAME)

submodules	:
	@git submodule update --init --recursive
	@$(MAKE) -C $(PF_FOLDER)
	@$(MAKE) -C $(LFT_FOLDER)

$(NAME)		: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) -o $(NAME)

%.o			: %.c $(HEADER)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

clean		:
	@rm -f $(OBJ)
	@$(MAKE) -C $(PF_FOLDER) clean
	@$(MAKE) -C $(LFT_FOLDER) clean

fclean		: clean
	@rm -f $(NAME) $(LIBS)

re			: fclean all

.PHONY: all clean fclean re submodules
