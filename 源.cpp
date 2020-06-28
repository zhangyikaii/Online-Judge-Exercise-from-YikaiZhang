/**
* zhanw15 @2018/5/12
* 蓝桥杯第六题		航班时间
*/
#include <stdio.h>
#include <iostream>
using namespace std;

//格式化输出
void printFormat(int t, char c) {
	if (t<10) printf("0%d%c", t, c);
	else printf("%d%c", t, c);
}

/*
case(A % 10)
0: aseg=7'b1000000;
1: aseg=7'b1111001;
2: aseg=7'b0100100;
3: aseg=7'b0110000;
4: aseg=7'b0011001;
5: aseg=7'b0010010;
6: aseg=7'b0000010;
7: aseg=7'b1111000;
8: aseg=7'b1111111;
9: aseg=7'b1111011;
endcase
case((A / 10) % 10)
0: bseg=7'b1000000;
1: bseg=7'b1111001;
2: bseg=7'b0100100;
3: bseg=7'b0110000;
4: bseg=7'b0011001;
5: bseg=7'b0010010;
6: bseg=7'b0000010;
7: bseg=7'b1111000;
8: bseg=7'b1111111;
9: bseg=7'b1111011;
endcase


case(B % 10)
0: cseg=7'b1000000;
1: cseg=7'b1111001;
2: cseg=7'b0100100;
3: cseg=7'b0110000;
4: cseg=7'b0011001;
5: cseg=7'b0010010;
6: cseg=7'b0000010;
7: cseg=7'b1111000;
8: cseg=7'b1111111;
9: cseg=7'b1111011;
endcase
case((B / 10) % 10)
0: dseg=7'b1000000;
1: dseg=7'b1111001;
2: dseg=7'b0100100;
3: dseg=7'b0110000;
4: dseg=7'b0011001;
5: dseg=7'b0010010;
6: dseg=7'b0000010;
7: dseg=7'b1111000;
8: dseg=7'b1111111;
9: dseg=7'b1111011;
endcase

*/


/*
PIN_W17
PIN_V18
PIN_AG17
PIN_AG16
PIN_AH17
PIN_AG18
PIN_AH18

PIN_AF16
PIN_V16
PIN_AE16
PIN_AD17
PIN_AE18
PIN_AE17
PIN_V17

PIN_AA21
PIN_AB17
PIN_AA18
PIN_Y17
PIN_Y18
PIN_AF18
PIN_W16

PIN_Y19
PIN_W19
PIN_AD19
PIN_AA20
PIN_AC20
PIN_AA19
PIN_AD20

PIN_AD21
PIN_AG22
PIN_AE22
PIN_AE23
PIN_AG23
PIN_AF23
PIN_AH22

PIN_AF21
PIN_AG21
PIN_AF20
PIN_AG20
PIN_AE19
PIN_AF19
PIN_AB21
*/


