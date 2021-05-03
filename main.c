#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	char **line;
	int fd = open(argv[1], O_RDONLY);
	line = malloc(sizeof(char*));
	if (line == NULL)
		return(0);
	while (get_next_line(fd, line) > 0)
	{
		printf("%s\n",*line);
		free(*line);
	}
	
}
