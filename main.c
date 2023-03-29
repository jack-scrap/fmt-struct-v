#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	int maj = atoi(argv[1]);

	int min = 0;
	if (argc > 1 + 1) {
		if (strlen(argv[1 + 1]) > 1) {
			err("Length of minor version too long");
		}

		min = atoi(argv[2]);
	}

	int patch = 0;
	if (argc > 1 + 1 + 1) {
		if (strlen(argv[1 + 1 + 1]) > 1) {
			err("Length of patch version too long");
		}

		patch = atoi(argv[3]);
	}

	printf("%d%c%d%c%d\n", maj, sep, min, sep, patch);

	return 0;
}
