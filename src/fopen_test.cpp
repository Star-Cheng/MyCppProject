#include <stdio.h>

int main(int argc, char *argv[])
{
    /*
    FILE *fopen (const char *__restrict __filename,
		    const char *__restrict __modes) __wur;
    1. r: read only
    2. w: write only
    3. r+: read and write
    4. w+: write and read
    5. a: append
    */
    FILE *ioFile = fopen("../data/hello.txt", "r");
    if (ioFile == NULL)
    {
        printf("open file failed\n");
        return -1;
    }
    else
    {
        printf("open file success\n");
    }
    /* int fclose (FILE *__stream);
    ** return: 0: success
    **        -1: fail
    */
    int result = fclose(ioFile);
    if (result == 0)
    {
        printf("close file success\n");
    }
    else if (result == EOF)
    {
        printf("close file failed\n");
    }
    return 0;
}