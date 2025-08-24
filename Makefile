.PHONY: all clean run-tests

HOME=.
SRC=$(HOME)/src
TEST=$(HOME)/test
BUILD=$(HOME)/build

CC=gcc

all: build run-tests
	@echo test

build: $(SRC)
	# TODO

build-tests: $(TEST)
	# TODO

run-tests: build-tests
	# TODO

clean:
	rm -rf $(BUILD)
