/*-------------------------------------------------------------------*/
/* stra.c (Version 1)                                                */
/* Author: Anh Dao                                                   */
/*-------------------------------------------------------------------*/

#include <assert.h>
#include <stddef.h>

size_t Str_getLength(const char pcSrc[])
{
    size_t uLength = 0;
    assert(pcSrc != NULL);
    while (pcSrc[uLength] != '\0')
        uLength++;
    return uLength;
}

size_t Str_copy(char copy[], const char pcSrc[])
{
    size_t i = 0;
    assert(copy != NULL && pcSrc != NULL);
    while (copy[i] = pcSrc[i] != '\0')
        i++;
    /* \0 because NULL represents a null pointer, and \0 is an empty
    string literal */
    return i;
}

size_t Str_concat(char dest[], const char pcSrc[])
{
    size_t destLength = Str_getLength(dest);
    size_t i = 0;
    assert(dest != NULL && pcSrc != NULL);
    while (pcSrc[i] != '\0')
    {
        dest[destLength + i] = pcSrc[i];
        i++;
    }
    dest[destLength + i] = '\0';
    return destLength + i;
    // Return the length of the concatenated string
}

size_t Str_compare(const char str1[], const char str2[])
{
    size_t i = 0;
    assert(str1 != NULL && str2 != NULL);
    while (str1[i] == str2[i])
    {
        if (str1[i] == '\0')
            return 0;
        // return 0 means strings are equal
        i++;
    }
    return i;
    // i is index where the strings differ
}

size_t Str_search(const char haystack[], const char needle[])
{
    assert(haystack != NULL && needle != NULL);

    size_t i, j, haystack_len = 0, needle_len = 0;

    haystack_len = Str_getLength(haystack);
    needle_len = Str_getLength(needle);

    // Ensures needle is shorter than haystack
    if (needle_len > haystack_len)
    {
        return -1;
    }

    // Loops in order to find the needle in the haystack
    for (i = 0; i <= haystack_len - needle_len; i++)
    {
        for (j = 0; j < needle_len; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
        }
        if (j == needle_len)
        {
            return i; // The index of needle
        }
    }
    return -1; // Needle not found
}
