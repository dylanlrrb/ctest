CC = gcc
FLAGS = -Wall
SRC = src/math_demo.c
DEPS = $(shell find deps -name "*.c")
HEADS = $(shell find . -name "*.h")
TESTS = $(shell find tests -name "*.c")
OBJS = $(SRC:.c=.c) $(DEPS:.c=.c)
WATCH_ITVL = 1

.PHONY: all clean watch watch-test test-ci

all: built

run: built
	@./$^

built: $(OBJS) $(HEADS)
	@echo "compiling..." & date +"Timestamp: %T"
	@${CC} ${FLAGS} $(OBJS) -o $@

clean:
	@echo "cleaning..."
	rm built test test-ci

watch:
	@echo "Watching for file changes..."
	@watch -i ${WATCH_ITVL} "make | grep -v 'Nothing to be done'"

test: $(TESTS) $(OBJS) $(HEADS)
	@clear
	@clear
	@echo "Running tests..."
	@${CC} -Wno-format $(TESTS) $(DEPS) -o $@
	@./$@
	@date +"Timestamp: %T"

test-watch:
	@clear
	@clear
	@echo "Watching for file changes..."
	@watch -i ${WATCH_ITVL} "make test | grep -v 'up to date'"

test-ci: $(TESTS) $(OBJS) $(HEADS)
	@clear
	@echo "Running tests..."
	@${CC} -Wno-format $(TESTS) $(DEPS) -o $@
	@./$@
	@date +"Timestamp: %T"
