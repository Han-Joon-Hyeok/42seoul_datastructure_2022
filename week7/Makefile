NAME = test

CC = gcc
#CFLAGS := -Wall -Wextra -Werror
CFLAGS := -fsanitize=address -g

INCS = -I./minHeap/ -I./linkedQueue/

DIR_HEAP = ./minHeap/
DIR_LINKEDQUEUE = ./linkedQueue/

SRCS = main.c \
		selectionSort.c \
		bubbleSort.c \
		quickSort.c \
		insertionSort.c \
		shellSort.c \
		mergeSort.c \
		heapSort.c \
		$(DIR_HEAP)createminHeap.c \
		$(DIR_HEAP)deleteminHeap.c \
		$(DIR_HEAP)insertminHeap.c \
		$(DIR_HEAP)isHeapEmpty.c \
		$(DIR_HEAP)isHeapFull.c \
		radixSort.c \
		$(DIR_LINKEDQUEUE)createLinkedQueue.c \
		$(DIR_LINKEDQUEUE)deleteLinkedQueue.c \
		$(DIR_LINKEDQUEUE)dequeueLQ.c \
		$(DIR_LINKEDQUEUE)enqueueLQ.c \
		$(DIR_LINKEDQUEUE)isLinkedQueueEmpty.c \
		$(DIR_LINKEDQUEUE)peekLQ.c \
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