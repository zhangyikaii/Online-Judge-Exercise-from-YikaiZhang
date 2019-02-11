

# 终于开始啦_ics_lab

[TOC]


## 1. DataLab
### bitAnd()

**摩根定理**:

非(P 且 Q) = (非 P) 或 (非 Q)

非(P 或 Q) = (非 P) 且 (非 Q)

**举个例子:**
`a = 1 0 0 1 0`
`b = 0 1 0 1 0`

`这两个数相 与`
`a & b  =  0 0 0 1 0`

`~a = 0 1 1 0 1`
`~b = 1 0 1 0 1`
// 都拥有 1 的位置变为 都是 0
// 取 或 操作筛选出都是 0 的位置
`~a | ~b = 1 1 1 0 1`

`再取 非 ~(~a | ~b)`
代码:

```c++
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
 
int bitAnd(int x, int y) {
  return ~(~x|~y);
}
```





### logicalShift()
**逻辑移位**
**定义:** 高 / 低位移出, 低 / 高位补零, 可能溢出; 若高位移出是 1 , 则左移的时候发生溢出

```c++
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    int tmp = ~(1 << 31);
    tmp = ((tmp >> n) << 1) + 1;
    return tmp & (x >> n);
}
```

`(1 << 31) 就是 1 后面跟着 31 个零 10000000000000000000000000000000`
`~(1 << 31) 就是 31 个 1`
`tmp = (tmp >> n) 移动后就是 31 - n 个 1`
`再左移一位 << 1, 就是后面又多了一个零, 再 + 1 就是后面最低位多了一个 1.`

**这样就构造出了32 - n 个 1, 和 x & 一下就可以了**
这题关键就是构造出 32 - n 个 1



### bitCount()

```c++
/*
 * bitCount - returns count of number of 1's in word
 *   返回 二进制数中 1 的个数
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 *   采用二分法，先计算x每两位中1的个数，并用对应的两队来存储这个个数。
 *   然后计算每4位1的个数，在用对应的4位进行存储。依次类推。
 *   最后整合得到16位中1的个数，即x中的1的个数。
 */
int bitCount(int x) {
    int count;

    int tmpMask1=(0x55) | (0x55 << 8);
    int mask1 = (tmpMask1) | (tmpMask1 << 16); // 得到掩码 01010101...01010101

    int tmpMask2 = (0x33) | (0x33 << 8);
    int mask2 = (tmpMask2) | (tmpMask2 << 16); // 得到掩码 00110011...00110011

    int tmpMask3 = (0x0f) | (0x0f << 8);
    int mask3 = (tmpMask3) | (tmpMask3 << 16); // 得到掩码  00001111...00001111

    int mask4 = (0xff) | (0xff <<16);          // 得到掩码  0000 0000 1111 1111 0000 0000 1111 1111

    int mask5 = (0xff) | (0xff << 8);          // 得到掩码：0000 0000 0000 0000 1111 1111 1111 1111

    // 下面有规律的
    count = (x & mask1) + ((x >> 1) & mask1);
    count = (count & mask2) + ((count >> 2) & mask2);
    count = (count & mask3) + ((count >> 4) & mask3);
    count = (count & mask4) + ((count >> 8) & mask4);
    count = (count & mask5) + ((count >> 16) & mask5);

    return count;
}
```

**精妙!**
每次`(count & mask2) + ((count >> 2) & mask2);` 这种操作之后, 就是计算每 2 / 4 / 8 / 16 位  1  的个数
例如, 106 = 01 10 10 10  经过第一行之后就是  01 01 01 01, 说明就是每两位就有一个一, 他们是分开来算的只不过四个 两个都排成在了一起

又**比如 107, 上面五行每次的计算过程如下:**

`000000000000000000000000 01 10 10 11`     `// 这是原来的数: 107`

`000000000000000000000000 01 01 01 10`    `// 最后一个 10 表示最后两位有两个 1  这是第一行处理结果`

`000000000000000000000000 0010 0011`

`000000000000000000000000 00000101`

`00000000000000000000000000000101`

`00000000000000000000000000000101`



### bang()

```c++
/*
 * bang - Compute !x without using !
 *   0为1,1为0
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
    int tmp = ~x + 1;	// tmp = -x;
    tmp = x | tmp; 		// 非0最高位一定是1，因为正数和负数 或  
    tmp = tmp >> 31; 	// 因为如果是正数/负数, 则最高位是 1, >> 31 之后32位都是 1 了, 如果是x == 0, 那么最高位是0, >> 31 之后还是 0.
    return (tmp+1);
}
```

