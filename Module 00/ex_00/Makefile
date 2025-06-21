# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoudi-b <mdoudi-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/21 16:27:09 by mdoudi-b          #+#    #+#              #
#    Updated: 2025/06/21 16:41:20 by mdoudi-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables básicas
NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Archivos
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

# Regla principal
all: $(NAME)

# Crear .O

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear el ejecutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Limpiar archivos objeto
clean:
	rm -f $(OBJS)

# Limpiar todo
fclean: clean
	rm -f $(NAME)

# Recompilar
re: fclean all

# Indicar que son reglas, no archivos
.PHONY: all clean fclean re
