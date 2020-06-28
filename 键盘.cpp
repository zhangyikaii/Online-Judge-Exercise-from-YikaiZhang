/*

module ram(code, addr);
	input [7:0] code;
	output reg [7:0] addr;
	reg [7:0] ram [255:0];

	initial
	begin
		$readmemh("C:/Users.......", ram, 0, 255);
	end

	always
	begin
		addr = ram[code];
	end
endmodule



module light(h, l, flag, segh, segl);
	input flag;
	input [3:0] h;
	input [3:0] l;
	output reg [6:0] segh;
	output reg [6:0] segl;

	always
	begin
		if(flag)
		begin
			case(h)
			0: segh = 7'b1000000;
			1: segh = 7'b1111001;
			2: segh = 7'b0100100;
			3: segh = 7'b0110000;
			4: segh = 7'b0011001;
			5: segh = 7'b0010010;
			6: segh = 7'b0000010;
			7: segh = 7'b1111000;
			8: segh = 7'b0000000;
			9: segh = 7'b0010000;
			10: segh = 7'b0001000;
			11: segh = 7'b0000011;
			12: segh = 7'b1000110;
			13: segh = 7'b0100001;
			14: segh = 7'b0000110;
			15: segh = 7'b0001110;
			endcase
			case(l)
			0: segl = 7'b1000000;
			1: segl = 7'b1111001;
			2: segl = 7'b0100100;
			3: segl = 7'b0110000;
			4: segl = 7'b0011001;
			5: segl = 7'b0010010;
			6: segl = 7'b0000010;
			7: segl = 7'b1111000;
			8: segl = 7'b0000000;
			9: segl = 7'b0010000;
			10: segl = 7'b0001000;
			11: segl = 7'b0000011;
			12: segl = 7'b1000110;
			13: segl = 7'b0100001;
			14: segl = 7'b0000110;
			15: segl = 7'b0001110;
			endcase
		end
		else
		begin
			segh = 7'b1111111;
			segl = 7'b1111111;
		end
	end

endmodule


module ps2_keyboard(clk, clrn, ps2_clk,ps2_data,data, ready, nextdata_n, overflow);
	input clk,clrn,ps2_clk,ps2_data;
	input nextdata_n;
	output [7:0] data;
	output reg ready;
	output reg overflow; // fifo overflow
	// internal signal, for test
	reg [9:0] buffer; // ps2_data bits
	reg [7:0] fifo[7:0]; // data fifo
	reg [2:0] w_ptr,r_ptr; // fifo write and read pointers
	reg [3:0] count; // count ps2_data bits
	// detect falling edge of ps2_clk
	reg [2:0] ps2_clk_sync;

	always @(posedge clk) begin
		ps2_clk_sync <= {ps2_clk_sync[1:0],ps2_clk};
	end

	wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

	always @(posedge clk) begin
		if (clrn == 0) begin // reset
			count <= 0; w_ptr <= 0; r_ptr <= 0;
			overflow <= 0; ready<= 0;
		end else if (sampling) begin
		
		if (count == 4'd10) begin
			if ((buffer[0] == 0) && // start bit
				(ps2_data) && // stop bit
				(^buffer[9:1])) begin // odd parity
				fifo[w_ptr] <= buffer[8:1]; // kbd scan code
				w_ptr <= w_ptr+3'b1;
				ready <= 1'b1;
				overflow <= overflow | (r_ptr == (w_ptr + 3'b1));
			end
			count <= 0; // for next
		end else begin
			buffer[count] <= ps2_data; // store ps2_data
			count <= count + 3'b1;
		end
	end
	if ( ready ) begin // read to output next data
		if(nextdata_n == 1'b0) begin //read next data
			r_ptr <= r_ptr + 3'b1;
			if(w_ptr==(r_ptr+1'b1)) //empty
				ready <= 1'b0;
			end
		end
	end

	assign data = fifo[r_ptr]; //always set output data

endmodule


module key_board8(clk, clrn, ps2_clk, ps2_data, seg0, seg1, segm0, segm1, segh0, segh1, flag, flag2);

	input clk, clrn, ps2_clk, ps2_data;
	wire [7:0] data_asc;
	wire [7:0] data_code;
	wire ready;
	wire overflow;

	reg [7:0] data_p;
	reg [7:0] count = 0; // an le duoshao ci

	output reg flag = 1;   // judge keyboard-button is valid or not
	output reg flag2 = 1;

	output [6:0] seg0;
	output [6:0] seg1;
	output [6:0] segm0;
	output [6:0] segm1;
	output [6:0] segh0;
	output [6:0] segh1;

	reg all = 1;

	reg [6:0] count_clk = 0;
	reg clk_b = 0;
	always @(posedge clk)
	begin
		if(count_clk == 100)
		begin
			count_clk <= 0;
			clk_b <= ~clk_b;
		end
		else
			count_clk <= count_clk + 1;
	end


	reg nextdata_n2;
	ps2_keyboard S(.clk(clk), .clrn(clrn), .ps2_clk(ps2_clk), .ps2_data(ps2_data), .data(data_code), .ready(ready), .nextdata_n(nextdata_n2), .overflow(overflow))

	light L1(.h(count[7:4]), .l(count[3:0], .flag(all), .segh(segh1), .segl(segh0));
	light L2(.h(data_asc[7:4]), .l(data_asc[3:0]), .flag(all), .segh(segh1), .segl(segh0));
	light L3(.h(data_p[7:4], .l(data_p[3:0]), .flag(flag), .segh(seg1), .segl(seg0));

	always @(posedge clk_b)
	begin
		if (ready)
		begin
			if(data_code != 8'hf0 && flag2)
			begin
				data_p <= data_code;
				flag2 <= 1;
				flag <= 1;
			end
			else if (data_code == 8'hf0)
			begin
				data_p <= data_code;
				count <= count + 1;
				flag <= 0;
				flag2 <= 0;
			end
			else if(!flag2)
			begin
				data_p <= data_code;
				flag2 <= 1;
				flag <= 0;
			end

			nextdata_n2 <= 0;
		end
		else
		begin
			nextdata_n2 <= 1;
		end
	end
endmodule






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


To, Location

Q[7],PIN_AF24
Q[6],PIN_AE24
Q[5],PIN_AF25
Q[4],PIN_AG25
Q[3],PIN_AD24
Q[2],PIN_AC23
Q[1],PIN_AB23
Q[0],PIN_AA24
choose[2], PIN_AA15
choose[1], PIN_AA14
choose[0], PIN_AK4
clk, PIN_AJ4
data_in[7],PIN_AD30
data_in[6], PIN_AC28
data_in[5], PIN_V25
data_in[4], PIN_W25
data_in[3], PIN_AC30
data_in[2], PIN_AB28
data_in[1], PIN_Y27
data_in[0], PIN_AB30
en, PIN_AA30


To, Location

clk, PIN_AF14
clrn, PIN_AC29
ps2_clk, PIN_AB25
ps2_data, PIN_AA25
segh0[6], PIN_AH22
segh0[5], PIN_AF23
segh0[4], PIN_AG23
segh0[3], PIN_AE23
segh0[2], PIN_AE22
segh0[1], PIN_AG22
segh0[0], PIN_AD21

segh1[6], PIN_AB21
segh1[5], PIN_AF19
segh1[4], PIN_AE19
segh1[3], PIN_AG20
segh1[2], PIN_AF20
segh1[1], PIN_AG21
segh1[0], PIN_AF21

segm1[6], PIN_AD20
segm1[5], PIN_AA19
segm1[4], PIN_AC20
segm1[3], PIN_AA20
segm1[2], PIN_AD19
segm1[1], PIN_W19
segm1[0], PIN_Y19

segm0[6], PIN_W16
segm0[5], PIN_AF18
segm0[4], PIN_Y18
segm0[3], PIN_Y17
segm0[2], PIN_AA18
segm0[1], PIN_AB17
segm0[0], PIN_AA21


seg0[6], PIN_AH18
seg0[5], PIN_AG18
seg0[4], PIN_AH17
seg0[3], PIN_AG16
seg0[2], PIN_AG17
seg0[1], PIN_V18
seg0[0], PIN_W17
seg1[6], PIN_V17
seg1[5], PIN_AE17
seg1[4], PIN_AE18
seg1[3], PIN_AD17
seg1[2], PIN_AE16
seg1[1], PIN_V16
seg1[0], PIN_AF16






*/