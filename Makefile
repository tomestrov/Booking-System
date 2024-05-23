SRCS = src/booking.cpp src/flight.cpp src/lodging.cpp src/trip.cpp
EXE = a.out
SUBMITTY_CXXFLAGS = -I.

ifeq ($(DRIVER),)
	# Code.CS student settings (default)
	SRCS += src/main.cpp
else
	# Alternate driver supplied (likely for testing)
	SRCS += $(DRIVER)
endif

# Everything below that should not have to change ever.
CXX = g++
CXXFLAGS = -g -std=c++17 -Wall $(SUBMITTY_CXXFLAGS)
LDFLAGS = -g
LIBS =
OBJS = $(SRCS:.cpp=.o)
SHELL = /bin/bash
TARGET = all

all: run

$(EXE): $(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(LDFLAGS) $(LIBS)

.SUFFIXES: .cpp
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

compile: $(EXE)

run: compile
	./$(EXE) $(ARGS)

clean:
	-rm -f $(OBJS) $(EXE) solutions.txt
