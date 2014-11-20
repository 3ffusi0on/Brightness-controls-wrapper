/*
** main.c
**
** Made by simon_p
**
** Started on Thu Nov 20 15:47:37 2014
*/

#include <unistd.h>
#include <stdio.h>

int     main(int argc, char *argv[])
{
    int val;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s ['-'|'+']\n", argv[0]);
        return (-1);
    }

    setuid(0); /* set root privileges */

    if (argv[1][0] == '+')
    {
        val = execl("/usr/local/bin/Brightness-up", NULL);
    }
    else if (argv[1][0] == '-')
    {
        val = execl("/usr/local/bin/Brightness-down", NULL);
    }
    else
    {
        fprintf(stderr, "Brightness wrapper error: Wrong paramater. Use '+' or '-'\n");
        return (-1);
    }

    if (val == -1)
    {
        fprintf(stderr, "Brightness wrapper error: %m\n");
    }
    return (0);
}
