/* { dg-do preprocess } */ 
/* { dg-options "-pedantic-errors" } */

#if 0xa == 10
#error yes /* { dg-error "#error yes" "normal conversion" } */
#endif

#if 077 == 63
#error yes /* { dg-error "#error yes" "normal conversion" } */
#endif

#if 12wrt /* { dg-error "nvalid number" "invalid number" } */
#endif

#if 0abc /* { dg-error "nvalid number" "invalid number" } */
#endif

#if 42abc /* { dg-error "nvalid number" "invalid number" } */
#endif

#if 1.2 /* { dg-error "floating point numbers" "floating point in #if" } */
#endif

#if 4uu /* { dg-error "too many `u' suffixes" "too many suffixes" } */
#endif

#if 124123231lll /* { dg-error "too many `l' suffixes" "too many suffixes" } */
#endif

#if 099 /* { dg-error "digits beyond the radix" "decimal in octal constant" } */
#endif

#if 0xfffffffffffffffff /* { dg-error "integer constant out of range" "range error" } */
#endif