# Define the C++ compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall

# Define the source directories
SRCDIR1 = lab1
SRCDIR2 = lab2
SRCDIR3 = lab3

# Define the output directory
OBJDIR = ./out

# List the source files for lab1 and lab2
SRCS1 = $(wildcard $(SRCDIR1)/*.cpp)
SRCS2 = $(wildcard $(SRCDIR2)/*.cpp)
SRCS3 = $(wildcard $(SRCDIR3)/*.cpp)

# Define the target executables
TARGET1 = $(OBJDIR)/lab1
TARGET2 = $(OBJDIR)/lab2
TARGET3 = $(OBJDIR)/lab3

# Rule to build current working lab
all: lab3

# Rule to build and run the lab1 executable
lab1:
	$(CXX) $(CXXFLAGS) $(SRCS1) -o $(TARGET1)
	@echo "Running lab1 executable..."
	$(TARGET1)

# Rule to build and run the lab2 executable
lab2:
	$(CXX) $(CXXFLAGS) $(SRCS2) -o $(TARGET2)
	@echo "Running lab2 executable..."
	$(TARGET2)

# Rule to build and run the lab3 executable
lab3:
	$(CXX) $(CXXFLAGS) $(SRCS3) -o $(TARGET3)
	@echo "Running lab3 executable..."
	$(TARGET3)

# Clean rule to remove executables
clean:
	rm -f $(TARGET1) $(TARGET2)

# Specify the 'all' and 'clean' targets as phony
.PHONY: all lab1 lab2 lab3 clean
