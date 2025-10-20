# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Project name
NAME = unnecessary_violence

# Source files
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# Check for memory leaks
leaks: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re leaks