注释打了为什么这么做哦



### tmin()

```c++
/*
 * tmin - return minimum two's complement integer
 *   返回补码整数的最小值
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
   return (1<<31);
}
```

二进制之前的那些理解, 在袁老师视频前面, 还要复习!!!



### fitsBits()

```c++
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   如果 x 可以表示为 n 位二进制补码形式 return 1
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    int shiftNumber= 32 + (~n + 1);		// 32 - n
    return !(x ^ ((x << shiftNumber) >> shiftNumber));
    // 先左移32 - n位，再右移32 - n位，即保留最后n位数. 
    // 再与 x 异或, 若两者相同表示 x 可被表示为一个 n 位整数，!0为1
}
```

**这里不理解, 题目是在说什么/xk**, `<< shiftNumber 之后又 >> shiftNumber` 有什么意义???  对于负数和正数不超的情形有什么意义???



### negate()

```c++
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   求相反数
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x) + 1;	 // 取反加1
}
```



### isPositive()

```c++
/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   x > 0 返回 1， x <= 0 返回 0
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    return !((x >> 31) | (!x));
    // 看符号位 x >> 31: (x >= 0) 为 (32 个 0), (x < 0) 为 (32 个 1)
    // 0 | x = x
    // 正数, 负数, 0 代进去验证一下
}
```

利用符号位和移位!



### isLessOrEqual()

```c++
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int signx = (x >> 31) & 1;
    int signy = (y >> 31) & 1;
    int isSameSign=! (signx ^ signy); // 符号相同isSameSign为 1, 不同为 0.
    int p = ! (((~x) + 1 + y) >> 31); // y - x 的符号位, >= 0 为 1, < 0 为 0
    return ( isSameSign & p ) | ( ( !isSameSign ) & signx); // 这一句不理解!
}
```

**最后那句是在做什么???**



### isTmin()

```c++
/*
 * returns 1 if x is the minimum, two’s complement number, and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 */
// 前面一部分用于判断左移一位后是否全部为 0, 后面一部分用来判断 x 值是否为 0
// 如果是最小的二进制补码数 => 100..00, x + x 就是全零了, 用这个特殊性!(x + x) = 1, 但是还要避免 x = 0
// 这是就用 !!x 了, x = 0 和 x != 0 是不同的 特殊结果, 很精妙!!!
int isTmin(int x) {
   return !(x+x) & !!(x);
}
```

判断是不是最小的**二进制补码数(two’s complement number)**, 真的**好精妙好精妙, 技巧记住!!!**



### isNotEqual()

  ```c++
/* isNotEqual
  *  题目要求：return 0 if x == y, and 1 otherwise
  *  例如: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
  *  允许操作：! ~ & ^ | + << >>
  *  操作数限制：6
  *  分值：2
  */
// 有了isTmin() 中 !! 的用法, 这题应该比较好理解, !! 可以区分全零和不全零, 并把所得结果弄特殊
// 如果x == y, 异或之后等于零, !! 之后等于零; 如果x != y, !(x ^ y) = 0, 然后!0 = 1, 很强!
int isNotEqual(int x, int y) {
    return(!!(x ^ y));
}
  ```

  

### anyOddBit()

- 题目要求：return 1 if any odd-numbered bit in word set to 1

  - 例如： anyOddBit(0x5) = 0, anyOddBit(0x7) = 1

- 允许操作：`! ~ & ^ | + << >>`

- 操作数限制：12

- 分值：2

  ```c++
  // 我们依旧不能超过 0xFF (就是11111111(255)) 的限制，所以需要把前面的 24 位都用 `|` 和 `>>` 运算符移动到最后八位中，再和 `10101010` 来做 `&` 操作，只要不为零，就说明在偶数位上有不为 0 位
  // 和一个特殊的数: 10101010 相 &, 来达到检测特定位的目的
  // 没有 10..10 那么长的数来检测只有0xFF, 所以用 | 和 >> 把全面的都压缩到后面的八位上.
  // !! 是判断, 同上isTmin 和 isNotEqual
  int anyOddBit(int x) {
      return !!((x | (x >> 8) | (x >> 16) | (x >> 24)) & 0xaa);
  }
  ```




