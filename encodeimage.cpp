#include <iostream>
#include <fstream>

// #include <highgui.h>

using namespace std;

// create function to get value of current bit

void printBinary(char ch) {
	for (int i = 0; i < 8; i++) {
		printf("%d", !!((ch << i) & 0x80));
	}
	
	printf("\n");
}

bool getBitValue(char ch, int bit) {
	cout << "ch1: ";
	printBinary(ch);
	ch = ch >> bit;
	cout << "ch2: ";
	printBinary(ch);
	cout << endl;
	
	return true;
}


int main(int argc, char** argv) {
	string messagefile = "hidden_message.txt";
	
	ifstream image;
	image.open("gumpypic.png");
	if (image.is_open() == false) {
		cout << "Error opening image" << endl;
	}
	
	
	
	ifstream message (messagefile, ifstream::binary);
	// message.open(messagefile);
	if (message.is_open() == false) {
		cout << "Error opening message" << endl;
	}
	
	char c = 'f';
	
	////////////////////////////////////////////
	
	// std::ifstream ifs ("test.txt", std::ifstream::in);

	char ch = image.get();
	// char ch = message.get();
	int gcount = message.gcount();
	int count = 0;
	cout << "gcount = " << gcount << endl;

	while (count < gcount) {
		cout << ch;
		ch = image.get();
		count++;
	}

	image.close();

	
	/*
	getBitValue(c, 0);
	getBitValue(c, 1);
	getBitValue(c, 2);
	getBitValue(c, 3);
	getBitValue(c, 4);
	getBitValue(c, 5);
	getBitValue(c, 6);
	getBitValue(c, 7);
	*/

	int bitcount = 0;
	bool end_of_image = false;
	bool message_encoded = false;
	
	while (end_of_image == false) {
		if (message.eof()) {
			message_encoded = true;
		}
		image.get(c);
		// cout << c;
		
		if (image.eof()) {
			end_of_image = true;
			break;
		}
	}
	
	// message_encoded = true;
	
	if (message_encoded) {
		cout << "Message encoded" << endl;
	}
	else {
		cout << "Message not encoded" << endl;
	}
	cout << endl << "done" << endl;
	
	
	/* Pseudo Code
	check args
	open image
		err checking
	open hidden_message
		err checking
	
	get first char from hidden_message
		store in char 
	
	bitcount = 0
	variable for if file ended
	variable for when message is done encoding
	
	
	
	for all rows in image.rows
		for all columns in image.cols
			for all colors (R, G, B)]
				get pixel(row,col)
				change pixel data
					look at bit and see if it is equal to the current bit in char
					if not equal, then change it
					else, leave it alone
				increment bitcount
				
				check to see if message is encoded
					use a flag
					if message is now encoded then exit loops
				
				if bitcount == 8 then we have finished encoding the current char
					get next char
					reset bitcount
					if full message is encoded then set char to \0 (NULL)
					set flag
	
	check if whole message was encoded
		if not, output error message
	
	save encoded image
	return success
	*/
	
	
	
	
	return 0;
}