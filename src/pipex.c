#include "../includes/pipex.h"
int main(int argc, char *argv[])
{
    (void)argv;
    t_pipex pipex;
    int fd[2];
    if (argc != 5)
    {
        printf("Pas assez darguments\n");
        return (0);
    }

    if (pipe(fd) == -1)
    {
        perror("perror");
        return (1);
    }
    pipex.pid1 = fork();       // Création d'un nouveau processus
    if (pipex.pid1 == -1)      // En cas d'erreur
    {
        perror("fork");
        return (1);
    }
    else if (pipex.pid1 == 0)  // Code du processus P1 (fils)
    {
        close(fd[0]);
        // open(fd[1]);
        write(1, "child" ,5);
        close(fd[1]);
        return (0);
    }
    else                // Code du processus P2 (père)
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf(" / %s\n", buffer); 
        close(fd[0]);
        return (0);
}