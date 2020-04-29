CC=g++
BIN = bin
TARGET = bin/test
SRCDIR = src
INC = -I include
STD = -std=c++17

ALL: $(TARGET) 

$(TARGET):  src/main.cpp
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET)";
	@mkdir -p $(BIN)
	$(CC) $^ -o $(TARGET) $(INC) $(STD)

.PHONY: clean
clean:
	@echo "Cleaning..."
	@echo " $(RM)  $(BUILD) $(BIN)"
	$(RM) -r $(BUILD) $(BIN)
