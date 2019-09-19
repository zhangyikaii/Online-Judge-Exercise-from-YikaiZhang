/* NOTE: Those capitalized variable names in following code will be substituted by different actual names or values. */
static const int CODE_TRAN_ARRAY[128] = { 1, 3, 6, 9, 2 };
static const char DICT[56] = { 0 };

// Definitions of some other variables
typedef int(*CODER)(char*);

static int encode_1(char* str) {
	int i = 0, n = 6;
	for (i = 0; i < n; i++) {
		str[i] = DICT[str[i]];
		if (str[i]<0x20 || str[i] > 0x7E) 
			str[i] = ' ';
	}

	return n;
}
int transform_code(int code, int mode) {
	switch (CODE_TRAN_ARRAY[mode] != 0) {
	case 0:
		mode = 9;
		break;

	default: 
		break;
	}
	return code;
}