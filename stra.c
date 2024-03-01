/*-------------------------------------------------------------------*/
/* stra.c (Version 1)                                                */
/* Author: Anh Dao                                                   */
/*-------------------------------------------------------------------*/

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "str.h"

/* Takes in an array, pointer constant source (pcSRC), returns
its length as a size_t (integer) */
size_t Str_getLength(const char pcSrc[])
{
    size_t uLength = 0;
    assert(pcSrc != NULL);
    while (pcSrc[uLength] != '\0')
        uLength++;
    return uLength;
}

/* Takes in two arrays, pointer constant destination (pcDest)
and pointer constant source (pcSrc), returns an array, pcDest
with the exact same contents as the inputted pcSrc array */
char *Str_copy(char pcDest[], const char pcSrc[])
{
    size_t i = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    while (pcSrc[i] != '\0')
    {
        pcDest[i] = pcSrc[i];
        i++;
    }
    pcDest[i] = '\0';
    /* \0 because NULL represents a null pointer, and \0 is an empty
    string literal */
    return pcDest;
}

/* Takes in arrays destination (dest) and pointer constant
source (pcSrc) returns an array dest containing the contents
of pcSrc concatenated onto the end of dest */
char *Str_concat(char dest[], const char pcSrc[])
{
    /* unsure if this is allowed, traverses the entire
    string while perhaps being unnecessary */
    size_t destLength = Str_getLength(dest);
    size_t i = 0;
    assert(dest != NULL && pcSrc != NULL);
    while (pcSrc[i] != '\0')
    {
        dest[destLength + i] = pcSrc[i];
        i++;
    }
    dest[destLength + i] = '\0';
    return dest;
    /* Return the destination string */
}

/* Compares two arrays, string1 (str1) and string2 (str2) and
returns one of three integers based on the following conditions:
0: the array contents are identical
1: str1 is greater than str2
-1: str2 is greater than str1 */
int Str_compare(const char str1[], const char str2[])
{
    int i = 0;
    assert(str1 != NULL && str2 != NULL);
    /* should return how the strings differ:
    -1 if string 1 is less than string 2
    1 if string 1 is greater than string 2 */
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return 0;
    }
    else if (str1[i] == '\0')
    {
        return -1;
    }
    return 1;
}

/* Takes in two arrays haystack and needle. Returns a
pointer to the beginning of the first occurrence of
the exact concents of array needle within array haystack.
Otherwise, returns NULL (needle not found) */
char *Str_search(const char haystack[], const char needle[])
{
    int i;
    int j;
    int haystack_len = 0;
    int needle_len = 0;
    assert(haystack != NULL && needle != NULL);
    haystack_len = Str_getLength(haystack);
    needle_len = Str_getLength(needle);

    /* Ensures needle is shorter than haystack */
    if (needle_len > haystack_len)
    {
        return NULL;
    }

    /* Loops in order to find the needle in the haystack */
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
            return (char *)&haystack[i];
        }
    }
    return NULL; /* Needle not found */
}
