# include <stdio.h> 
# include <fcntl.h>
# include <unistd.h> 
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>

int main()
{
    int infile;
    pid_t   pid;
    int fd[2];
    char buff;

    const char *red = "\033[31m";
    const char *reset = "\033[0m";
    if (pipe(fd) == -1)
    {
        perror("perror");
        return (1);
    }
    infile = open("txt", O_WRONLY);
    pid = fork();
 
    if(pid == 0){
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        while (read(fd[0], &buff, 1) > 0)
		{
			// Écrit le caractère lu dans la sortie standard
            write(STDOUT_FILENO, red, 5);
			write(STDOUT_FILENO, &buff, 1);
            write(STDOUT_FILENO, reset, 4);
		}
        // dup2(infile, STDOUT_FILENO);
        close(fd[0]);
    }
    else if(pid > 0){
        close(fd[0]);
        // dup2(infile, STDOUT_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        write(1, "Salut fils:\n", 11);
        // write(1, "H", 1);
        close(fd[1]);
    }
    waitpid(pid, NULL, 0);
    close(infile);
    return 0;
}