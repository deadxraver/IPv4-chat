.PHONY: all clean run-tests

HOME=.
SRC=$(HOME)/src
TEST=$(HOME)/test
BUILD=$(HOME)/build

APP_NAME=messenger

CC=g++

all: build run-tests
	@echo test

build: $(SRC)
	test -e $(BUILD) || mkdir $(BUILD)
	$(CC) $(SRC)/main.cpp $(SRC)/**/*.cpp -o $(BUILD)/$(APP_NAME)
	# TODO

build-tests: $(TEST)
	# TODO

run-tests: build-tests
	# TODO

clean:
	rm -rf $(BUILD)
