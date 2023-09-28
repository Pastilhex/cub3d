NAME = cub3d

NAME_BONUS = cub3d_bonus

CC = cc

SRC	= ./src/time.c\
	./src/drawn_ground.c\
	./src/drawn_sky.c\
	./src/ft_pix_put.c\
	./src/open_window.c\
	./src/handle_keypress.c\
	./src/close_window.c\
	./main.c\



SRC_BONUS = $(wildcard bonus/*.c)

CFLAGS = -L ./minilibx-linux -Wall -Werror -Wextra -g -lmlx -lXext -lX11 -lm -lbsd

RM = rm -f

all:
	$(MAKE) -C ./minilibx-linux
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

bonus:
	$(CC) $(SRC_BONUS) $(CFLAGS) -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C ./minilibx-linux 
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME_BONUS)

re: fclean all

show:
	@printf "CC		: $(CC)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "NAME BONUS	: $(NAME_BONUS)\n"
	@printf "CLEAN		: $(RM)\n"
	@printf "FLAGS		: $(CFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "SRC BONUS	: $(SRC_BONUS)\n"

PHONY: show fclean bonus clean all
