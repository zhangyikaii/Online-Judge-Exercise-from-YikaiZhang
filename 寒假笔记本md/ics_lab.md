

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



```c++
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   x - y <= 0返回1，  > 0返回1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int singx = (x >> 31) & 1;
    int singy = (y >> 31) & 1;    //比较符号位 1 0 = 1,  0 1 = 0;
    int sing = (singx ^ singy) & singx; //保证singx和singy异号
    int tmp = x + ((~y) + 1); // x - y, 同号情况下,异号情况下会越界 0 0 = , 1 1 =
    tmp = ((tmp>>31)&1) & (!(singx ^ singy));// 保证singx 和 singy 同号
    //int t = (!(x ^ y)); //判断相等
    //printf("sing  =%d, tmp = %d\n", sing, tmp);
    return (sing | tmp | ((!(x ^ y)))); //
}
```



### 技巧:

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

https://www.bilibili.com/video/av31289365/?p=2

- `(~n) + 1 = -n`

- ` 在左移不溢出的情况下, ( x << 1 ) + 1  就是   最低位补一个 1` 

- `机器里的 >> / << 操作都是有符号数的, `

  ​	`<< : 低位补 0`

   	`>> : 最高位是1(负数) 补 1, 最高位是0(正数) 补 0. `
- `x | (~x) 最高位一定是 1 (bang())`






