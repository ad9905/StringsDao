/*-------------------------------------------------------------------*/
/* stra.c (Version 1)                                                */
/* Author: Anh Dao                                                   */
/*-------------------------------------------------------------------*/

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

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
        pcDest[i] = pcSrc[i];
    i++;
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
size_t Str_compare(const char str1[], const char str2[])
{
    size_t i = 0;
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
            return 0;
        i++;
    }
    return 0;
}

size_t Str_search(const char haystack[], const char needle[])
{
    assert(haystack != NULL && needle != NULL);

    size_t i, j, haystack_len = 0, needle_len = 0;

    haystack_len = Str_getLength(haystack);
    needle_len = Str_getLength(needle);

    /* Ensures needle is shorter than haystack */
    if (needle_len > haystack_len)
    {
        return -1;
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
            return i;
        }
    }
    return -1; /* Needle not found */
}

int main()
{
    /* Test strings */
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "Hello, world!";
    char needle[] = "world";
    char dest[50] = "Concatenate ";

    /* Test my Str_getLength vs library's strlen() */
    printf("Str_getLength() result: %d\n", Str_getLength(str1));
    printf("strlen() result: %d\n", strlen(str1));

    /* Test my Str_compare() vs library's strcmp() */
    printf("Str_compare() result: %d\n", Str_compare(str1, str2));
    printf("strcmp() result: %d\n", strcmp(str1, str2));

    /* Test my Str_search() vs library's strstr() */
    printf("Str_search() result: %s\n", Str_search(str3, needle));
    printf("strstr() result: %s\n", strstr(str3, needle));

    /* Test my Str_concat vs library's str*/
    printf("Str_concat() result: %s\n", Str_concat(dest, str2));
    printf("strcat() result: %s\n", strcat(dest, str2));

    /* Test copy */
    printf("Str_copy() result: %s\n", Str_copy(str1, str2));
    printf("strcpy() result: %s\n", strcpy(str1, str2));

    return 0;
}