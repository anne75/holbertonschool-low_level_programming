#
#Makefile
#
#remake bash script as a makefile

#output
TARGET = liball.a

#sources files
SRC = $(wildcard *.c)
#flages to pass compiler
CFLAGS = -Wall -pedantic -Werror -Wextra

#compiler
CC = gcc

#automatically generated list of object files
OBJS := $(SRC:%.c=%.o)

$(OBJS): $(SRC) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(TARGET): $(OBJS)
	ar rcs $@ $<

