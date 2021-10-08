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
	
	ifstream message(messagefile);
	if (message.is_open() == false) {
		cout << "Error opening message" << endl;
	}
	
	char c = 'f';
	
	getBitValue(c, 0);
	getBitValue(c, 1);
	getBitValue(c, 2);
	getBitValue(c, 3);
	getBitValue(c, 4);
	getBitValue(c, 5);
	getBitValue(c, 6);
	getBitValue(c, 7);

	
	/* Pseudo Code
	check args
	open image
		err checking
	open hidden_message
		err checking
	
	get first char from hidden_message
		store in char 
	
	bitcount = 0
	
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