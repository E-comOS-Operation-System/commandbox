#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: info-of <filename>\n");
        return 1;
    }
    
    struct stat st;
    if (stat(argv[1], &st) != 0) {
        printf("Error: Cannot get file information %s: %s\n", argv[1], strerror(errno));
        return 1;
    }
    
    printf("File: %s\n", argv[1]);
    printf("Size: %ld bytes\n", st.st_size);
    printf("Type: %s\n", S_ISDIR(st.st_mode) ? "directory" : "file");
    printf("Permissions: %o\n", st.st_mode & 0777);
    printf("Modified: %s", ctime(&st.st_mtime));
    
    return 0;
}