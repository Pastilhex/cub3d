NAME = cub3d
NAME_BONUS = cub3d_bonus
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = cc
#CFLAGS = -Wall -Werror -Wextra -L./minilibx-linux -g -lmlx -lXext -lX11 -lm -lz -lbsd
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L./minilibx-linux -g -lmlx -lXext -lX11 -lm -lz -lbsd
RM = rm -f

SRC	= ./main.c\
	./src/init/read_cub_file.c\
	./src/init/init_data.c\
	./src/init/open_window.c\
	./src/init/init_textures_img.c\
	./src/drawing/render_frames.c\
	./src/drawing/render_frames2.c\
	./src/drawing/ft_pixel_put.c\
	./src/drawing/ft_pixel_get.c\
	./src/drawing/background.c\
	./src/utils/time.c\
	./src/utils/isOnlyDigitOrComma.c\
	./src/utils/is_direction.c\
	./src/utils/get_next_line.c\
	./src/utils/free_arr.c\
	./src/utils/ft_strchr.c\
	./src/utils/ft_strncmp.c\
	./src/utils/ft_strlen.c\
	./src/utils/ft_itoa.c\
	./src/utils/is_valid_colors.c\
	./src/utils/ft_bzero.c\
	./src/utils/ft_split.c\
	./src/utils/ft_split_set.c\
	./src/utils/ft_calloc.c\
	./src/utils/ft_is_numeric.c\
	./src/utils/ft_strdup.c\
	./src/utils/ft_strjoin.c\
	./src/utils/ft_strtrim.c\
	./src/utils/get_array_size.c\
	./src/utils/ft_isdigit.c\
	./src/utils/ft_atoi.c\
	./src/utils/ft_strnstr.c\
	./src/utils/ft_substr.c\
	./src/utils/ft_memcpy.c\
	./src/utils/ft_put_nbr.c\
	./src/utils/flood_fill.c\
	./src/utils/ft_strcmp.c\
	./src/move/move_player.c\
	./src/move/handle_keypress.c\
	./src/move/handle_player_keys.c\
	./src/close/close_window.c\
	./src/parser/check_map_integrity.c\
	./src/parser/get_map_size.c\
	./src/parser/access_file.c\
	./src/parser/get_ttl_nbr_lines.c\
	./src/parser/get_elements.c\
	./src/parser/check_input.c\
	./src/parser/check_map_extension.c\
	./src/parser/get_map_to_array.c\
	./src/parser/get_elements_textures.c\
	./src/parser/check_line.c

SRC_BONUS = ./bonus/src/parser/check_input.c\
	./bonus/src/parser/check_map_integrity.c\
	./bonus/src/parser/check_line.c\
	./bonus/src/parser/get_ttl_nbr_lines.c\
	./bonus/src/parser/get_map_size.c\
	./bonus/src/parser/get_map_to_array.c\
	./bonus/src/parser/get_elements.c\
	./bonus/src/parser/access_file.c\
	./bonus/src/parser/get_elements_textures.c\
	./bonus/src/parser/check_map_extension.c\
	./bonus/src/move/move_player.c\
	./bonus/src/move/handle_player_keys.c\
	./bonus/src/move/handle_keypress.c\
	./bonus/src/drawing/render_frames.c\
	./bonus/src/drawing/render_frames2.c\
	./bonus/src/drawing/background.c\
	./bonus/src/drawing/ft_pixel_put.c\
	./bonus/src/drawing/ft_pixel_get.c\
	./bonus/src/init/open_window.c\
	./bonus/src/init/read_cub_file.c\
	./bonus/src/init/init_textures_img.c\
	./bonus/src/init/init_data.c\
	./bonus/src/close/close_window.c\
	./bonus/src/utils/ft_strjoin.c\
	./bonus/src/utils/get_next_line.c\
	./bonus/src/utils/ft_strnstr.c\
	./bonus/src/utils/get_array_size.c\
	./bonus/src/utils/ft_isdigit.c\
	./bonus/src/utils/ft_strlen.c\
	./bonus/src/utils/ft_itoa.c\
	./bonus/src/utils/flood_fill.c\
	./bonus/src/utils/ft_is_numeric.c\
	./bonus/src/utils/ft_atoi.c\
	./bonus/src/utils/is_valid_colors.c\
	./bonus/src/utils/ft_strdup.c\
	./bonus/src/utils/ft_strchr.c\
	./bonus/src/utils/ft_strncmp.c\
	./bonus/src/utils/ft_calloc.c\
	./bonus/src/utils/ft_bzero.c\
	./bonus/src/utils/ft_split_set.c\
	./bonus/src/utils/ft_strcmp.c\
	./bonus/src/utils/ft_memcpy.c\
	./bonus/src/utils/ft_split.c\
	./bonus/src/utils/ft_strtrim.c\
	./bonus/src/utils/ft_put_nbr.c\
	./bonus/src/utils/time.c\
	./bonus/src/utils/ft_substr.c\
	./bonus/src/utils/is_direction.c\
	./bonus/src/utils/isOnlyDigitOrComma.c\
	./bonus/src/utils/free_arr.c\
	./bonus/main.c\


all: $(NAME)
	
$(NAME): $(OBJ)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(SRC_BONUS) $(CFLAGS) $(LDFLAGS) -o $(NAME_BONUS)

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
