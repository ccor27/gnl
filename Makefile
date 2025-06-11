NAME_MAND = gnl_mand
NAME_BONUS = gnl_bonus

SRCS_MAND = get_next_line.c get_next_line_utils.c main.c
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c

CFLAGS = -Wall -Wextra -Werror

all: test_mandatory test_bonus

$(NAME_MAND): $(SRCS_MAND)
	@cc $(CFLAGS) $(SRCS_MAND) -o $(NAME_MAND)

$(NAME_BONUS): $(SRCS_BONUS)
	@cc $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

test_mandatory: $(NAME_MAND)
	@bash test_mandatory.sh

test_bonus: $(NAME_BONUS)
	@bash test_bonus.sh

clean:
	rm -f $(NAME_MAND) $(NAME_BONUS) out.txt ref.txt ref1.txt ref2.txt

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re
