# Lec03: C Arrays, Strings, More Pointers

## Struct Clarification

另一种定义结构体的方法：typedef

typedef是用于指定类型或定义新名称的类型的关键字

```C
typedef struct foo{
	/* fields */
} bar;
bar name1;

struct foo{
	/* fields */
};
typedef struct foo bar
bar name1;
```

## Operator Precedence

==比逻辑运算(&, |, &&, ||)优先级更高

x&1==0等价于x&(1==0)

## Sizeof()

- Arrays: 返回数组的大小
- Structs: 返回一个结构体实例的大小（结构体内变量的大小+填充）

## Array Basics

C的数组不知道自己的长度，不检查数组范围，容易导致segmentation fault和bus error（Java的数组知道自己的长度）

在声明数组大小时，尽量用单独的常变量，以保证重复使用数组长度时不会出错

数组的地址是没有意义的，它的值与数组第一个元素的地址相同。即对数组a有a=&a

K&R: "An array name is not a variable."

数组传递给函数后其大小信息丢失，编译器只知道传递的是一个指针，因此`printf("%d\n",sizeof(array));`只会输出指针大小。而对于函数内的局部数组变量，编译器知道它的大小，用`sizeof()`时会输出数组实际大小

## Pointer Arithmetic

pointer $\pm$ number实际上是pointer $\pm$ number*sizeof(\*pointer)

i.e. moves pointer to the next array element

e.g. int \*p; p + 1 $\Leftrightarrow$ Add 1*sizeof(int)

对结构体构成的数组，也像基本类型一样处理

### Increment and Dereference

- 如果有多个前置运算符，则**从右往左**依次计算
  - *--p先计算--再计算\*

- 后置增减运算符比前置运算符优先级高
  - 但后置运算符会在最后生效
  - *p++会返回\*p，然后让p+1
  - (*p)++会返回\*p，然后让(\*p)+1