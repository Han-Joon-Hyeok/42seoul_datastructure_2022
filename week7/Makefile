NAME = test

CC = gcc
#CFLAGS := -Wall -Wextra -Werror
CFLAGS := -fsanitize=address -g

#INCS = -I./heap/MINHEAP/ -I./array_graph/

SRCS = main.c \
		selectionSort.c \
		bubbleSort.c \
		quickSort.c \
		insertionSort.c \
		shellSort.c \
		swap.c \
		displayArray.c

OBJS := $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re