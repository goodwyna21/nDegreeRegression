BUILD := ./Build
SOURCE := ./Source
TARGET := main.o
MAIN := main.cpp
ARMAFLAGS := -DARMA_DONT_USE_WRAPPER -lopenblas -llapack

$(BUILD)/$(TARGET): $(SOURCE)/$(MAIN)
	g++ $(SOURCE)/$(MAIN) -o $@ $(ARMAFLAGS)
