CCFLAGS = `pkg-config --cflags --libs protobuf`
CC = g++

all:	reverseme.cc
	$(CC) $(CCFLAGS) reverseme.cc reverseme.pb.cc -o reverseme
