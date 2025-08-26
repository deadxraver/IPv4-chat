.PHONY: all clean run-tests

HOME=.
SRC=$(HOME)/src
TEST=$(HOME)/test
BUILD=$(HOME)/build

APP_NAME=messenger
TEST_NAME=test

CC=g++

all: build run-tests
	@echo -e '\nSuccess! Executable can be found at' $(BUILD)/$(APP_NAME)

build: $(SRC)/**
	test -e $(BUILD) || mkdir $(BUILD)
	$(CC) $(SRC)/main.cpp $(SRC)/**/*.cpp -o $(BUILD)/$(APP_NAME)

build-tests: $(TEST)
	$(CC) $(TEST)/main.cpp $(SRC)/**/*.cpp -o $(BUILD)/$(TEST_NAME)

run-tests: build-tests
	echo
	time $(BUILD)/$(TEST_NAME)

clean:
	rm -rf $(BUILD)
