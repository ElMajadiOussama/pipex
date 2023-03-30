#include "../includes/pipex.h"
#include <stdio.h>

void	errors(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}


char    *find_path(char *cmd, char **env)
{
    char **all_path;
    char *path;
    char *join_path;
    int i;

    i = 0;
    while(ft_strnstr(env[i], "PATH=", 5) == 0)
        env++;
    all_path[i] = ft_split(env, ":");
    while(all_path[i])
    {
        join_path[i] = ft_strjoin(all_path[i], "/");
        path = ft_strjoin(join_path[i], cmd);
        free(join_path);
        if(access(path, F_OK) == 0)
            return(path);
        free(path);
        i++;
    }
    i = -1;
    while(all_path[++i])
        free(all_path[i]);
    free(all_path);
    return (NULL);
}

void    child_process(char **argv, char **env,int *fd)
{
    int infile;

    infile = open(fd[0], O_RDONLY, 0777);
    if(infile == -1)
        return (NULL);
    dup2(fd[0], STDOUT_FILENO);
    dup2(infile, STDIN_FILENO);
    close(fd[0]);
    exec(argv[2], env);
}
