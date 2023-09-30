NAME = cub3d

NAME_BONUS = cub3d_bonus

CC = cc

SRC	= ./main.c\
	./src/time.c\
	./src/drawn_ground.c\
	./src/drawn_sky.c\
	./src/ft_pix_put.c\
	./src/open_window.c\
	./src/utils/ft_isdigit.c\
	./src/utils/ft_is_numeric.c\
	./src/utils/ft_atoi.c\
	./src/utils/ft_calloc.c\
	./src/utils/ft_strlen.c\
	./src/utils/ft_bzero.c\
	./src/utils/get_next_line.c\
	./src/utils/ft_strnstr.c\
	./src/close_window.c\
	./src/parser/access_file.c\
	./src/parser/get_ttl_nbr_lines.c\
	./src/parser/get_map_to_array.c\
	./src/parser/find_texture.c\
	./src/parser/get_elements.c\
	./src/parser/get_back_line.c\
	./src/parser/get_texture.c\
	./src/parser/check_map_extension.c\
	./src/parser/get_map_size.c\
	./src/import_map_file.c\
	./src/handle_keypress.c\



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