/*

module ALU(choose, t, asel, bsel, out, carry, overflow, ZF, Aeg, Beg, Ceg, Deg, Eeg, Feg);
	input [2:0] choose;
	input [6:0] t;
	input asel, bsel;
	wire [6:0] B, A;
	assign A = (asel) ? t : 0;
	assign B = (bsel) ? t : 0;
	output reg out, carry, overflow, ZF;
	output reg [6:0] Aeg;
	output reg [6:0] Beg;
	output reg [6:0] Ceg;
	output reg [6:0] Deg;
	output reg [6:0] Eeg;
	output reg [6:0] Feg;
	integer i, a, b;
	reg [6:0] c;
	reg [6:0] result;
	always @(choose or A or B or t)
	case(choose)
		0: begin { carry, result }=A + B;
					out = 0;
					overflow = (A[6] == B[6] && A[6] != result[6]);
					ZF = !(|result);
					case(result % 10)
					0: Eeg=7'b1000000;
					1: Eeg=7'b1111001;
					2: Eeg=7'b0100100;
					3: Eeg=7'b0110000;
					4: Eeg=7'b0011001;
					5: Eeg=7'b0010010;
					6: Eeg=7'b0000010;
					7: Eeg=7'b1111000;
					8: Eeg=7'b1111111;
					9: Eeg=7'b1111011;
					endcase
					case((result / 10) % 10)
					0: Feg=7'b1000000;
					1: Feg=7'b1111001;
					2: Feg=7'b0100100;
					3: Feg=7'b0110000;
					4: Feg=7'b0011001;
					5: Feg=7'b0010010;
					6: Feg=7'b0000010;
					7: Feg=7'b1111000;
					8: Feg=7'b1111111;
					9: Feg=7'b1111011;
					endcase
					case(A % 10)
					0: Aeg=7'b1000000;
					1: Aeg=7'b1111001;
					2: Aeg=7'b0100100;
					3: Aeg=7'b0110000;
					4: Aeg=7'b0011001;
					5: Aeg=7'b0010010;
					6: Aeg=7'b0000010;
					7: Aeg=7'b1111000;
					8: Aeg=7'b1111111;
					9: Aeg=7'b1111011;
					endcase
					case((A / 10) % 10)
					0: Beg=7'b1000000;
					1: Beg=7'b1111001;
					2: Beg=7'b0100100;
					3: Beg=7'b0110000;
					4: Beg=7'b0011001;
					5: Beg=7'b0010010;
					6: Beg=7'b0000010;
					7: Beg=7'b1111000;
					8: Beg=7'b1111111;
					9: Beg=7'b1111011;
					endcase
					
					case(B % 10)
					0: Ceg=7'b1000000;
					1: Ceg=7'b1111001;
					2: Ceg=7'b0100100;
					3: Ceg=7'b0110000;
					4: Ceg=7'b0011001;
					5: Ceg=7'b0010010;
					6: Ceg=7'b0000010;
					7: Ceg=7'b1111000;
					8: Ceg=7'b1111111;
					9: Ceg=7'b1111011;
					endcase
					case((B / 10) % 10)
					0: Deg=7'b1000000;
					1: Deg=7'b1111001;
					2: Deg=7'b0100100;
					3: Deg=7'b0110000;
					4: Deg=7'b0011001;
					5: Deg=7'b0010010;
					6: Deg=7'b0000010;
					7: Deg=7'b1111000;
					8: Deg=7'b1111111;
					9: Deg=7'b1111011;
					endcase
			end
		1: begin for(i = 0; i <= 6; i = i + 1) 
					c[i] = ~B[i];
					{ carry, result } = A + c + 1;
					out = 0;
					overflow = (A[6] == c[6] && A[6] != result[6]); 
					ZF = !(|result);
					case(A % 10)
	0: Aeg=7'b1000000;
	1: Aeg=7'b1111001;
	2: Aeg=7'b0100100;
	3: Aeg=7'b0110000;
	4: Aeg=7'b0011001;
	5: Aeg=7'b0010010;
	6: Aeg=7'b0000010;
	7: Aeg=7'b1111000;
	8: Aeg=7'b1111111;
	9: Aeg=7'b1111011;
	endcase
	case((A / 10) % 10)
	0: Beg=7'b1000000;
	1: Beg=7'b1111001;
	2: Beg=7'b0100100;
	3: Beg=7'b0110000;
	4: Beg=7'b0011001;
	5: Beg=7'b0010010;
	6: Beg=7'b0000010;
	7: Beg=7'b1111000;
	8: Beg=7'b1111111;
	9: Beg=7'b1111011;
	endcase
	
	case(B % 10)
	0: Ceg=7'b1000000;
	1: Ceg=7'b1111001;
	2: Ceg=7'b0100100;
	3: Ceg=7'b0110000;
	4: Ceg=7'b0011001;
	5: Ceg=7'b0010010;
	6: Ceg=7'b0000010;
	7: Ceg=7'b1111000;
	8: Ceg=7'b1111111;
	9: Ceg=7'b1111011;
	endcase
	case((B / 10) % 10)
	0: Deg=7'b1000000;
	1: Deg=7'b1111001;
	2: Deg=7'b0100100;
	3: Deg=7'b0110000;
	4: Deg=7'b0011001;
	5: Deg=7'b0010010;
	6: Deg=7'b0000010;
	7: Deg=7'b1111000;
	8: Deg=7'b1111111;
	9: Deg=7'b1111011;
	endcase
	
			end
		2: begin for(i = 0; i <= 6; i = i + 1) result[i] = ~A[i];out = 0; carry = 0; overflow = 0; ZF = !(|result);
	case(A % 10)
	0: Aeg=7'b1000000;
	1: Aeg=7'b1111001;
	2: Aeg=7'b0100100;
	3: Aeg=7'b0110000;
	4: Aeg=7'b0011001;
	5: Aeg=7'b0010010;
	6: Aeg=7'b0000010;
	7: Aeg=7'b1111000;
	8: Aeg=7'b1111111;
	9: Aeg=7'b1111011;
	endcase
	case((A / 10) % 10)
	0: Beg=7'b1000000;
	1: Beg=7'b1111001;
	2: Beg=7'b0100100;
	3: Beg=7'b0110000;
	4: Beg=7'b0011001;
	5: Beg=7'b0010010;
	6: Beg=7'b0000010;
	7: Beg=7'b1111000;
	8: Beg=7'b1111111;
	9: Beg=7'b1111011;
	endcase
	
	case(B % 10)
	0: Ceg=7'b1000000;
	1: Ceg=7'b1111001;
	2: Ceg=7'b0100100;
	3: Ceg=7'b0110000;
	4: Ceg=7'b0011001;
	5: Ceg=7'b0010010;
	6: Ceg=7'b0000010;
	7: Ceg=7'b1111000;
	8: Ceg=7'b1111111;
	9: Ceg=7'b1111011;
	endcase
	case((B / 10) % 10)
	0: Deg=7'b1000000;
	1: Deg=7'b1111001;
	2: Deg=7'b0100100;
	3: Deg=7'b0110000;
	4: Deg=7'b0011001;
	5: Deg=7'b0010010;
	6: Deg=7'b0000010;
	7: Deg=7'b1111000;
	8: Deg=7'b1111111;
	9: Deg=7'b1111011;
	endcase
		end

		3: begin for(i = 0; i <= 6; i = i + 1) result[i] = A[i] & B[i]; out = 0; carry = 0; overflow = 0; ZF = !(|result);
	case(A % 10)
	0: Aeg=7'b1000000;
	1: Aeg=7'b1111001;
	2: Aeg=7'b0100100;
	3: Aeg=7'b0110000;
	4: Aeg=7'b0011001;
	5: Aeg=7'b0010010;
	6: Aeg=7'b0000010;
	7: Aeg=7'b1111000;
	8: Aeg=7'b1111111;
	9: Aeg=7'b1111011;
	endcase
	case((A / 10) % 10)
	0: Beg=7'b1000000;
	1: Beg=7'b1111001;
	2: Beg=7'b0100100;
	3: Beg=7'b0110000;
	4: Beg=7'b0011001;
	5: Beg=7'b0010010;
	6: Beg=7'b0000010;
	7: Beg=7'b1111000;
	8: Beg=7'b1111111;
	9: Beg=7'b1111011;
	endcase
	
	case(B % 10)
	0: Ceg=7'b1000000;
	1: Ceg=7'b1111001;
	2: Ceg=7'b0100100;
	3: Ceg=7'b0110000;
	4: Ceg=7'b0011001;
	5: Ceg=7'b0010010;
	6: Ceg=7'b0000010;
	7: Ceg=7'b1111000;
	8: Ceg=7'b1111111;
	9: Ceg=7'b1111011;
	endcase
	case((B / 10) % 10)
	0: Deg=7'b1000000;
	1: Deg=7'b1111001;
	2: Deg=7'b0100100;
	3: Deg=7'b0110000;
	4: Deg=7'b0011001;
	5: Deg=7'b0010010;
	6: Deg=7'b0000010;
	7: Deg=7'b1111000;
	8: Deg=7'b1111111;
	9: Deg=7'b1111011;
	endcase
	
	end
		4: begin for(i = 0; i <= 6; i = i + 1) result[i] = A[i] | B[i]; out = 0; carry = 0; overflow = 0; ZF = !(|result); 
		case(A % 10)
	0: Aeg=7'b1000000;
	1: Aeg=7'b1111001;
	2: Aeg=7'b0100100;
	3: Aeg=7'b0110000;
	4: Aeg=7'b0011001;
	5: Aeg=7'b0010010;
	6: Aeg=7'b0000010;
	7: Aeg=7'b1111000;
	8: Aeg=7'b1111111;
	9: Aeg=7'b1111011;
	endcase
	case((A / 10) % 10)
	0: Beg=7'b1000000;
	1: Beg=7'b1111001;
	2: Beg=7'b0100100;
	3: Beg=7'b0110000;
	4: Beg=7'b0011001;
	5: Beg=7'b0010010;
	6: Beg=7'b0000010;
	7: Beg=7'b1111000;
	8: Beg=7'b1111111;
	9: Beg=7'b1111011;
	endcase
	
	case(B % 10)
	0: Ceg=7'b1000000;
	1: Ceg=7'b1111001;
	2: Ceg=7'b0100100;
	3: Ceg=7'b0110000;
	4: Ceg=7'b0011001;
	5: Ceg=7'b0010010;
	6: Ceg=7'b0000010;
	7: Ceg=7'b1111000;
	8: Ceg=7'b1111111;
	9: Ceg=7'b1111011;
	endcase
	case((B / 10) % 10)
	0: Deg=7'b1000000;
	1: Deg=7'b1111001;
	2: Deg=7'b0100100;
	3: Deg=7'b0110000;
	4: Deg=7'b0011001;
	5: Deg=7'b0010010;
	6: Deg=7'b0000010;
	7: Deg=7'b1111000;
	8: Deg=7'b1111111;
	9: Deg=7'b1111011;
	endcase
	
		end
		5: begin for(i = 0; i <= 6; i = i + 1) result[i] = A[i] ^ B[i]; out = 0; carry = 0; overflow = 0; ZF = !(|result);
		case(A % 10)
	0: Aeg=7'b1000000;
	1: Aeg=7'b1111001;
	2: Aeg=7'b0100100;
	3: Aeg=7'b0110000;
	4: Aeg=7'b0011001;
	5: Aeg=7'b0010010;
	6: Aeg=7'b0000010;
	7: Aeg=7'b1111000;
	8: Aeg=7'b1111111;
	9: Aeg=7'b1111011;
	endcase
	case((A / 10) % 10)
	0: Beg=7'b1000000;
	1: Beg=7'b1111001;
	2: Beg=7'b0100100;
	3: Beg=7'b0110000;
	4: Beg=7'b0011001;
	5: Beg=7'b0010010;
	6: Beg=7'b0000010;
	7: Beg=7'b1111000;
	8: Beg=7'b1111111;
	9: Beg=7'b1111011;
	endcase
	
	case(B % 10)
	0: Ceg=7'b1000000;
	1: Ceg=7'b1111001;
	2: Ceg=7'b0100100;
	3: Ceg=7'b0110000;
	4: Ceg=7'b0011001;
	5: Ceg=7'b0010010;
	6: Ceg=7'b0000010;
	7: Ceg=7'b1111000;
	8: Ceg=7'b1111111;
	9: Ceg=7'b1111011;
	endcase
	case((B / 10) % 10)
	0: Deg=7'b1000000;
	1: Deg=7'b1111001;
	2: Deg=7'b0100100;
	3: Deg=7'b0110000;
	4: Deg=7'b0011001;
	5: Deg=7'b0010010;
	6: Deg=7'b0000010;
	7: Deg=7'b1111000;
	8: Deg=7'b1111111;
	9: Deg=7'b1111011;
	endcase
	
	end
		6: begin 	
		a = A; b = B;
		a = a<<28; b = b<<28;
		if(a>b) out = 1; else out = 0; carry = 0; overflow = 0; ZF = 0;
		case(A % 10)
	0: Aeg=7'b1000000;
	1: Aeg=7'b1111001;
	2: Aeg=7'b0100100;
	3: Aeg=7'b0110000;
	4: Aeg=7'b0011001;
	5: Aeg=7'b0010010;
	6: Aeg=7'b0000010;
	7: Aeg=7'b1111000;
	8: Aeg=7'b1111111;
	9: Aeg=7'b1111011;
	endcase
	case((A / 10) % 10)
	0: Beg=7'b1000000;
	1: Beg=7'b1111001;
	2: Beg=7'b0100100;
	3: Beg=7'b0110000;
	4: Beg=7'b0011001;
	5: Beg=7'b0010010;
	6: Beg=7'b0000010;
	7: Beg=7'b1111000;
	8: Beg=7'b1111111;
	9: Beg=7'b1111011;
	endcase
	
	case(B % 10)
	0: Ceg=7'b1000000;
	1: Ceg=7'b1111001;
	2: Ceg=7'b0100100;
	3: Ceg=7'b0110000;
	4: Ceg=7'b0011001;
	5: Ceg=7'b0010010;
	6: Ceg=7'b0000010;
	7: Ceg=7'b1111000;
	8: Ceg=7'b1111111;
	9: Ceg=7'b1111011;
	endcase
	case((B / 10) % 10)
	0: Deg=7'b1000000;
	1: Deg=7'b1111001;
	2: Deg=7'b0100100;
	3: Deg=7'b0110000;
	4: Deg=7'b0011001;
	5: Deg=7'b0010010;
	6: Deg=7'b0000010;
	7: Deg=7'b1111000;
	8: Deg=7'b1111111;
	9: Deg=7'b1111011;
	endcase
		
	end
		7: begin if(A==B) out = 1; else out = 0; carry = 0; overflow = 0; ZF = 0; 
		case(A % 10)
	0: Aeg=7'b1000000;
	1: Aeg=7'b1111001;
	2: Aeg=7'b0100100;
	3: Aeg=7'b0110000;
	4: Aeg=7'b0011001;
	5: Aeg=7'b0010010;
	6: Aeg=7'b0000010;
	7: Aeg=7'b1111000;
	8: Aeg=7'b1111111;
	9: Aeg=7'b1111011;
	endcase
	case((A / 10) % 10)
	0: Beg=7'b1000000;
	1: Beg=7'b1111001;
	2: Beg=7'b0100100;
	3: Beg=7'b0110000;
	4: Beg=7'b0011001;
	5: Beg=7'b0010010;
	6: Beg=7'b0000010;
	7: Beg=7'b1111000;
	8: Beg=7'b1111111;
	9: Beg=7'b1111011;
	endcase
	
	case(B % 10)
	0: Ceg=7'b1000000;
	1: Ceg=7'b1111001;
	2: Ceg=7'b0100100;
	3: Ceg=7'b0110000;
	4: Ceg=7'b0011001;
	5: Ceg=7'b0010010;
	6: Ceg=7'b0000010;
	7: Ceg=7'b1111000;
	8: Ceg=7'b1111111;
	9: Ceg=7'b1111011;
	endcase
	case((B / 10) % 10)
	0: Deg=7'b1000000;
	1: Deg=7'b1111001;
	2: Deg=7'b0100100;
	3: Deg=7'b0110000;
	4: Deg=7'b0011001;
	5: Deg=7'b0010010;
	6: Deg=7'b0000010;
	7: Deg=7'b1111000;
	8: Deg=7'b1111111;
	9: Deg=7'b1111011;
	endcase
	
		end
		default begin out = 0; overflow = 0; carry = 0; ZF = 0; result = 0; end
	endcase
endmodule
*/




int main()
{
	cout << (9 | 6) << endl;
	int n; char c; //输入数据组数
	scanf("%d", &n);
	int flyTime[23423]; //flytime 单位：秒

	int i = 2 * n;
	while (i--) {
		if (i % 2)
			flyTime[i / 2] = 0; //初始化

		int h1, m1, s1, h2, m2, s2;
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		flyTime[i / 2] += 60 * 60 * (h2 - h1) + 60 * (m2 - m1) + (s2 - s1);

		//处理次日、第三天到达情况
		while ((c = getchar()) != '\n') {
			if (c == '+') 
				flyTime[i / 2] += 24 * 60 * 60 * (getchar() - '0');
		}
	}

	for (i = n - 1; i >= 0; i--) {
		flyTime[i] /= 2;
		printFormat(flyTime[i] / 3600, ':');        //hour
		printFormat(flyTime[i] / 60 % 60, ':');       //minute
		printFormat(flyTime[i] % 60, '\n');         //second
	}

	return 0;
}