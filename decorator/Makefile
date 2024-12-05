# Compiler and flags
CXX = g++20
CXXFLAGS = -std=c++20 -Wall -Wextra -g

# Source files
SOURCES = Pizza.cc CrustAndSauce.cc Topping.cc Decorator.cc main.cc
HEADERS = Pizza.h CrustAndSauce.h Topping.h Decorator.h
OBJECTS = $(SOURCES:.cc=.o)

# Output binary
TARGET = pizza

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Compilation rule
%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)
