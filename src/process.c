#include "../includes/pipex.h"

char *find_path(char *command, char **envp)
{
    char **path;
    char *full_path;
    int i;

    i = 0;
    while(envp[i])
    {
        if(ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            path = ft_split(envp[i], ":");
            if(!path)
                return(NULL);
            int j = 0;
            while(path[j])
            {
                full_path = ft_strjoin(path[j], "/");
                if(!full_path)
                    return (NULL);
                full_path = ft_strjoin(full_path, command);
                if(access(full_path, X_OK) == 0)
                {
                    free (path);
                    return (full_path);
                }
                free(full_path);
                j++;
            }
            free(path);
        }
        i++;
    }
    return (NULL);
}

void    child_process(char **argv, char **envp, int *fd)
{

}