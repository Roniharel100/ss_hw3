#include <string.h>
#include <stdio.h>
#define LINE 256
#define WORD 30

int getLine(char s[])
{
    //EOF (end of file)"no input"
    char c = getchar();
    int count = 0;

    while (c != '\n' && c != EOF && count < LINE)
    {
        s[count] = c;
        count++;
        c = getchar();
    }
    s[count] = '\0';
    return count;
}
int getword(char w[])
{
    //EOF (end of file)"no input"
    char c = getchar();
    int count = 0;
    while (c != '\n' && c != EOF && count < WORD && c != '\t' && c != ' ')
    {
        w[count] = c;
        count++;
        c = getchar();
    }
    w[count] = '\0';
    return count;
}

int substring(char *str1, char *str2)
{
    int i, j;
    for (i = 0; i < strlen(str1); i++)
    {
        for (j = 0; j < strlen(str2); j++)
        {
            if (str1[i + j] != str2[j])
            {
                j = -1;
                break;
            }
        }
        if (j != -1)
            return 1;
    }
    return 0;
}
int similar(char *s, char *t, int n)
{
    int i = 0;
    int j = 0;
    int num = 0;

    if (strlen(s) < strlen(t))
    {
        return 0;
    }

    while (j < strlen(t))
    {
        if (s[i] != t[j])
        {
            num = num + 1;
        }
        else
        {
            j++;
        }
        i++;
    }
    while (i < strlen(s))
    {
        if (s[i] == '\r')
        {
            break;
        }
        else
        {
            num = num + 1;
            i++;
        }
    }
    if (num > n)
        return 0;
    else
        return 1;
}
void print_lines(char *str)
{
    char line[LINE];
    int n = getLine(line);
    while (n > 0)
    {
        if (substring(line, str))
        {
            printf("%s\n", line);
        }
        n = getLine(line);
    }
}
void print_similar_words(char *str)
{
    char word[WORD];
    int n = getword(word);
    while (n > 0)
    {
        if (similar(word, str, 1))
        {
            printf("%s\n", word);
        }
        n = getword(word);
    }
}

int main()
{
    char word[WORD];
    char choice;
    getword(word);
    scanf("%c", &choice);
    if (choice == 'a')
    {
        print_lines(word);
    }
    else if (choice == 'b')
    {
        print_similar_words(word);
    }
    return 0;
}