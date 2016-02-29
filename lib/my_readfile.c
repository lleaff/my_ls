#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_memcpy.h"

#ifdef __USE_BSD
#define OPEN_FLAGS S_IREAD
#else
#define OPEN_FLAGS S_IRUSR
#endif

#define BUFFERSIZE 3000

char *my_readfile(char* filename)
{
    int file;
    char buffer[BUFFERSIZE];
    int size;
    char *content;
    
    file = open (filename, O_RDONLY, OPEN_FLAGS);
    if (!file)
        return NULL;
    size = read(file, buffer, BUFFERSIZE - 1);
    if ((content = (char*)malloc(size)) == NULL)
        return NULL;
    if (buffer[size - 1] != '\0')
        buffer[size++] = '\0';
    my_memcpy(content, buffer, size);
    return content;
}
