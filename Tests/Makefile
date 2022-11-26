STD					=	test_std

FT					=	test_ft

CXX					=	c++

FT_CONTAINERS_PATH	=	..

INCLUDES			=	-I$(FT_CONTAINERS_PATH) -I$(FT_CONTAINERS_PATH)/containers

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98 $(INCLUDES)

SRCS				=	$(wildcard *.cpp)

OBJS				=	$(patsubst %.cpp, %.o, $(SRCS))

RM					=	rm -rf

.DEFAULT_GOAL		=	all

%.o:				%.c
					@$(CXX) $(CXXFLAGS) -c $< -o $@


all:				$(STD) $(FT)
					@./$(STD) > test_std.out
					@./$(FT) > test_ft.out
					@(cmp --silent test_std.out test_ft.out && printf "\e[32mOK\n\e[0m") || printf "\e[31mKO\n\e[0m"
					@$(RM) test_std.out
					@$(RM) test_ft.out
					@$(MAKE) fclean

$(STD):				$(OBJS)
					@$(CXX) $(CXXFLAGS) -o $(STD) $(OBJS)

$(FT):				$(OBJS)
					@$(CXX) $(CXXFLAGS) -DFT_CONTAINER -o $(FT) $(OBJS)

clean:
					@$(RM) $(OBJS)

fclean:				clean
					@$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
