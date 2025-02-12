/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Anh Dao                                                    */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
    size_t fromLen = Str_getLength(pcFrom);
    size_t count = 0;
    const char *pos = pcLine;

    assert(pcLine != NULL);
    assert(pcFrom != NULL);
    assert(pcTo != NULL);

    if (fromLen == 0)
    {
        fputs(pcLine, stdout);
        return 0;
    }

    while ((pos = Str_search(pos, pcFrom)) != NULL)
    {
        while (pcLine != pos)
        {
            putchar(*pcLine);
            pcLine++;
        }
        fputs(pcTo, stdout);
        pos += fromLen;
        pcLine = pos;
        count++;
    }
    fputs(pcLine, stdout);
    return count;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
    enum
    {
        MAX_LINE_SIZE = 4096
    };
    enum
    {
        PROPER_ARG_COUNT = 3
    };

    char acLine[MAX_LINE_SIZE];
    size_t uReplaceCount = 0;

    if (argc != PROPER_ARG_COUNT)
    {
        fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Takes in strings argv[1] and argv[2]. Replaces each
    occurance of argv[1] with argv[2], writes these modified
    lines to stdout and writes to stderr with the # of
    replacements made */
    while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL)
    {
        size_t finalCount = replaceAndWrite(acLine, argv[1], argv[2]);
        uReplaceCount = uReplaceCount + finalCount;
    }
    fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
    return 0;
}
