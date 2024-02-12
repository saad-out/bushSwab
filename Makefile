CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBFT := libft.a
LIBFT_FOLDER := libft
LIBFT_HEADER := libft.h
NAME := push_swap
OBJS := main.o push_swap.o hash.o stack.o parsing.o utils.o instructions.o turk.o utils_2.o
BONUS_OBJS := main_bonus.o checker_bonus.o instructions.o hash.o stack.o parsing.o utils.o get_next_line.o get_next_line_utils.o utils_2.o
BONUS_NAME := checker

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT): $(LIBFT_HEADER)
	make -C $(LIBFT_FOLDER) bonus
	cp $(LIBFT_FOLDER)/$(LIBFT) .

$(LIBFT_HEADER):
	cp $(LIBFT_FOLDER)/$(LIBFT_HEADER) .

%.o: %.c $(LIBFT)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	make -C $(LIBFT_FOLDER) clean
	rm -rf $(LIBFT) $(LIBFT_HEADER)
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_FOLDER) fclean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
