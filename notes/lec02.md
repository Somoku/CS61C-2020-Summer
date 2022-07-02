# Lec02: C Intro, Pointers

## C Concepts

- Compiler: Creates useable programs(machine code) from C source code
- Typed variables: Must declare the kind of data the variable will contain
- Typed functions: Must declare the kind of data returned from the function
- Header files(.h): Allows you to declare functions and variables in separate files
- Structs: Groups of related values
- Enums: Lists of predefined values
- Pointers: Aliases to other variables

## Compilation

C is a compiled language（编译语言）

- C编译器将C程序映射到特定体系结构的机器代码，由CPU直接解释并运行

- Java将代码转变为独立于架构的字节码，由JVM（JAVA虚拟机）运行

- Python直接用解释器(interpreter)来解释代码
- C与其它语言最大的不同在于C程序直接映射到CPU能理解的低级机器指令，不需要任何中间者

### Compilation Advantages

- **Excellent run-time performance:** 比Python和Java运行速度更快，因为C针对特定体系结构进行优化
- **Fair compilation time:** 对编译程序的增强（如*Makefile*）允许重新编译时只针对修改后的文件

### Compilation Disadvantages

- 编译文件是特定于体系结构(CPU type and OS)的，可执行文件必须在新系统上重建
- "Edit -> Compilation -> Run[repeat]"的过程需要一定的时间

## Variable Types

### Typecasting in C

C is a "weakly" typed language（弱类型语言，可以显式进行类型转换）

所有变量都是以bit形式存储，其值取决于解释方式，即变量类型

## Structs

结构体用于定义复合数据类型

### Structs Alignment and Padding in C

结构体内数据有对齐要求

- 变量地址为变量字节数的倍数

- 结构体大小为所含变量的最大字节数的倍数

优点：CPU操作会更快，提高性能

可以通过额外的指令使其不对齐

### Unions in C

A "union" is also an instruction in C on how to arrange a bunch of bits

- union只为单个最大元素存储足够的数据，即union的大小等于所包含的变量字节数的最大值

- union中所有变量被映射到相同的地址上

union对解释机器代码很有用

## C vs. Java

|                   |               C                |                 Java                 |
| ----------------- | :----------------------------: | :----------------------------------: |
| Type of Language  |       Function Oriented        |           Object Oriented            |
| Programming Unit  |            Function            |      Class = Abstract Data Type      |
| Compilation       | Creates machine-dependent code | Creates machine-independent bytecode |
| Execution         |   Loads and execute program    |       JVM interprets bytecode        |
| Memory management |      Manual(malloc, free)      |    Automatic(garbage collection)     |

## C Syntax

### Generic C Program Layout

```c
/* Dumps of other files here(.h and .o) */
#include <system_files>
#include "local_files"

/* Handled by preprocessor. */
#define macro_name macro_expr /* Replace macro_name with macro_expr. */

/* declare functions. */
/* declare global variables and structs. */

int main(int argc, char *argv[]){
    /* the innards */
}

/* define other functions. */
```

- argc表示命令行的参数个数
- argv是指针数组，指针指向字符串参数，以NULL结尾

### True or False

No explicit Boolean type in C(unlike Java)

- 0 and NULL evaluates to FALSE in C
- Anything else evaluates to TRUE

### Update to ANSI C

使用"C99" or "C9x"标准：gcc -std=c99

**Highlights:**

- Declarations in *for* loops, like Java
- Java-like // comments (to end of line)
- Variable-length non-global arrays
- <inttypes.h> for explicit integer types
- <stdbool.h> for Boolean logic definitions

## Pointers

通用指针void*可以指向任何变量，但要谨慎使用，可能导致程序中的错误

int *x, y, z; 和 int *x, *y, *z; 不同：前者中x是指针，y和z是整型变量；后者中x, y, z都是指针

- Why pointers?
  - 当传递结构体或数组时，传递指针比传递一整个拷贝要更简便
  - 指针能使代码更简洁紧凑
- Careful: Pointers are likely the single largest source of bugs in C
  - 大多数动态内存管理的问题
  - 内存泄漏问题

### Pointer Bugs

未初始化的局部变量可能包含任何东西，声明一个指针只是为指针分配空间，而不分配所指向的地址

## Summary

- C是一种高效的编译语言，在安全性方面对程序员要求高
  - 弱类型语言，主动确定变量类型
  - 指针的安全性问题
- 指针是C语言下对数据地址的抽象
- C的函数是"传值"的