#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 
#include <string.h> 
#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_isalnum.c"
#include "ft_isascii.c"
#include "ft_isprint.c"
#include "ft_strlen.c"
#include "ft_memset.c"
#include "ft_bzero.c"
#include "ft_memcpy.c"
#include "ft_memmove.c"
#include "ft_strlcpy.c"
#include "ft_strlcat.c"
#include "ft_toupper.c"
#include "ft_tolower.c"
#include "ft_strchr.c"
#include "ft_strrchr.c"
#include "ft_strncmp.c"
#include "ft_memchr.c"
#include "ft_memcmp.c"
#include "ft_strnstr.c"
#include "ft_atoi.c"
/*#include "libft.h"*/

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		return (0);
	}
	printf("isalpha: %d\n", isalpha(argv[1][0]));
	printf("ft_isalpha: %d\n\n", ft_isalpha(argv[1][0]));

	printf("isalnum: %d\n", isalnum(argv[1][0]));
	printf("ft_isalnum: %d\n\n", ft_isalnum(argv[1][0]));
	
	printf("isdigit: %d\n", isdigit(argv[1][0]));
	printf("ft_isdigit: %d\n\n", ft_isdigit(argv[1][0]));

	printf("isascii: %d\n", isascii(argv[1][0]));
	printf("ft_isascii: %d\n\n", ft_isascii(argv[1][0]));

	printf("isprint: %d\n", isprint(argv[1][0]));
	printf("ft_isprint: %d\n\n", ft_isprint(argv[1][0]));

	char m[11]="123456789\0";
	printf("strlen: %lu\n",(long unsigned)strlen(m));
	printf("ft_strlen: %lu\n\n", (long unsigned)ft_strlen(m));

	char src[10] = "1234567890";
        char dst[10] = "";	

	printf("memset: %s\n", (char *)memset(dst, '@', 8));
	char dst1[10] = ""; 
	printf("ft_memset: %s\n\n", (char *)ft_memset(dst1, '@', 8));

	bzero(dst, 5);
	printf("bzero: %s\n", dst); 
	ft_bzero(dst1, 5);
	printf("ft_bzero: %s\n\n", dst1);

    printf("memcpy: %s\n", (unsigned char *)memcpy(((void *)0), ((void *)0), 0));
	printf("ft_memcpy: %s\n\n", (unsigned char *)ft_memcpy(((void *)0), ((void *)0), 0));

	char src1[11]="0123456789\0";
	ft_memmove(src1+4, src1+3, 3);
	printf("ft_memmove: %s\n", src1);
//   	printf("memmove: %s\n",(char *)memmove(src1+4, src1+3, 3));
	char src2[11] ="0123456789\0";
	memmove(src2+4, src2+3, 3);
	
   	printf("memmove: %s\n", src2);
//	printf("ft_memmove: %s\n\n", (char *)ft_memmove(src2+4, src2+3, 3));

	/*char src3[10]="0123456789";
	char dst2[5]= "";
    printf("strlcpy: %lu\n",(long unsigned)strlcpy(dst2, src3, 5));*/
	char src4[10] ="0123456789";
	char dst3[5] = "";
	printf("ft_strlcpy: %lu\n\n", (long unsigned)ft_strlcpy(dst3, src4, 5));

	char src5[11] ="0123456789";
	char dst4[6] = "\0";
	printf("ft_strlcat: %lu\n dst4: %s\n", (unsigned long)ft_strlcat(dst4, src5, 8), dst4);
	
	printf("toupper: %c\n", (char)toupper(argv[1][0]));
	printf("ft_toupper: %c\n\n", (char)ft_toupper(argv[1][0]));

	printf("tolower: %c\n", (char)tolower(argv[1][0]));
	printf("ft_tolower: %c\n\n", (char)ft_tolower(argv[1][0]));

	char a[] = "bonjour\0";
	char a1[14] = "I like at";
	char a2[4] = "ou\0";
	int b = (int)'i';
	printf("strchr: %s\n", strchr(a + 2, 'b'));
	printf("ft_strchr: %s\n\n", strchr(a + 2, 'b'));

    char *srcc = "abbbbbbbbbbbb";
    char *d1 = strrchr(srcc, 'a');
    char *d2 = ft_strrchr(srcc, 'a');
    printf("d1 == d2: %d\n", d1 == d2);
	printf("strrchr: %s\n", strrchr(srcc, '\0'));
	printf("ft_strrchr: %s\n\n", strrchr(srcc, '\0'));

	printf("strncmp: %d\n", strncmp("abcdef", "abcdefghijklmnop", 6));
	printf("ft_strncmp: %d\n\n", strncmp("abcdef", "abcdefghijklmnop", 6));
	printf("memchr: %s\n", (char *)memchr(a, 'k', 7));
	printf("ft_memchr: %s\n\n", (char *)ft_memchr(a, 'k', 7));

	printf("memcmp: %d\n", memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("ft_memcmp: %d\n\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));

	printf("strnstr: %s\n", strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	printf("ft_strnstr: %s\n\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));

	  printf("atoi: %d\n",   atoi("      -34567,./"));
      printf("ft_atoi:  %d\n\n", ft_atoi("     -34567</"));

	return (0);
}
