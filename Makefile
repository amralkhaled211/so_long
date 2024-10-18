# Compiler and compiling flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Linker flags
MLXFLAGS = -lmlx -lXext -lX11

# Project name (executable)
NAME = so_long

# Source files and object files
SRC_DIR = ./source
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Libraries
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(LIBFT_DIR)/printf/libftprintf.a

# Include directory
INCLUDES = -I$(LIBFT_DIR)

# Rule for making the executable
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF_LIB) $(MLXFLAGS) $(INCLUDES)

# Rule for making the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Object files rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Clean object files
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean (objects and executable)
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Re-make everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
