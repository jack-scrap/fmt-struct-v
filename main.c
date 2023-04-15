#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char sep = '.';

void err(char* msg) {
	fprintf(stderr, "Error: %s\n", msg);
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

	int maj;

	int no = atoi(argv[1]);

	if (no < 0) {
		err("Major version negative");

		return 1;
	}

	maj = no;

	int min = 0;
	if (argc > 1 + 1) {
		if (strlen(argv[1 + 1]) > 1) {
			err("Length of minor version too long");

			return 1;
		}

		int no = atoi(argv[1 + 1]);

		if (no < 0) {
			err("Minor version negative");

			return 1;
		}

		min = no;
	}

	int patch = 0;
	if (argc > 1 + 1 + 1) {
		if (strlen(argv[1 + 1 + 1]) > 1) {
			err("Length of patch version too long");

			return 1;
		}

		int no = atoi(argv[1 + 1 + 1]);

		if (no < 0) {
			err("Minor version negative");

			return 1;
		}

		patch = no;
	}

	printf("%d%c%d%c%d", maj, sep, min, sep, patch);

	return 0;
}
