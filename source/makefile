# Compiler settings
CC = g++
CFLAGS = -Wall -std=c++11

# Project target
TARGET = my_program

# Source and Object files
SRCS = main.cpp errors.cpp push_back_stream.cpp tokenizer.cpp tokens.cpp
OBJS = $(SRCS:.cpp=.o)

# Include directory for headers
INCLUDES = -I.  # If headers are in the current directory

# Rule to build the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

# Rule to compile each .cpp file into a .o object file
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean
