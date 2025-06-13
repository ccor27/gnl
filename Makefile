NAME_MAND = gnl_mand
NAME_BONUS = gnl_bonus

SRCS_MAND = get_next_line.c get_next_line_utils.c main.c
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c

CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= 42

all: test_mandatory test_bonus

$(NAME_MAND): $(SRCS_MAND)
	@echo "🔨 Compiling MANDATORY with BUFFER_SIZE=$(BUFFER_SIZE)"
	@cc $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRCS_MAND) -o $(NAME_MAND)

$(NAME_BONUS): $(SRCS_BONUS)
	@echo "🔨 Compiling BONUS with BUFFER_SIZE=$(BUFFER_SIZE)"
	@cc $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRCS_BONUS) -o $(NAME_BONUS)

test_mandatory: $(NAME_MAND)
	@echo "🚀 Running mandatory tests..."
	@bash test_mandatory.sh

test_bonus:
	@echo "🚀 Running bonus tests..."
	@bash test_bonus.sh

clean:
	rm -f $(NAME_MAND) $(NAME_BONUS) out.txt ref.txt ref1.txt ref2.txt fd_invalid_output.txt gnl_mand_fd_invalid

fclean: clean

re: fclean all

.PHONY: all clean fclean re test_mandatory test_bonus
