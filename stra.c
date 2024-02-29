/*-------------------------------------------------------------------*/
/* stra.c (Version 1)                                                */
/* Author: Anh Dao                                                   */
/*-------------------------------------------------------------------*/

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[])
{
    size_t uLength = 0;
    assert(pcSrc != NULL);
    while (pcSrc[uLength] != '\0')
        uLength++;
    return uLength;
}

char *Str_copy(char pcDest[], const char pcSrc[])
{
    size_t i = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    while (pcSrc[i] != '\0')
    {
        pcDest[i] = pcSrc[i];
        i++;
    }
    /* \0 because NULL represents a null pointer, and \0 is an empty
    string literal */
    return pcDest;
}

char *Str_concat(char dest[], const char pcSrc[])
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
    return dest;
    /* Return the destination string */
}

/* should be returning integers that denote if strings are equal,
less than, or greater than. */
int Str_compare(const char str1[], const char str2[])
{
    int i = 0;
    assert(str1 != NULL && str2 != NULL);
    /* should return how the strings differ:
    -1 if string 1 is less than string 2
    1 if string 1 is greater than string 2 */
    while (str1[i] == str2[i])
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
        /* return 0 means strings are equal */
        else if (str1[i] == '\0')
        {
            return 0;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

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
            /* The index of needle
             (its starting position)*/
            return (char *)&haystack[i];
        }
    }
    return NULL; /* Needle not found */
}
