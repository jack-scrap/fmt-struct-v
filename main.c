#include <stdio.h>
#include <string.h>

const char sep = '.';

void err(char* msg) {
	printf("Error: %s\n", msg);
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		err("No arguments");

		return 1;
	}

	if (argc > 1 + 1 + 1 + 1) {
		err("Wrong number of arguments");

		return 1;
	}

	char* maj = argv[1];

	char* min = "0";
	if (argc > 1 + 1) {
		min = argv[2];
	}

	if (strlen(min) > 1) {
		err("Length of minor version too long");
	}

	char* patch = "0";
	if (argc > 1 + 1 + 1) {
		patch = argv[2];
	}

	if (strlen(patch) > 1) {
		err("Length of patch version too long");
	}

	printf("%s%c%c%c%c\n", maj, sep, min[0], sep, patch[0]);

	return 0;
}