### conditional()

- 题目要求：`same as x ? y : z`
  - 例如：`conditional(2,4,5) = 4`
- 允许操作：`! ~ & ^ | + << >>`
- 操作数限制：16
- 分值：3

这一题稍微有一些复杂，我们来看看怎么去想。因为不能用 `if` 来做流程判断，所以我们返回的表达式例一定要包含 y 和 z，**但是可以根据 x 的值来进行变换，**所以大概的式子是 `(y op expr) | (z op expr)`(op 表示操作符， expr 是某个表达式)。

然后就简单很多了，我们只要想办法做一个 expr，要么为 `0x00..00`，要么为 `0xffffffff` 即可，**于是表达式 `~!x + 1` 就可以满足我们的需求，**

x 等于 0 时，表达式为 `0xffffffff`，

x 不等于 0 时 `~!x + 1`  是 `0x00..00`, 满足以上要求! 

```c++
int conditional(int x, int y, int z) {
    /*
     *if x!=0, mask = 0x00000000, so y & ~mask == y and z & mask == 0
     *if x==0, mask = 0xffffffff, so y & ~mask = y & 0 = 0; z & mask = z
     */
    int mask = ~!x + 1; 
    return (y & ~mask) | (z & mask);
}
```

### subOK

- 题目要求：Determine if can compute x - y without overflow
  - 例如：
  - `subOK(0x80000000,0x80000000) = 1`
  - `subOK(0x80000000,0x70000000) = 0`
- 允许操作：`! ~ & ^ | + << >>`
- 操作数限制：20
- 分值：3

`判断是否可以在不溢出的情况下计算x - y;` 这题也不算轻松，但是我们可以一步一步来搞定，首先，既然是计算 x-y，我们要能够知道结果，由于不给使用减号，那就用倒数（之前的方法），所以 x-y 的结果为 `~y+1+x`。然后需要怎么判断呢，观察发现，**只有在以下这两种情况同时发生的时候，才是 overflow**

1.  x 和 y 符号不同
2.  x - y 的符号 和 x 不同

**可能有点难以理解**，overflow 指的是除符号位的最高位进位，也就是说符号会变化，所以需要 x 和 y 的符号不同
（这样 x - y 就等同于两个同符号的加法），也就是第一个条件；符号到底有没有变化呢，就要看 x - y 与 x 的符号是否相同，也就是第二个条件。所以代码如下：

```c++
int subOK(int x, int y) {
  /*
   * overflow of sub happens iff 
   * 1) x and y have different signs
   * 2) res = x - y has different sign with x
   */
  int res = x + (~y + 1);
  int sameSign = x ^ y;		// 符号位相同异或后为 0
  int resSign = res ^ x;

  // 想判断符号位就是 >> 31, 然后 !, 记住!
  return !((sameSign & resSign) >> 31);
}
```



### 技巧:

https://www.bilibili.com/video/av31289365/?p=2

- `(~n) + 1 = -n`

- ` 在左移不溢出的情况下, ( x << 1 ) + 1  就是   最低位补一个 1` 

- `机器里的 >> / << 操作都是有符号数的, `

  ​	`<< : 低位补 0`

   	`>> : 最高位是1(负数) 补 1, 最高位是0(正数) 补 0. `

- `x | (~x) 最高位一定是 1 (bang())`

- `0xff 或者 0xFF, 反正一个f就是四位 1, 注意16进制二进制可以轻松转换的!`.

- `~!x + 1` 在 `x == 0 和 x != 0` **的情况下可以化为很特殊的形式**, 分别是 `0xffffffff 和 0x00..00`, **想消除掉某个数, `& / |` 上全零或全 1 是很好用的**

- `0x80000000 是 100..00, 最小的二进制补码.`

- `想判断符号位就是 >> 31, 然后 !, 记住!`( 来自 subOK() )





```c++
#include <cstdio> 
#include <cstdlib> 
#include <iostream>
using namespace std;

// 可以用这个看 DataLab 每一步的变化

void TwoPrint(int t) {
	char str[100] = "";

	_itoa(t, str, 2);
    
    // for 输出 32 位前面的 0
	for (int i = 0; i < 32 - strlen(str); ++i)
		printf("0");
	printf("%s\n", str);
}

int main() {
	

	return 0;
}
```






