void *my_memcpy(void *dest, const void *src, int size)
{
    int n;

    for (n = 0; n < size; n++)
    {
        *(((char*)dest) + n) = *(((char*)src) + n);
    }
    return dest;
}
