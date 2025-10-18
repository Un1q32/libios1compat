HOST := armv6-apple-darwin8-

CC := $(HOST)cc
AR := $(HOST)ar

CFLAGS := -std=c99 -O2

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)

ifndef VERBOSE
V := @
endif

libios1compat.a: $(OBJS)
	@printf " \033[1;34mAR\033[0m libios1compat.a\n"
	$(V)$(AR) rcs $@ $(OBJS)

%.o: %.c
	@src=$@; src=$${src##*/}; printf " \033[1;32mCC\033[0m %s\n" "$$src"
	$(V)$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "Cleaning up...\n"
	$(V)rm -rf src/*.o libios1compat.a
