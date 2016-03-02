int char_in_str(char c, char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (i);
    return (-1);
}
