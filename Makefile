CC := cc
CFLAGS := -Wall -Wextra -Werror


# Directories
SRC_DIR := srcs
INC_DIR := includes
LIB_DIR := lib
LIBFT_DIR := $(LIB_DIR)/libft
MANDATORY_DIR := $(SRC_DIR)/mandatory
BONUS_DIR := $(SRC_DIR)/bonus
COMMON_DIR := $(SRC_DIR)/common

# Executables
NAME := push_swap
CHECKER := checker
LIBFT := $(LIBFT_DIR)/libft.a

# Header files
INCLUDES := -I $(INC_DIR) -I $(LIBFT_DIR)

# Object files
MANDATORY_OBJ := $(MANDATORY_DIR)/main.o \
				 $(MANDATORY_DIR)/push_swap.o \
				 $(MANDATORY_DIR)/sort_three.o \
				 $(MANDATORY_DIR)/turk.o \
				 $(MANDATORY_DIR)/turk_utils.o \
				 $(MANDATORY_DIR)/turk_utils_2.o \
				 $(MANDATORY_DIR)/turk_utils_3.o
BONUS_OBJ := $(BONUS_DIR)/main_bonus.o \
			 $(BONUS_DIR)/checker_bonus.o \
			 $(BONUS_DIR)/checker_utils_bonus.o \
			 $(BONUS_DIR)/get_next_line_bonus.o \
			 $(BONUS_DIR)/get_next_line_utils_bonus.o
COMMON_OBJ := $(COMMON_DIR)/hash.o \
			  $(COMMON_DIR)/instructions.o \
			  $(COMMON_DIR)/instructions_2.o \
			  $(COMMON_DIR)/parsing.o \
			  $(COMMON_DIR)/stack.o \
			  $(COMMON_DIR)/stack_utils.o \
			  $(COMMON_DIR)/utils.o \
			  $(COMMON_DIR)/utils_2.o

# Rules

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(MANDATORY_OBJ) $(COMMON_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(CHECKER): $(BONUS_OBJ) $(COMMON_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

%.o: %.c $(LIBFT)
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(MANDATORY_OBJ) $(BONUS_OBJ) $(COMMON_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME) $(CHECKER)

re: fclean all
