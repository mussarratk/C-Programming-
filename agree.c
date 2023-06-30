#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user to agree
    char c = get_char("Do you agree? ");

    //Check whether agreed
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not Agreed.\n");
    }
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start Size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End Size: ");
    }
    while (endSize <= startSize);


    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    int population = startSize;
    while (population < endSize)
    {
        population = population + (population / 3) - (population / 4);
        year++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);
}