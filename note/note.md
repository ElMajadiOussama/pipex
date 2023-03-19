# pipex
## Items

1. Laptop
2. Big mouse

![](img1.png)

`pipe()` : Envoie la sortie du premier execve()en entrée au second execve();  

`fork()` : Exécute deux processus (c'est-à-dire deux commandes) dans un seul programme ;

Divise un processur en deux sous-processus qui se produisent en même temps. Ca return 0 pour le processus enfant, et un nombre non null pour le processus parent, ou -1 si erreur.

 `dup2()` : Echange nos fichiers avec stdin et stdout




```c
void pipex(int ​​f1, int f2) 
{ 
    int end[2] ;
    tuyau(fin); 
}
````

 