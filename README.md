
## 📌 Undefined Behavior in Conversion Specifications

> **"If a conversion specification is invalid, the behavior is undefined. If any argument is not the correct type for the corresponding conversion specification, the behavior is undefined."**  
> _Source:_ ISO/IEC 9899:1999, Section 7.19.6.1 — The `fprintf` Function

> **"If the syntax of a conversion specification is invalid, unpredictable things will happen."**  
> _Source:_ [GNU C Library Manual - Table of Output Conversions](https://www.gnu.org/software/libc/manual/html_node/Table-of-Output-Conversions.html)

### Note:
In the context of this project, undefined behavior scenarios, as described above, **do not need to be replicated or simulated**.

---



# Variadic Arguments in C: 32-bit vs 64-bit Memory Layout

On a 32-bit system, arguments are typically stored sequentially on the stack. Each argument occupies a specific space in memory, based on its type and size.

On a 64-bit system, however, arguments are passed using a combination of registers and stack memory, with registers taking priority for the first few arguments (typically up to 6 integer or pointer arguments). Only when registers are exhausted are arguments placed on the stack.

However, **the specific behavior of variadic arguments in memory can vary significantly depending on the architecture and compiler**. Some compilers may handle variadic arguments differently, particularly when optimization flags are applied.

## Learn More

For additional details on type promotions and how they affect variadic functions, check this link:  
- [Type Promotions in C (cppreference.com)](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Argument-Promotions.html)

Table of Output Conversions in C (GNU C Library):
- [Table of Output Conversions (gnu.org)](https://www.gnu.org/software/libc/manual/html_node/Table-of-Output-Conversions.html)


### Example Code
```c
#include <stdio.h>

void z(char c,int n){while (n--> 0)printf("%c",c);}void y(void *q,int k){while(k-->0)if(*(unsigned char*)q>=32&&*(unsigned char*)q<=126)printf("%c ",*(unsigned char*)q++);else printf(". ");}void x(void *q,int k){while(k-->0)printf("%02x ",*(unsigned char*)q++);}void print_memory(void *q,int k){unsigned char*mem=(unsigned char*)q;int n,d=8,f=0;while(f<=k/d){n=d<k-f*d?d:k-f*d;printf("%p: ",mem);x(mem,n);z(' ',(d - n)*3);printf("-> ");y(mem, n);printf("\n");mem += n;f++;}} // ->hcoskun


// Test variadic function
int test_variadic(int count, ...) {
	print_memory(&count, 1000);  // For 64-bit systems, use print_memory((void*)(&count + 1), 1000);
	return 1;
}

int main(void) {
	test_variadic(100, 1, 2, 3, 4, 5 ,6 , 7 ,8 ,9 , 9 , 11, 11 ,12 ,13 ,14 ,15 ,16 ,17 ,18 ,19 ,20, 21, 22
	, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100);
    return 1;
}
```
---

### Example Output: 32-bit System

In a 32-bit system, each argument occupies 4 bytes on the stack and is stored sequentially in memory.
<details>
<summary>Click to expand 32-bit System Memory Layout</summary>

```
### 32-bit Memory Layout (Sample Output)

| Address |          Hex Data        | ASCII Representation  |
0xfff673d0: 64 00 00 00 01 00 00 00 -> d . . . . . . .  <----
0xfff673d8: 02 00 00 00 03 00 00 00 -> . . . . . . . .
0xfff673e0: 04 00 00 00 05 00 00 00 -> . . . . . . . .
0xfff673e8: 06 00 00 00 07 00 00 00 -> . . . . . . . .
0xfff673f0: 08 00 00 00 09 00 00 00 -> . . . . . . . .
0xfff673f8: 09 00 00 00 0b 00 00 00 -> . . . . . . . .
0xfff67400: 0b 00 00 00 0c 00 00 00 -> . . . . . . . .
0xfff67408: 0d 00 00 00 0e 00 00 00 -> . . . . . . . .
0xfff67410: 0f 00 00 00 10 00 00 00 -> . . . . . . . .
0xfff67418: 11 00 00 00 12 00 00 00 -> . . . . . . . .
0xfff67420: 13 00 00 00 14 00 00 00 -> . . . . . . . .
0xfff67428: 15 00 00 00 16 00 00 00 -> . . . . . . . .
0xfff67430: 17 00 00 00 18 00 00 00 -> . . . . . . . .
0xfff67438: 19 00 00 00 1a 00 00 00 -> . . . . . . . .
0xfff67440: 1b 00 00 00 1c 00 00 00 -> . . . . . . . .
0xfff67448: 1d 00 00 00 1e 00 00 00 -> . . . . . . . .
0xfff67450: 1f 00 00 00 20 00 00 00 -> . . . . . . . .
0xfff67458: 21 00 00 00 22 00 00 00 -> ! . . . . . . .
0xfff67460: 23 00 00 00 24 00 00 00 -> # . . . . . . .
0xfff67468: 25 00 00 00 26 00 00 00 -> % . . . . . . .
0xfff67470: 27 00 00 00 28 00 00 00 -> ' . . . . . . .
0xfff67478: 29 00 00 00 2a 00 00 00 -> ) . . . . . . .
0xfff67480: 2b 00 00 00 2c 00 00 00 -> + . . . . . . .
0xfff67488: 2d 00 00 00 2e 00 00 00 -> - . . . . . . .
0xfff67490: 2f 00 00 00 30 00 00 00 -> / . . . . . . .
0xfff67498: 31 00 00 00 32 00 00 00 -> 1 . . . . . . .
0xfff674a0: 33 00 00 00 34 00 00 00 -> 3 . . . . . . .
0xfff674a8: 35 00 00 00 36 00 00 00 -> 5 . . . . . . .
0xfff674b0: 37 00 00 00 38 00 00 00 -> 7 . . . . . . .
0xfff674b8: 39 00 00 00 3a 00 00 00 -> 9 . . . . . . .
0xfff674c0: 3b 00 00 00 3c 00 00 00 -> ; . . . . . . .
0xfff674c8: 3d 00 00 00 3e 00 00 00 -> = . . . . . . .
0xfff674d0: 3f 00 00 00 40 00 00 00 -> ? . . . . . . .
0xfff674d8: 41 00 00 00 42 00 00 00 -> A . . . . . . .
0xfff674e0: 43 00 00 00 44 00 00 00 -> C . . . . . . .
0xfff674e8: 45 00 00 00 46 00 00 00 -> E . . . . . . .
0xfff674f0: 47 00 00 00 48 00 00 00 -> G . . . . . . .
0xfff674f8: 49 00 00 00 4a 00 00 00 -> I . . . . . . .
0xfff67500: 4b 00 00 00 4c 00 00 00 -> K . . . . . . .
0xfff67508: 4d 00 00 00 4e 00 00 00 -> M . . . . . . .
0xfff67510: 4f 00 00 00 50 00 00 00 -> O . . . . . . .
0xfff67518: 51 00 00 00 52 00 00 00 -> Q . . . . . . .
0xfff67520: 53 00 00 00 54 00 00 00 -> S . . . . . . .
0xfff67528: 55 00 00 00 56 00 00 00 -> U . . . . . . .
0xfff67530: 57 00 00 00 58 00 00 00 -> W . . . . . . .
0xfff67538: 59 00 00 00 5a 00 00 00 -> Y . . . . . . .
0xfff67540: 5b 00 00 00 5c 00 00 00 -> [ . . . . . . .
0xfff67548: 5d 00 00 00 5e 00 00 00 -> ] . . . . . . .
0xfff67550: 5f 00 00 00 60 00 00 00 -> _ . . . . . . .
0xfff67558: 61 00 00 00 62 00 00 00 -> a . . . . . . .
0xfff67560: 63 00 00 00 64 00 00 00 -> c . . . . . . . <----
0xfff67568: 30 db fa f7 1b 79 62 56 -> 0 . . . . . . .
0xfff67570: 01 00 00 00 90 75 f6 ff -> . . . . . . . .
0xfff67578: 20 c0 fe f7 19 65 d9 f7 ->   . . . . . . .
0xfff67580: cf 80 f6 ff 70 00 00 00 -> . . . . . . . .
0xfff67588: 00 c0 fe f7 19 65 d9 f7 -> . . . . . . . .
0xfff67590: 01 00 00 00 44 76 f6 ff -> . . . . . . . .
0xfff67598: 4c 76 f6 ff b0 75 f6 ff -> L v . . . . . .
0xfff675a0: 00 b0 f9 f7 05 79 62 56 -> . . . . . . . .
0xfff675a8: 01 00 00 00 44 76 f6 ff -> . . . . . . . .
0xfff675b0: 00 b0 f9 f7 44 76 f6 ff -> . . . . . . . .
0xfff675b8: 80 bb fe f7 20 c0 fe f7 -> . . . . . . . .
0xfff675c0: 2b 4b f9 22 3b c1 db 7c -> + K . . . . . .
0xfff675c8: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0xfff675d0: 00 00 00 00 80 bb fe f7 -> . . . . . . . .
0xfff675d8: 20 c0 fe f7 00 08 87 fe ->   . . . . . . .
0xfff675e0: 40 ca fe f7 a6 64 d9 f7 -> @ . . . . . . .
0xfff675e8: 00 b0 f9 f7 f3 65 d9 f7 -> . . . . . . . .
0xfff675f0: 00 00 00 00 d0 9e 62 56 -> . . . . . . . .
0xfff675f8: 4c 76 f6 ff 20 c0 fe f7 -> L v . . . . . .
0xfff67600: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0xfff67608: 6d 65 d9 f7 cc 9f 62 56 -> m e . . . . . .
0xfff67610: 01 00 00 00 a0 70 62 56 -> . . . . . . . .
0xfff67618: 00 00 00 00 cb 70 62 56 -> . . . . . . . .
0xfff67620: 05 79 62 56 01 00 00 00 -> . . . . . . . .
0xfff67628: 44 76 f6 ff 00 00 00 00 -> D v . . . . . .
0xfff67630: 00 00 00 00 a0 9a fb f7 -> . . . . . . . .
0xfff67638: 3c 76 f6 ff 40 ca fe f7 -> < v . . . . . .
0xfff67640: 01 00 00 00 cf 80 f6 ff -> . . . . . . . .
0xfff67648: 00 00 00 00 d7 80 f6 ff -> . . . . . . . .
0xfff67650: e7 80 f6 ff ff 80 f6 ff -> . . . . . . . .
0xfff67658: 16 81 f6 ff 2b 81 f6 ff -> . . . . . . . .
0xfff67660: 60 81 f6 ff 70 81 f6 ff -> ` . . . . . . .
0xfff67668: 83 81 f6 ff 90 81 f6 ff -> . . . . . . . .
0xfff67670: b2 81 f6 ff a1 87 f6 ff -> . . . . . . . .
0xfff67678: bb 87 f6 ff dd 87 f6 ff -> . . . . . . . .
0xfff67680: f1 87 f6 ff 11 88 f6 ff -> . . . . . . . .
0xfff67688: 1e 88 f6 ff 29 88 f6 ff -> . . . . . . . .
0xfff67690: 31 88 f6 ff 51 88 f6 ff -> 1 . . . . . . .
0xfff67698: 59 88 f6 ff 9a 88 f6 ff -> Y . . . . . . .
0xfff676a0: 78 8f f6 ff ae 8f f6 ff -> x . . . . . . .
0xfff676a8: be 8f f6 ff e6 8f f6 ff -> . . . . . . . .
0xfff676b0: 00 00 00 00 20 00 00 00 -> . . . . . . . .
0xfff676b8: 40 35 fb f7 21 00 00 00 -> @ 5 . . . . . .
0xfff676c0: 00 30 fb f7 33 00 00 00 -> . . . . . . . .
0xfff676c8: f0 06 00 00 10 00 00 00 -> . . . . . . . .
0xfff676d0: ff fb 8b 17 06 00 00 00 -> . . . . . . . .
0xfff676d8: 00 10 00 00 11 00 00 00 -> . . . . . . . .
0xfff676e0: 64 00 00 00 03 00 00 00 -> d . . . . . . .
0xfff676e8: 34 60 62 56 04 00 00 00 -> 4 ` b V . . . .
0xfff676f0: 20 00 00 00 05 00 00 00 ->   . . . . . . .
0xfff676f8: 0b 00 00 00 07 00 00 00 -> . . . . . . . .
0xfff67700: 00 50 fb f7 08 00 00 00 -> . . . . . . . .
0xfff67708: 00 00 00 00 09 00 00 00 -> . . . . . . . .
0xfff67710: a0 70 62 56 0b 00 00 00 -> . . . . . . . .
0xfff67718: e8 03 00 00 0c 00 00 00 -> . . . . . . . .
0xfff67720: e8 03 00 00 0d 00 00 00 -> . . . . . . . .
0xfff67728: e8 03 00 00 0e 00 00 00 -> . . . . . . . .
0xfff67730: e8 03 00 00 17 00 00 00 -> . . . . . . . .
0xfff67738: 00 00 00 00 19 00 00 00 -> . . . . . . . .
0xfff67740: 6b 77 f6 ff 1a 00 00 00 -> k w . . . . . .
0xfff67748: 02 00 00 00 1f 00 00 00 -> . . . . . . . .
0xfff67750: f0 8f f6 ff 0f 00 00 00 -> . . . . . . . .
0xfff67758: 7b 77 f6 ff 00 00 00 00 -> { w . . . . . .
0xfff67760: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0xfff67768: 00 00 00 08 08 87 fe 35 -> . . . . . . . .
0xfff67770: 09 67 6a 84 64 0b 95 e7 -> . . . . . . . .
0xfff67778: 5e 4c d0 69 36 38 36 00 -> ^ L . . . . . .
0xfff67780: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0xfff67788: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0xfff67790: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0xfff67798: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0xfff677a0: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0xfff677a8: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0xfff677b0: 00 00 00 00 00 00 00 00 -> . . . . . . . .

```
</details>

---

### Example Output: 64-bit System

On a 64-bit system, the first few arguments are stored in registers, while additional arguments are stored on the stack.
<details>
<summary>Click to expand 64-bit System Memory Layout</summary>

```
### 64-bit Memory Layout (Sample Output)

| Address |          Hex Data        | ASCII Representation  |
0x7ffe74056fd0: 90 65 8e 86 bd 7f 00 00 -> . . . . . . . . 
0x7ffe74056fd8: 01 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74056fe0: 02 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74056fe8: 03 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74056ff0: 04 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74056ff8: 05 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057000: 60 41 8e 86 bd 7f 00 00 -> ` A . . . . . .
0x7ffe74057008: b8 e1 8c 86 bd 7f 00 00 -> . . . . . . . . 
0x7ffe74057010: ab da 3f c7 6c 55 00 00 -> . . . . . . . .
0x7ffe74057018: a8 fd 3f c7 6c 55 00 00 -> . . . . . . . .
0x7ffe74057020: 40 00 92 86 bd 7f 00 00 -> @ . . . . . . .
0x7ffe74057028: 71 8f 8f 86 bd 7f 00 00 -> q . . . . . . .
0x7ffe74057030: 01 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057038: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057040: 08 69 8e 86 bd 7f 00 00 -> . . . . . . . .
0x7ffe74057048: 60 16 90 86 bd 7f 00 00 -> ` . . . . . . .
0x7ffe74057050: 30 73 05 74 fe 7f 00 00 -> 0 s . . . . . .
0x7ffe74057058: 20 74 05 74 fe 7f 00 00 ->   t . . . . . .
0x7ffe74057060: 01 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057068: a8 74 05 74 fe 7f 00 00 -> . . . . . . . .
0x7ffe74057070: ab da 3f c7 6c 55 00 00 -> . . . . . . . .
0x7ffe74057078: ae bd 8f 86 bd 7f 00 00 -> . . . . . . . .
0x7ffe74057080: 90 73 05 74 fe 7f 00 00 -> . . . . . . . .
0x7ffe74057088: 9d db 3f c7 6c 55 00 00 -> . . . . . . . .
0x7ffe74057090: 06 00 00 00 00 00 00 00 -> . . . . . . . .  <----
0x7ffe74057098: 07 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570a0: 08 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570a8: 09 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570b0: 09 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570b8: 0b 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570c0: 0b 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570c8: 0c 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570d0: 0d 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570d8: 0e 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570e0: 0f 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570e8: 10 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570f0: 11 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740570f8: 12 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057100: 13 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057108: 14 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057110: 15 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057118: 16 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057120: 17 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057128: 18 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057130: 19 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057138: 1a 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057140: 1b 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057148: 1c 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057150: 1d 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057158: 1e 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057160: 1f 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057168: 20 00 00 00 00 00 00 00 ->   . . . . . . .
0x7ffe74057170: 21 00 00 00 00 00 00 00 -> ! . . . . . . .
0x7ffe74057178: 22 00 00 00 00 00 00 00 -> " . . . . . . .
0x7ffe74057180: 23 00 00 00 00 00 00 00 -> # . . . . . . .
0x7ffe74057188: 24 00 00 00 00 00 00 00 -> $ . . . . . . .
0x7ffe74057190: 25 00 00 00 00 00 00 00 -> % . . . . . . .
0x7ffe74057198: 26 00 00 00 00 00 00 00 -> & . . . . . . .
0x7ffe740571a0: 27 00 00 00 00 00 00 00 -> ' . . . . . . .
0x7ffe740571a8: 28 00 00 00 00 00 00 00 -> ( . . . . . . .
0x7ffe740571b0: 29 00 00 00 00 00 00 00 -> ) . . . . . . .
0x7ffe740571b8: 2a 00 00 00 00 00 00 00 -> * . . . . . . .
0x7ffe740571c0: 2b 00 00 00 00 00 00 00 -> + . . . . . . .
0x7ffe740571c8: 2c 00 00 00 00 00 00 00 -> , . . . . . . .
0x7ffe740571d0: 2d 00 00 00 00 00 00 00 -> - . . . . . . .
0x7ffe740571d8: 2e 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740571e0: 2f 00 00 00 00 00 00 00 -> / . . . . . . .
0x7ffe740571e8: 30 00 00 00 00 00 00 00 -> 0 . . . . . . .
0x7ffe740571f0: 31 00 00 00 00 00 00 00 -> 1 . . . . . . .
0x7ffe740571f8: 32 00 00 00 00 00 00 00 -> 2 . . . . . . .
0x7ffe74057200: 33 00 00 00 00 00 00 00 -> 3 . . . . . . .
0x7ffe74057208: 34 00 00 00 00 00 00 00 -> 4 . . . . . . .
0x7ffe74057210: 35 00 00 00 00 00 00 00 -> 5 . . . . . . .
0x7ffe74057218: 36 00 00 00 00 00 00 00 -> 6 . . . . . . .
0x7ffe74057220: 37 00 00 00 00 00 00 00 -> 7 . . . . . . .
0x7ffe74057228: 38 00 00 00 00 00 00 00 -> 8 . . . . . . .
0x7ffe74057230: 39 00 00 00 00 00 00 00 -> 9 . . . . . . .
0x7ffe74057238: 3a 00 00 00 00 00 00 00 -> : . . . . . . .
0x7ffe74057240: 3b 00 00 00 00 00 00 00 -> ; . . . . . . .
0x7ffe74057248: 3c 00 00 00 00 00 00 00 -> < . . . . . . .
0x7ffe74057250: 3d 00 00 00 00 00 00 00 -> = . . . . . . .
0x7ffe74057258: 3e 00 00 00 00 00 00 00 -> > . . . . . . .
0x7ffe74057260: 3f 00 00 00 00 00 00 00 -> ? . . . . . . .
0x7ffe74057268: 40 00 00 00 00 00 00 00 -> @ . . . . . . .
0x7ffe74057270: 41 00 00 00 00 00 00 00 -> A . . . . . . .
0x7ffe74057278: 42 00 00 00 00 00 00 00 -> B . . . . . . .
0x7ffe74057280: 43 00 00 00 00 00 00 00 -> C . . . . . . .
0x7ffe74057288: 44 00 00 00 00 00 00 00 -> D . . . . . . .
0x7ffe74057290: 45 00 00 00 00 00 00 00 -> E . . . . . . .
0x7ffe74057298: 46 00 00 00 00 00 00 00 -> F . . . . . . .
0x7ffe740572a0: 47 00 00 00 00 00 00 00 -> G . . . . . . .
0x7ffe740572a8: 48 00 00 00 00 00 00 00 -> H . . . . . . .
0x7ffe740572b0: 49 00 00 00 00 00 00 00 -> I . . . . . . .
0x7ffe740572b8: 4a 00 00 00 00 00 00 00 -> J . . . . . . .
0x7ffe740572c0: 4b 00 00 00 00 00 00 00 -> K . . . . . . .
0x7ffe740572c8: 4c 00 00 00 00 00 00 00 -> L . . . . . . .
0x7ffe740572d0: 4d 00 00 00 00 00 00 00 -> M . . . . . . .
0x7ffe740572d8: 4e 00 00 00 00 00 00 00 -> N . . . . . . .
0x7ffe740572e0: 4f 00 00 00 00 00 00 00 -> O . . . . . . .
0x7ffe740572e8: 50 00 00 00 00 00 00 00 -> P . . . . . . .
0x7ffe740572f0: 51 00 00 00 00 00 00 00 -> Q . . . . . . .
0x7ffe740572f8: 52 00 00 00 00 00 00 00 -> R . . . . . . .
0x7ffe74057300: 53 00 00 00 00 00 00 00 -> S . . . . . . .
0x7ffe74057308: 54 00 00 00 00 00 00 00 -> T . . . . . . .
0x7ffe74057310: 55 00 00 00 00 00 00 00 -> U . . . . . . .
0x7ffe74057318: 56 00 00 00 00 00 00 00 -> V . . . . . . .
0x7ffe74057320: 57 00 00 00 00 00 00 00 -> W . . . . . . .
0x7ffe74057328: 58 00 00 00 00 00 00 00 -> X . . . . . . .
0x7ffe74057330: 59 00 00 00 00 00 00 00 -> Y . . . . . . .
0x7ffe74057338: 5a 00 00 00 00 00 00 00 -> Z . . . . . . .
0x7ffe74057340: 5b 00 00 00 00 00 00 00 -> [ . . . . . . .
0x7ffe74057348: 5c 00 00 00 00 00 00 00 -> \ . . . . . . .
0x7ffe74057350: 5d 00 00 00 00 00 00 00 -> ] . . . . . . .
0x7ffe74057358: 5e 00 00 00 00 00 00 00 -> ^ . . . . . . .
0x7ffe74057360: 5f 00 00 00 00 00 00 00 -> _ . . . . . . .
0x7ffe74057368: 60 00 00 00 00 00 00 00 -> ` . . . . . . .
0x7ffe74057370: 61 00 00 00 00 00 00 00 -> a . . . . . . .
0x7ffe74057378: 62 00 00 00 00 00 00 00 -> b . . . . . . .
0x7ffe74057380: 63 00 00 00 00 00 00 00 -> c . . . . . . .
0x7ffe74057388: 64 00 00 00 00 00 00 00 -> d . . . . . . .  <----
0x7ffe74057390: 01 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe74057398: 90 dd 6d 86 bd 7f 00 00 -> . . . . . . . .
0x7ffe740573a0: 00 00 00 00 00 00 00 00 -> . . . . . . . .
0x7ffe740573a8: ab da 3f c7 6c 55 00 00 -> . . . . . . . .
0x7ffe740573b0: 90 74 05 74 01 00 00 00 -> . . . . . . . .
```
</details>

## Variadic Arguments: Type Promotion and Padding

When small types like char, short, and float are passed as arguments, they are automatically promoted to larger types—char and short become int, and float becomes double. This type promotion ensures that variadic functions can read these values reliably with va_list.

Padding, meanwhile, handles memory alignment. In 64-bit systems, all arguments are stored in 8-byte intervals for faster access, regardless of their original size. Type promotion standardizes data size, while padding arranges arguments in memory for efficient access with va_list.

### Example Code

```c
void print_memory(void *q,int k);

int test_variadic(int count, ...) {
    va_list args;
    va_start(args, count);
    print_memory(&count + 1, 1000);
    va_end(args);
    return 1;
}

int main(void) {
    char s = -1;
    print_memory(&s, 8); 
    test_variadic(100, s, 'a', 'c', s, 1, 2, 4, 5, 6, 7, 8, s, '9', 'a', 'b');
    return 0;
}
```
![image](https://github.com/user-attachments/assets/4058a5da-5002-4079-ab87-ef01c59bf8af)

## 🛠️ va_list Debug Tool

Include the print_va_list function in your code to inspect the values inside a va_list.

```c
void	print_va_list(va_list args)
{

	unsigned int gp_offset = *((unsigned int *)(args));
	unsigned int fp_offset = *((unsigned int *)(args) + 1);
	unsigned long overflow_arg_area = *((unsigned long *)(args) + 1);
	unsigned long reg_save_area = *((unsigned long *)(args) + 2);

	printf("\n=========== DEBUG: va_list Details ===========\n");
	printf("va_list Address:         %p\n", (void *)&args);
	printf("va_list Points to Addr:  %p\n", (void *)args);
	printf("General Purpose Offset:  %u\n", gp_offset);
	printf("Floating Point Offset:   %u\n", fp_offset);
	printf("Overflow Arg Area:  0x%lx\n", overflow_arg_area);
	printf("Register Save Area: 0x%lx\n", reg_save_area);
	printf("==============================================\n\n");
}
```

