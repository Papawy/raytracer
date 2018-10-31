CC = g++

# Exe name
EXE = rt

# Directories
INCDIR = include
export SRCDIR = src
BUILDDIR = build

# Flags
CPPFLAGS = -I$(INCDIR)
CFLAGS = -Wall -Wextra -pedantic -std=c++17
LDFLAGS =

# Libraries
LDLIBS = -lm

# Sources
SRC = $(shell find $(SRCDIR) -name \*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRC))

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(EXE)

$(OBJS):
	@mkdir -p $(BUILDDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(SRC) $(LDLIBS) -c -o $(OBJS)

clean:
	rm -rf $(OBJS) $(EXE)
	rm -rf $(BUILDDIR)
