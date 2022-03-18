#include <unistd.h>

#define USED used[(unsigned char)args[i][j]]

int main(int n, char **args) {
	int used[255] = {0};
	int i, j;
	if (n == 3) {
		i = 1;
		while(i < 3) {
			j = 0;
			while (args[i][j]) {
				if (!USED)
					USED = write(1, &args[i][j], 1);
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
