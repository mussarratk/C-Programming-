#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Prompt for text input
    string text = get_string("Text: ");
    printf("%s\n", text);

    // Count the number of letters in text
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }
    }
    printf("%i letters\n", letters);

    // Count the number of words in text
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    printf("%i words\n", words);

    // Count the number of sentences in text
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++; 
        }
    }
    printf("%i sentences\n", sentences);

    // Use Coleman liau index to determine the reading grade
    float calculation = (0.0588 * letters /  words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(calculation);
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
    }
}