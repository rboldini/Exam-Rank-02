#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char *get_next_line(int fd) {
	char	a[999999] = {0};
	char	*line;
	int		i = 0;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return NULL;
	while (read(fd, &a[i], 1) == 1) {
		if (a[i] == '\n')
			break;
		i++;
	}
	if (!a[0] || !(line = malloc(i + 1)))
		return NULL;
	i = 0;
	while (a[i]) {
		line[i] = a[i];
		i++;
	}
	line[i] = '\0';
	return line;
}
