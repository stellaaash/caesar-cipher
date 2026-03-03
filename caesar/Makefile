NAME		=	caesar
CXX			=	clang
CXXFLAGS	=	-Wall \
				-Wextra \
				-Wpedantic \
				-Wconversion \
				-Wsign-conversion \
				-Werror \
				-g

RM			=	rm
RMFLAGS		=	-f

SRCDIR		=	src
CFILES		=	$(SRCDIR)/main.c

OBJS		=	$(CFILES:.c=.o)

INCLDIR		=	include
IFILES		=

VALGRIND	=	valgrind
VALFLAGS	=	--leak-check=full --show-leak-kinds=all
LOG			=	valgrind.log


all:			$(NAME)

%.o:			%.c
				@printf "\rCompiling $<..."
				@$(CXX) $(CXXFLAGS) -I$(INCLDIR) -c $< -o $@

$(NAME):		$(OBJS)
				@printf "\rCompiling $(NAME)..."
				@$(CXX) $(CXXFLAGS) -I$(INCLDIR) $(OBJS) -o $(NAME)
				@printf "\r\n\033[32m$(NAME) compiled.\033[0m\n"

clean:
				@printf "\rCleaning object files"
				@$(RM) $(RMFLAGS) $(OBJS)
				@$(RM) $(RMFLAGS) $(OBJS:.o=.d)
				@printf "\rObject files cleaned.\n"

fclean:			clean
				@printf "\rRemoving $(NAME)..."
				@$(RM) $(RMFLAGS) $(NAME)
				@$(RM) $(RMFLAGS) $(LOG)
				@printf "\r$(NAME) Removed.\n"

re:				fclean all

test:			re
				@printf "\n==============================================\n"
				$(VALGRIND) $(VALFLAGS) ./$(NAME) | tee $(LOG)

.PHONY:			all clean fclean re debug test
