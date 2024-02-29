#include <stddef.h>

/* The below five lines declare stra.c functions */
size_t Str_getLength(const char pcSrc[]);
char *Str_copy(char pcDest[], const char pcSrc[]);
char *Str_concat(char dest[], const char pcSrc[]);
int Str_compare(const char str1[], const char str2[]);
char *Str_search(const char haystack[], const char needle[]);

/* The below five lines declare strp.c functions */
size_t Str_getLength(const char *pcSrc);
char *Str_copy(char *pcDest, const char *pcSrc);
char *Str_concat(char *dest, const char *pcSrc);
int Str_compare(const char *str1, const char *str2);
char *Str_search(const char *haystack, const char *needle);
