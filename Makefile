CC=g++
all: encode_image decode_image 


encode_image: encodeimage.cpp
	$(CC) -o encodeimage encodeimage.cpp
	
decode_image: decodeimage.cpp
	$(CC) -o decodeimage decodeimage.cpp