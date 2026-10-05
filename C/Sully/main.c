#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define TOKENS "#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#include <fcntl.h>%c#include <unistd.h>%c#include <sys/wait.h>%c%c#define TOKENS %c%s%c%c%cint main() {%c	int		x = %d;%c	char	filename[100];%c%c	if (x < 0)%c		return 0;%c	sprintf(filename, %cSully_%%d.c%c, x);%c%c	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);%c%c	if (fd < 0) {%c		dprintf(STDERR_FILENO, %cCan't open the file: %%s%%c%c, filename, 10);%c		return 1;%c	}%c	dprintf(fd, TOKENS, 10, 10, 10, 10, 10, 10, 10, 34, TOKENS, 34, 10, 10, 10, x - 1, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 34, 34, 34, 34, 34, 34, 10, 10, 34, 34, 34, 34, 10, 10);%c	close(fd);%c	pid_t pid = fork();%c	if (pid < 0)%c		return 1;%c	if (pid == 0)%c		execlp(%ccc%c, %ccc%c, filename, %c-o%c, %cSully%c, (char *)NULL);%c	waitpid(pid, NULL, 0);%c	execlp(%c./Sully%c, %c./Sully%c, (char *)NULL);%c}%c"

int main() {
	int		x = 5;
	char	filename[100];

	if (x < 0)
		return 0;
	sprintf(filename, "Sully_%d.c", x);

	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

	if (fd < 0) {
		dprintf(STDERR_FILENO, "Can't open the file: %s%c", filename, 10);
		return 1;
	}
	dprintf(fd, TOKENS, 10, 10, 10, 10, 10, 10, 10, 34, TOKENS, 34, 10, 10, 10, x - 1, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 34, 34, 34, 34, 34, 34, 10, 10, 34, 34, 34, 34, 10, 10);
	close(fd);
	pid_t pid = fork();
	if (pid < 0)
		return 1;
	if (pid == 0)
		execlp("cc", "cc", filename, "-o", "Sully", (char *)NULL);
	waitpid(pid, NULL, 0);
	execlp("./Sully", "./Sully", (char *)NULL);
}
