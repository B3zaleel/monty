#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "monty.h"

/**
 * read_file - Reads the lines in a file froma file path
 * @path: The location of the file
 *
 * Return: The lines of the file, otherwise NULL
 */
char **read_file(char *path, int *lines_count)
{
  char **lines = NULL;
  struct stat file_stat;
  int fd;

  stat(path, &file_stat);
  if (S_ISREG(file_stat.st_mode))
  {
    fd = open(path, O_RDONLY);
    if (fd >= 0)
    {
      /* TODO: read file's lines */
      close(fd);
    }
  }
  return (lines);
}

