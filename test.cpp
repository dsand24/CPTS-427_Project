#include <stdio.h>
#include <stdlib.h>






int main(int argc, char** argv) {

	char *filename = "gumpypic.png";
	FILE *input = fopen(filename, "rb+");
	if (!input)
	{
		printf("Could not open input file '%s'\n", filename);
		system("PAUSE");
		return 1;
	}

	fseek(input, 0, SEEK_END);
	size_t size = ftell(input);
	rewind(input);

	char *buffer = (char *) malloc(size);
	if (!buffer)
	{
		printf("Out of memory, could not allocate %u bytes\n", size);
		system("PAUSE");
		return 1;
	}

	if (fread(buffer, 1, size, input) != size)
	{
		printf("Could not read from input file '%s'\n", filename);
		free(buffer);
		fclose(input);
		system("PAUSE");
		return 1;
	}
	fclose(input);

	// we loaded the file from disk into memory now

	for (size_t i = 0; (i + 3) < size; i += 4)
	{
		if (buffer[i + 0] == 0xFF && buffer[i + 1] == 0x00 && buffer[i + 2] == 0x00 && buffer[i + 3] == 0x00)
		{
			printf("Pixel %i is red\n", (i / 4));
		}
	}

	free(buffer);
}