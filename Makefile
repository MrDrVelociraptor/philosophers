SRC = src/*.c



INC = inc

HEADERS = -I$(INC)
FLAGS = -Wall -Werror -Wextra -pthread $(HEADERS)

all:
	@gcc $(FLAGS) $(SRC) -o philo 
	@echo Good to go
	

clean:
	@rm -f philo
	@echo nothing here anymore, well, except .c

fclean: clean

re: clean all
