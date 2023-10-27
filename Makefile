NAME = cub3d
NAME_BONUS = cub3d_bonus
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L./minilibx-linux -g -lmlx -lXext -lX11 -lm -lz -lbsd
RM = rm -f

SRC	= ./mandatory/main.c\
	./mandatory/src/init/read_cub_file.c\
	./mandatory/src/init/init_data.c\
	./mandatory/src/init/open_window.c\
	./mandatory/src/init/init_textures_img.c\
	./mandatory/src/drawing/render_frames.c\
	./mandatory/src/drawing/render_frames2.c\
	./mandatory/src/drawing/ft_pixel_put.c\
	./mandatory/src/drawing/ft_pixel_get.c\
	./mandatory/src/drawing/background.c\
	./mandatory/src/utils/time.c\
	./mandatory/src/utils/is_only_digit_or_comma.c\
	./mandatory/src/utils/is_direction.c\
	./mandatory/src/utils/get_next_line.c\
	./mandatory/src/utils/free_arr.c\
	./mandatory/src/utils/ft_strchr.c\
	./mandatory/src/utils/ft_strncmp.c\
	./mandatory/src/utils/ft_strlen.c\
	./mandatory/src/utils/ft_itoa.c\
	./mandatory/src/utils/is_valid_colors.c\
	./mandatory/src/utils/ft_bzero.c\
	./mandatory/src/utils/ft_split.c\
	./mandatory/src/utils/ft_split_set.c\
	./mandatory/src/utils/ft_calloc.c\
	./mandatory/src/utils/ft_is_numeric.c\
	./mandatory/src/utils/ft_strdup.c\
	./mandatory/src/utils/ft_strjoin.c\
	./mandatory/src/utils/ft_strtrim.c\
	./mandatory/src/utils/get_array_size.c\
	./mandatory/src/utils/ft_isdigit.c\
	./mandatory/src/utils/ft_atoi.c\
	./mandatory/src/utils/ft_strnstr.c\
	./mandatory/src/utils/ft_substr.c\
	./mandatory/src/utils/ft_memcpy.c\
	./mandatory/src/utils/ft_put_nbr.c\
	./mandatory/src/utils/flood_fill.c\
	./mandatory/src/utils/ft_strcmp.c\
	./mandatory/src/utils/ft_strrchr.c\
	./mandatory/src/move/move_player.c\
	./mandatory/src/move/handle_keypress.c\
	./mandatory/src/move/handle_player_keys.c\
	./mandatory/src/close/close_window.c\
	./mandatory/src/parser/check_map_integrity.c\
	./mandatory/src/parser/get_map_size.c\
	./mandatory/src/parser/access_file.c\
	./mandatory/src/parser/get_ttl_nbr_lines.c\
	./mandatory/src/parser/get_elements.c\
	./mandatory/src/parser/check_input.c\
	./mandatory/src/parser/check_map_extension.c\
	./mandatory/src/parser/get_map_to_array.c\
	./mandatory/src/parser/get_elements_textures.c\
	./mandatory/src/parser/check_line.c

