BUILD = ./Build
SOURCE = ./Source
TARGET = main.o
MAIN = main.cpp
HEADERS = regression.cpp
ARMAFLAGS = -DARMA_DONT_USE_WRAPPER -lopenblas -llapack

$(BUILD)/$(TARGET): $(SOURCE)/$(MAIN) $(SOURCE)/$(HEADERS)
	g++ $(SOURCE)/$(MAIN) -o $@ $(ARMAFLAGS)
