CXX := -g++
CXXFLAGS := -std=c++14 -Wall -Werror -Wextra -g
LDFLAGS := -L/usr/lib -lstdc++ -lm -lX11 -L/opt/X11/lib
BUILD := ./build
OBJ_DIR := $(BUILD)/objects
APP_DIR := .
TARGET := chess
INCLUDE := -Iinclude/ -I.
SRC := $(wildcard src/*.cc)

OBJECTS := $(SRC:%.cc=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(OBJECTS:.o=.d)


$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean zip

all:
	make $(APP_DIR)/$(TARGET)

build:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rvf $(BUILD)
	@rm -rvf $(APP_DIR)/$(TARGET)
	@rm -vf  $(TARGET).zip

zip: clean
	zip -r $(TARGET).zip Makefile src/ include/
