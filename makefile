CC=g++
BIN = bin
TARGET = bin/test
SRCDIR = src
INC = -I include

ALL: $(TARGET) 

$(TARGET): src/main.cpp include/btree.hpp include/traits.hpp
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET)";
	@mkdir -p $(BIN)
	$(CC) $^ -o $(TARGET) $(INC)

.PHONY: clean
clean:
	@echo "Cleaning..."
	@echo " $(RM)  $(BUILD) $(BIN)"
	$(RM) -r $(BUILD) $(BIN)
