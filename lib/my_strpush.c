void my_strpush(char* dest, char* toPush)
{
    while (*dest)
        dest++;
    while (*toPush)
        *dest++ = *toPush++;
    *dest = '\0';
}
