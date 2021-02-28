CC = g++
PROJ_NAME = yomenai
NIM=13519124

SRC = src/
OUT = out/

HEADERS = headers/

_FILES = main Graph parser TopoSort Num2Roman
OBJS = $(patsubst %,$(OUT)/$(NIM)-%.o, $(_FILES))

OUT_NAME = $(PROJ_NAME)
OUT_FILE = $(patsubst %, $(OUT)/%, $(OUT_NAME))

TEST_FILE ?= test/test

$(OUT):
	mkdir -p $@

$(OUT)/%.o: $(SRC)/%.cpp $(OUT)
	$(CC) -c -I$(HEADERS) -o $@ $<

build: $(OBJS)
	$(CC) -o $(OUT_FILE) $^

run: build
	$(OUT_FILE) $(TEST_FILE)

clean:
	rm -rf $(OUT)

.phony: build run clean $(OUT)