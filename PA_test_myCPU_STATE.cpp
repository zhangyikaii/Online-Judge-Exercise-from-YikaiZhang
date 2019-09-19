
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;


#define CACHE_ENABLED
#define IA32_SEG             // protect mode enable
#define IA32_PAGE            // virtual memory management is now complete
// #define TLB_ENABLED

// PA 4
#define IA32_INTR            // tells NEMU and Kernel that we are ready for handling exceptions(traps only) and interrupts






typedef struct {
	uint32_t limit : 16;
	uint32_t base : 32;
}GDTR;

typedef union {
	struct {
		uint32_t pe : 1;
		uint32_t mp : 1;
		uint32_t em : 1;
		uint32_t ts : 1;
		uint32_t et : 1;
		uint32_t reserve : 26;
		uint32_t pg : 1;
	};
	uint32_t val;
}CR0;

// typedef union {
// 	struct {
// 		uint32_t present             : 1;
// 		uint32_t read_write          : 1;
// 		uint32_t user_supervisor     : 1;
// 		uint32_t page_write_through  : 1;
// 		uint32_t page_cache_disable  : 1;
// 		uint32_t accessed            : 1;
// 		uint32_t dirty               : 1;
// 		uint32_t pad0                : 1;
// 		uint32_t global              : 1;
// 		uint32_t pad1                : 3;
// 		uint32_t page_frame          : 20;
// 	};
// 	uint32_t val;
// } CR3;


typedef union
{
	struct
	{
		uint32_t reserved : 12;
		uint32_t PDBR : 20;
	};
	uint32_t val;
} CR3;


typedef struct {   // the 16-bit visible part, i.e., the selector 
	union {
		uint16_t val;
		struct {
			uint32_t rpl : 2;
			uint32_t ti : 1;
			uint32_t index : 13;
		};
	};

	// the invisible part, i.e., cache part 
	struct {
		uint32_t base;
		uint32_t limit;
		uint32_t type : 5;
		uint32_t privilege_level : 2;
		uint32_t soft_use : 1;
	};
}SegReg;


typedef struct {
	uint32_t limit : 16;
	uint32_t base : 32;
}IDTR;


// define the structure of registers
typedef struct {

	// general purpose registers
	union {
		union {
			union {
				uint32_t _32;
				uint16_t _16;
				uint8_t _8[2];
			};
			uint32_t val;
		} gpr[8];
		struct { // do not change the order of the registers
			uint32_t eax, ecx, edx, ebx, esp, ebp, esi, edi;
		};
	};

	// EIP
	uint32_t eip;

	// EFLAGS
	union {
		struct {
			uint32_t CF : 1;
			uint32_t dummy0 : 1;
			uint32_t PF : 1;
			uint32_t dummy1 : 1;
			uint32_t AF : 1;
			uint32_t dummy2 : 1;
			uint32_t ZF : 1;
			uint32_t SF : 1;
			uint32_t TF : 1;
			uint32_t IF : 1;
			uint32_t DF : 1;
			uint32_t OF : 1;
			uint32_t OLIP : 2;
			uint32_t NT : 1;
			uint32_t dummy3 : 1;
			uint32_t RF : 1;
			uint32_t VM : 1;
			uint32_t dummy4 : 14;
		};
		uint32_t val;
	} eflags;

#ifdef IA32_INTR
	// interrupt
	IDTR idtr; // IDTR, todo: define type IDTR
	uint8_t intr;
#endif

#ifdef IA32_SEG
	GDTR gdtr; // GDTR, todo: define type GDTR
	// segment registers, todo: define type SegReg
	union {
		SegReg segReg[6];
		struct { SegReg es, cs, ss, ds, fs, gs; };
	};
	// control registers, todo: define type CR0
	CR0 cr0;
#endif


#ifdef IA32_PAGE
	// control registers, todo: define type CR3
	CR3 cr3;
#endif
} CPU_STATE;



// ----------------------------------------------------------------------------------------

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff
#define mod 1000000007
#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
using namespace std;
typedef long long ll;

#define in(x) x=read()

#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int main() {
	// printf("%d\n", sizeof(CPU_STATE));
	CPU_STATE myCpu;
	printf("%d\n", sizeof(myCpu.cr3));

	return 0;
}