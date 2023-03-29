#ifndef PIPEX_H
# define PIPEX_H

/*
** perror
*/
# include <stdio.h> 
/*
** open
*/
# include <fcntl.h>
/*
** dup2, close, STDIN_FILENO, fork, access
*/
# include <unistd.h> 
/*
** free, exit
*/
# include <stdlib.h>
/*
** waitpid
*/
# include <sys/wait.h>
/*
** pid_t
*/
# include <sys/types.h>
/*
** libft.h
*/
# include "../libft/libft.h"
void    child_process(char **argv, char **envp, int *fd);
#endif