#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;


#define MOD 1000000007
#define SIGN(A) ((A > 0) ? 1 : -1) 
int divideConquer(int X, int Y, int n, int n0){
	int sign = SIGN(X) * SIGN(Y);
	int x = abs(X);
	int y = abs(Y);
	if (x == 0 || y == 0){
		return 0;
	}
	else if (n == 1 || n0 == 1){
		return sign * x * y;
	}
	else{
		int p1 = pow(10, (int)(n / 2)), p2 = pow(10, (int)(n0 / 2));
		int A = (int)x / p1;
		int B = x - A * p1;
		int C = (int)y / p2;
		int D = y - C * p2;
		int AC = divideConquer(A, C, n / 2, n0 / 2) % MOD;
		int BD = divideConquer(B, D, n / 2, n0 / 2) % MOD;
		int ABDC = divideConquer((A - B), (D - C), n / 2, n0 / 2) + AC + BD;
		return sign * (AC * (int)pow(10, n / 2 + n0 / 2) % MOD + ABDC * (int)pow(10, (int)(n / 2)) % MOD + BD);
	}
}

int main() {
	cout << divideConquer(2351, 2361, 4) << endl;

	return 0;
}


/*
module Timer(clk, en, stop, clear, endone, seg0, seg1);
	input clk;
	input en;
	input stop;
	input clear;
	output reg endone;
	output reg [6:0] seg0;
	output reg [6:0] seg1;
	reg [3:0] h = 0;
	reg [3:0] l = 0;
	reg [6:0] counter = 0;
	reg clk_1s = 0;
	reg [24:0] count_clk = 0;

	always @ (posedge clk)
	begin
		if(count_clk == 25000000)
			begin
				count_clk = 0;
				clk_1s = ~clk_1s;
			end
		else
			count_clk = count_clk + 1;
	end

	always @ (posedge clk_1s)
	begin
	if (en)
	begin
		endone = 0;
		if (clear)
		begin
			counter = 0;
			l = 0;
			h = 0;
		end
		else if (stop)
		begin
			counter = counter;
			l = 1;
			h = h;
		end
		else
		begin
			if (counter == 99)
			begin
				endone = 1;
				counter = 0;
			end
			else
			counter = counter + 1;
			l = counter % 10;
			h = ((counter - counter % 10) / 10);
		end

		case(h)
		0: seg1 = 7'b1000000;
		1: seg1 = 7'b1111001;
		2: seg1 = 7'b0100100;
		3: seg1 = 7'b0110000;
		4: seg1 = 7'b0011001;
		5: seg1 = 7'b0010010;
		6: seg1 = 7'b0000010;
		7: seg1 = 7'b1111000;
		8: seg1 = 7'b1111111;
		9: seg1 = 7'b1111011;
		endcase
		case(l)
		0: seg0 = 7'b1000000;
		1: seg0 = 7'b1111001;
		2: seg0 = 7'b0100100;
		3: seg0 = 7'b0110000;
		4: seg0 = 7'b0011001;
		5: seg0 = 7'b0010010;
		6: seg0 = 7'b0000010;
		7: seg0 = 7'b1111000;
		8: seg0 = 7'b1111111;
		9: seg0 = 7'b1111011;
		endcase
	end
	else if (!en)
	begin
		conuter = 0;
		l = 0;
		h = 0;
		seg0 = 7'b1000000;
		seg1 = 7'b1000000;
	end
end
endmodule

begin 
	en = 1; clk = 0; clear = 0; stop = 0; #20;
	en = 1;			 clear = 0; stop = 1; #20;
	en = 1;			 clear = 1; stop = 0; #20;
	en = 0;			 clear = 0; stop = 0;
end
*/
