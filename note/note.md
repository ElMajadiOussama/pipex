# pipex
## Annuaire

1. Fork()
2. Big mouse

`fork()` : Divise un processur en deux sous-processus qui se produisent en même temps. 
Ca return 0 pour le processus enfant, et un nombre non null pour le processus parent, ou -1 si erreur.

Exemple : 

```c
{
    // processes enfant parce que la valeur de retour est zéro.
    if (fork() == 0)
        printf("Hello from Child!\n");
 
    // processus parent parce que la valeur de retour est non nulle.
    else
        printf("Hello from Parent!\n");
}

int main()
{
    forkexemple();
}
````
`execve()` : Execute un programme en remplaçant le processus courant.

Exemple : 

```c
{
    // On utilise la fonction execve() pour exécuter la commande ls
    // dans le processus enfant.
    if (fork() == 0)
        execve("/bin/ls", NULL, NULL);
 
    // On utilise la fonction execve() pour exécuter la commande ps
    // dans le processus parent.
    else
        execve("/bin/ps", NULL, NULL);
}
````




`pipe()` : Envoie la sortie du premier execve()en entrée au second execve();  


 `dup2()` : Echange nos fichiers avec stdin et stdout




```c
void pipex(int ​​f1, int f2) 
{ 
    int end[2] ;
    tuyau(fin); 
}
````

 ![](img1.png)