#include "../includes/pipex.h"
int main(int argc, char *argv[], char **envp)
{
    int fd[2];
    pid_t   process_id;
    if (argc == 5)
    {
        if (pipe(fd) == -1)
        {
            perror("perror");
            return (1);
        }
        process_id = fork();// Création d'un nouveau processus
        if(process_id ==-1)
            perror("fork");
        if(process_id == 0)
            child_process(argv, envp, fd);
        waitpid(process_id, NULL, 0);
        parent_process(argv, envp, fd);
    }
    else
    {
        printf("Pas assez darguments\n");
        return (0);
    }
}