.PHONY: build run
default: run

build:
	cd build && cmake .. && make

run: build
	./build/RogueGame