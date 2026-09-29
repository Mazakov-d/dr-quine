#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//hello world
#define STR "#include <fcntl.h>%c#include <stdio.h>%c#include <unistd.h>%c%c//hello world%c#define STR %c%s%c%c#define OPEN open(%cGrace_kid.c%c, O_WRONLY | O_CREAT | O_TRUNC, 0644)%c#define MAIN int main() { int fd = OPEN; if (fd < 0) { dprintf(2, %cError opening the file.%c); return 1; } dprintf(fd, STR, 10, 10, 10, 10, 10, 34, STR, 34, 10, 34, 34, 10, 34, 34, 10, 10, 10); close(fd); return 0;}%c%cMAIN%c"
#define OPEN open("Grace_kid.c", O_WRONLY | O_CREAT | O_TRUNC, 0644)
#define MAIN int main() { int fd = OPEN; if (fd < 0) { dprintf(2, "Error opening the file."); return 1; } dprintf(fd, STR, 10, 10, 10, 10, 10, 34, STR, 34, 10, 34, 34, 10, 34, 34, 10, 10, 10); close(fd); return 0;}

MAIN
