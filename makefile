CC = g++
PROJ_NAME = yomenai
NIM=13519124

SRC = src/
OUT = out/
BIN = bin/

HEADERS = headers/

_FILES = main Graph parser TopoSort Num2Roman
OBJS = $(patsubst %,$(OUT)/$(NIM)-%.o, $(_FILES))

OUT_NAME = $(PROJ_NAME)
OUT_FILE = $(patsubst %, $(BIN)/%, $(OUT_NAME))

TEST_FILE ?= test/test1

$(OUT):
	mkdir -p $@

$(BIN):
	mkdir -p $@

$(OUT)/%.o: $(SRC)/%.cpp $(OUT)
	$(CC) -c -I$(HEADERS) -o $@ $<

$(OUT_FILE): $(OBJS)
	$(CC) -o $(OUT_FILE) $^

build: $(BIN) $(OUT_FILE)

run: build
	$(OUT_FILE) $(TEST_FILE)

clean:
	rm -rf $(OUT)

.phony: build run clean