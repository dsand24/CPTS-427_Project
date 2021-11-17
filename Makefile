CC=g++
all: encode_image decode_image test


encode_image: encodeimage.cpp
	$(CC) -o encodeimage encodeimage.cpp
	
decode_image: decodeimage.cpp
	$(CC) -o decodeimage decodeimage.cpp

test: test.cpp
	$(CC) -o test test.cpp