SRC_BONUS = ./bonus/src/parser/check_input_bonus.c\
	./bonus/src/parser/check_map_integrity_bonus.c\
	./bonus/src/parser/check_line_bonus.c\
	./bonus/src/parser/get_ttl_nbr_lines_bonus.c\
	./bonus/src/parser/get_map_size_bonus.c\
	./bonus/src/parser/get_map_to_array_bonus.c\
	./bonus/src/parser/get_elements_bonus.c\
	./bonus/src/parser/access_file_bonus.c\
	./bonus/src/parser/get_elements_textures_bonus.c\
	./bonus/src/parser/check_map_extension_bonus.c\
	./bonus/src/parser/set_start_bonus.c\
	./bonus/src/move/move_player_bonus.c\
	./bonus/src/move/handle_player_keys_bonus.c\
	./bonus/src/move/handle_keypress_bonus.c\
	./bonus/src/move/handle_mouse_bonus.c\
	./bonus/src/drawing/render_frames_bonus.c\
	./bonus/src/drawing/render_frames2_bonus.c\
	./bonus/src/drawing/background_bonus.c\
	./bonus/src/drawing/ft_pixel_put_bonus.c\
	./bonus/src/drawing/ft_pixel_get_bonus.c\
	./bonus/src/drawing/minimap_utils_bonus.c\
	./bonus/src/drawing/minimap_array_bonus.c\
	./bonus/src/drawing/minimap_bonus.c\
	./bonus/src/drawing/draw_utils_bonus.c\
	./bonus/src/drawing/draw_hands_bonus.c\
	./bonus/src/drawing/draw_head_hud_bonus.c\
	./bonus/src/drawing/sprites_bonus.c\
	./bonus/src/drawing/draw_doors_bonus.c\
	./bonus/src/drawing/draw_doors2_bonus.c\
	./bonus/src/init/open_window_bonus.c\
	./bonus/src/init/read_cub_file_bonus.c\
	./bonus/src/init/init_textures_bonus.c\
	./bonus/src/init/init_textures_extra_bonus.c\
	./bonus/src/init/init_extra_sprites_bonus.c\
	./bonus/src/init/init_data_bonus.c\
	./bonus/src/init/init_imgs_bonus.c\
	./bonus/src/close/close_window_bonus.c\
	./bonus/src/utils/ft_strjoin_bonus.c\
	./bonus/src/utils/get_next_line_bonus.c\
	./bonus/src/utils/ft_strnstr_bonus.c\
	./bonus/src/utils/get_array_size_bonus.c\
	./bonus/src/utils/ft_isdigit_bonus.c\
	./bonus/src/utils/ft_strlen_bonus.c\
	./bonus/src/utils/ft_itoa_bonus.c\
	./bonus/src/utils/flood_fill_bonus.c\
	./bonus/src/utils/ft_is_numeric_bonus.c\
	./bonus/src/utils/ft_atoi_bonus.c\
	./bonus/src/utils/is_valid_colors_bonus.c\
	./bonus/src/utils/ft_strdup_bonus.c\
	./bonus/src/utils/ft_strchr_bonus.c\
	./bonus/src/utils/ft_strncmp_bonus.c\
	./bonus/src/utils/ft_calloc_bonus.c\
	./bonus/src/utils/ft_bzero_bonus.c\
	./bonus/src/utils/ft_split_set_bonus.c\
	./bonus/src/utils/ft_strcmp_bonus.c\
	./bonus/src/utils/ft_memcpy_bonus.c\
	./bonus/src/utils/ft_split_bonus.c\
	./bonus/src/utils/ft_strtrim_bonus.c\
	./bonus/src/utils/ft_put_nbr_bonus.c\
	./bonus/src/utils/time_bonus.c\
	./bonus/src/utils/utils_list_bonus.c\
	./bonus/src/utils/ft_substr_bonus.c\
	./bonus/src/utils/is_direction_bonus.c\
	./bonus/src/utils/is_only_digit_or_comma_bonus.c\
	./bonus/src/utils/free_arr_bonus.c\
	./bonus/main_bonus.c\

OBJSDIR = objects

OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))

OBJSBONUSDIR = obj_bonus

OBJSBONUS = $(addprefix $(OBJSDIR)/, $(SRC_BONUS:.c=.o))

all: $(NAME)
	
$(NAME): $(OBJ)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJSBONUS)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(SRC_BONUS) $(CFLAGS) $(LDFLAGS) -o $(NAME_BONUS)

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJBONUSSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./minilibx-linux 
	$(RM) -rf $(OBJSDIR) $(OBJBONUSDIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all bonus

show:
	@printf "CC		: $(CC)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "NAME BONUS	: $(NAME_BONUS)\n"
	@printf "CLEAN		: $(RM)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LDFLAGS		: $(LDFLAGS)\n"

PHONY: show fclean bonus clean all