/*
module v_rams_8 (clk, we, inaddr, outaddr, din, dout0, dout1, dout2);
input clk;
input we;
input [2:0] inaddr;
input [2:0] outaddr;
input [7:0] din;
output [7:0] dout0, dout1, dout2;

reg [7:0] ram [7:0];
reg [7:0] dout0, dout1;
第一个实现代码:

initial
begin
ram[7] = 8'hf0; ram[6] = 8'h23; ram[5] = 8'h20; ram[4] = 8'h50;
ram[3] = 8'h03; ram[2] = 8'h21; ram[1] = 8'h82; ram[0] = 8'h0D;

always @(posedge clk)
begin
	if(we)
		ram[inaddr] <= din;
	else
		dout0 <= ram[outaddr];
end
always @(negedge clk)
begin
	if (!we)
		dout1 <= ram[outaddr];
end
assign dout2 = ram[outaddr];
endmodule


测试代码:
initial
begin
	we = 0; clk = 0; inaddr = 3'b000; din = 8'b00000000; outaddr = 3'b000; #3;
	outaddr = 3'b001; #3;
	outaddr = 3'b010; #3;
	outaddr = 3'b011; #3;
	outaddr = 3'b100; #3;
	outaddr = 3'b101; #3;
	outaddr = 3'b110; #3;
	outaddr = 3'b111; #3;
end
always
begin
	#1 clk = ~clk;
end
endmodule


第二个实现代码:
module ram1(clk, we, inaddr, outaddr, din, dout);
input clk;
input we;
input [3:0] inaddr;
input [3:0] outaddr;
input [7:0] din;
output reg [7:0] dout;

reg [7:0] ram [15:0];

initial
begin
	$readmemh("F:/shudianxiangmu/7/3/mem1.txt", ram, 0, 15);
end

always @(posedge clk)
begin
	if (we)
		ram[inaddr] <= din;
	else
		dout <= ram[outaddr];
	end

endmodule

module ram(clk, we, inoutaddr, din, dout1, dout2);
	input clk;
	input we;
	input [3:0] inoutaddr;
	wire [3:0] addr;
	input [7:0] din;
	output [7:0] dout1;
	output [7:0] dout2;
	assign addr = inoutaddr;
	ram1 S(.clk(clk), .we(we), .inaddr(inoutaddr), .outaddr(addr), .din(din), .dout(dout1));
	ram2 A(.clock(clk), .data(din), .wren(we), .wraddress(inoutaddr), .rdaddress(addr), .q(dout2));
endmodule

begin
	// 读数据验证存储器初始化.
	we = 0; clk = 0; din = 8'b00000000; inoutaddr = 4'b0000; #5;
	inoutaddr = 4'b0001; #5;
	inoutaddr = 4'b0010; #5;
	inoutaddr = 4'b0011; #5;
	inoutaddr = 4'b0100; #5;
	inoutaddr = 4'b0101; #5;
	inoutaddr = 4'b0110; #5;
	inoutaddr = 4'b0111; #5;
	inoutaddr = 4'b1000; #5;
	inoutaddr = 4'b1001; #5;
	inoutaddr = 4'b1010; #5;
	inoutaddr = 4'b1011; #5;
	inoutaddr = 4'b1100; #5;
	inoutaddr = 4'b1101; #5;
	inoutaddr = 4'b1110; #5;
	inoutaddr = 4'b1111; #5;

	// 修改存储器里面的内容
	we = 1; din = 8'b11111111; #5;
	inoutaddr = 4'b0001; #5;
	inoutaddr = 4'b0010; #5;
	inoutaddr = 4'b0011; #5;
	inoutaddr = 4'b0100; #5;
	inoutaddr = 4'b0101; #5;
	inoutaddr = 4'b0110; #5;
	inoutaddr = 4'b0111; #5;
	inoutaddr = 4'b1000; #5;
	inoutaddr = 4'b1001; #5;
	inoutaddr = 4'b1010; #5;
	inoutaddr = 4'b1011; #5;
	inoutaddr = 4'b1100; #5;
	inoutaddr = 4'b1101; #5;
	inoutaddr = 4'b1110; #5;
	inoutaddr = 4'b1111; #5;

	// 再读存储器修改后的内容.
	we = 0; #5;
	inoutaddr = 4'b0001; #5;
	inoutaddr = 4'b0010; #5;
	inoutaddr = 4'b0011; #5;
	inoutaddr = 4'b0100; #5;
	inoutaddr = 4'b0101; #5;
	inoutaddr = 4'b0110; #5;
	inoutaddr = 4'b0111; #5;
	inoutaddr = 4'b1000; #5;
	inoutaddr = 4'b1001; #5;
	inoutaddr = 4'b1010; #5;
	inoutaddr = 4'b1011; #5;
	inoutaddr = 4'b1100; #5;
	inoutaddr = 4'b1101; #5;
	inoutaddr = 4'b1110; #5;
	inoutaddr = 4'b1111; #5;
end
always
begin
	#4 clk = ~clk;
end
endmodule


// 主要是两个地址输入的要分开来引脚要分开 在memo.v里面改.
To, Location
clk, PIN_AJ4
din[0], PIN_AB30
din[1], PIN_Y27
inoutaddr[0], PIN_AB28
inoutaddr[1], PIN_AC30
inoutaddr[2], PIN_W25
inoutaddr[3], PIN_V25

inoutadd0[0], PIN_AC28
inoutadd0[1], PIN_AD30
inoutadd0[2], PIN_AC29
inoutadd0[3], PIN_AA30

dout1[3], PIN_AC22
dout1[2], PIN_AB22
dout1[1], PIN_AF24
dout1[0], PIN_AE24

dout2[3], PIN_AD24
dout2[2], PIN_AC23
dout2[1], PIN_AB23
dout2[0], PIN_AA24

we, PIN_AK4




*/