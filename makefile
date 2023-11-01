# Define the C++ compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra

# Define the source directories
SRCDIR1 = lab1
SRCDIR2 = lab2

# Define the output directory
OBJDIR = out

# List the source files for lab1 and lab2
SRCS1 = $(wildcard $(SRCDIR1)/*.cpp)
SRCS2 = $(wildcard $(SRCDIR2)/*.cpp)

# Define the target executables
TARGET1 = $(OBJDIR)/lab1_executable
TARGET2 = $(OBJDIR)/lab2_executable

# Rule to build and run both lab1 and lab2 executables
all: lab2

# Rule to build and run the lab1 executable
lab1: $(SRCS1)
	$(CXX) $(CXXFLAGS) -o $(TARGET1) $^
	@echo "Running lab1 executable..."
	$(TARGET1)

# Rule to build and run the lab2 executable
lab2: $(SRCS2)
	$(CXX) $(CXXFLAGS) -o $(TARGET2) $^
	@echo "Running lab2 executable..."
	$(TARGET2)

# Clean rule to remove executables
clean:
	rm -f $(TARGET1) $(TARGET2)

# Specify the 'all' and 'clean' targets as phony
.PHONY: all lab1 lab2 clean
