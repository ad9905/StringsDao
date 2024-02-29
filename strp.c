/*-------------------------------------------------------------------*/
/* strp.c (Version 1)                                                */
/* Author: Anh Dao                                                   */
/*-------------------------------------------------------------------*/

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "str.h"

size_t Str_getLength(const char *pcSrc)
{
    const char *pcEnd;
    assert(pcSrc != NULL);
    pcEnd = pcSrc;
    while (*pcEnd != '\0')
        pcEnd++;
    return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *pcDest, const char *pcSrc)
{
    char *dest = pcDest;
    assert(pcDest != NULL && pcSrc != NULL);
    while (*pcSrc != '\0')
    {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }
    *pcDest = '\0';
    return dest;
}

char *Str_concat(char *dest, const char *pcSrc)
{
    char *result = dest;
    assert(dest != NULL && pcSrc != NULL);
    while (*dest != '\0')
        dest++;
    while (*pcSrc != '\0')
    {
        *dest = *pcSrc;
        dest++;
        pcSrc++;
    }
    *dest = '\0';
    return result;
}

int Str_compare(const char *str1, const char *str2)
{
    assert(str1 != NULL && str2 != NULL);
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return (*str1 > *str2) ? 1 : -1;
        }
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0')
        return 0;
    else if (*str1 == '\0')
        return -1;
    else
        return 1;
}

char *Str_search(const char *haystack, const char *needle)
{
    const char *pHaystack;
    const char *pNeedle;
    assert(haystack != NULL && needle != NULL);
    if (*needle == '\0')
        return (char *)haystack; /* Empty needle, return haystack */
    while (*haystack != '\0')
    {
        pHaystack = haystack;
        pNeedle = needle;
        while (*pNeedle != '\0' && *pHaystack == *pNeedle)
        {
            pHaystack++;
            pNeedle++;
        }
        if (*pNeedle == '\0')
            return (char *)haystack;
        haystack++;
    }
    return NULL; /* Needle not found */
}
