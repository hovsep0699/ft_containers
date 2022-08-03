BIN_DIR = bin

NAME = $(BIN_DIR)/queue

SRC_DIR = src

OBJ_DIR = $(BIN_DIR)/obj

MKDIR = mkdir -p

CXX = g++

RM = rm -rf

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

.DEFAULT_GOAL = all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

all: $(NAME) | $(BIN_DIR)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re