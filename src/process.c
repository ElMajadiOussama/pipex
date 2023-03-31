#include "../includes/pipex.h"
#include <stdio.h>

void	errors(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void    exec(char *argv, char **env)
{
    char *path;
    char **cmd;
    int i;

    i = -1;

    cmd = ft_split(argv, ' ');
    path = find_path(cmd[0], env);
    if(!path)
    {
        while(cmd[++i])
            free(cmd[i]);
        free(cmd);
        errors("Wrong command");
    }
    if(execve(path, cmd, env) == -1)
        errors("Error");
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
    all_path = ft_split(env[i], ':');
    while(all_path[i])
    {
        join_path = ft_strjoin(all_path[i], "/");
        path = ft_strjoin(join_path, cmd);
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

    infile = open(argv[1], O_RDONLY, 0777);
    if(infile == -1)
        errors("Error");
    dup2(fd[1], STDOUT_FILENO);
    dup2(infile, STDIN_FILENO);
    close(fd[0]);
    exec(argv[2], env);
}

void    parent_process(char **argv, char **env, int *fd)
{
    int outfile;

    outfile = open(argv[4],  O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (outfile == -1)
        errors("Error");
    dup2(fd[0], STDIN_FILENO);
    dup2(outfile, STDOUT_FILENO);
    close(fd[1]);
    exec(argv[3], env);
}
