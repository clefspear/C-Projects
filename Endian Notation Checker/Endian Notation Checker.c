#include <stdio.h>

#include <stdlib.h>

int checkEndianess(int);

int main(int argc, char *argv[])

{

            int check;

            unsigned int x = 23;

            check = checkEndianess(x);

            if (check)

                        printf("Little Endian\n");


            else

                        printf("Big Endian\n");

            system("PAUSE");

            return 0;

}

int checkEndianess(int x)

{
s
            char *holder = (char *)&x;

            if (*holder)

            {

                        return 1;

            }

            else

            {

                        return 0;

            }

}

