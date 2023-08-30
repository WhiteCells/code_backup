/*
基本 	替用
&&      and
&       and_eq
&       bitand
|       bitor
~       compl
!       not
!=      not_eq
||      or
|=      or_eq
^       xor
^=      xor_eq
 */

// #include <iso646.h>
// 
// #include <stdio.h>
// 
// int main() ??<
//     int a = 1, b = 2;
// 
//     if (1 == a and 2 == b) {
//         printf("success\n");
//     }
//     return 0;
// }

// %:include <stdlib.h>
// %:include <stdio.h>
// %:include <iso646.h>
//  
// int main(int argc, char** argv)
// ??<
//     if (argc > 1 and argv<:1:> not_eq NULL)
//     <%
//        printf("Hello%s\n", argv<:1:>);
//     %>
//  
//     return EXIT_SUCCESS;
// ??>