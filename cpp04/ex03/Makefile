NAME = materia

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98# -fsanitize=address -g

SRCS =   main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp AMateria.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp IMateriaSource.hpp ICharacter.hpp	
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# //////////////////////////////////////////////////////////////////////////////

