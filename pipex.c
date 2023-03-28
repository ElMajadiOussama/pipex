#include "includes/pipex.h"
//fd 1 = stdout sortie
// fd 0 = stdin entree

int main(int ac, char **argv, char **envp)
{
    int fd[2];
    pid_t pid;
    char *path;
    char **cmd_path;

    if(ac != 5)
    {
        printf("argument!");
        return (0);
    }
    if(pipe(fd) < 0)
    {
        perror("pipe");
        return (1);
    }
    pid = fork();
    path = find_path(envp);
    cmd_path = ft_split(path, ':');
    if(pid == -1)
    {
        perror("Fork");
        return(1);
    }
    else if(pid == 0)
    {
        child_process(argv ,fd);
    }
    else
    {
        parent_process(argv, fd);
    }
}