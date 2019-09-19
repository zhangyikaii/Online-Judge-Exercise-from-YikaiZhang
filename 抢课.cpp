#include <iostream>
#include <cstring>
#include<ctime>
#include <winsock2.h>
#include <Windows.h>
#include <string>
#define max 20480

using namespace std;
#pragma comment(lib, "ws2_32.lib")

// 全局变量
char host[500] = "elite.nju.edu.cn";
char buf[1024];

int num = 1;
string allHtml;

int ignoreTimes = 1;     // 设置消息接收频率，目前默认每发送1000次接受一次
SOCKET sock;

bool isLogin = false;
bool isCookie = false;

int main_time;
int init_sec;     // 计时开始的初始时间 
int tot_sec;     // 耗时
int tot_sec_main;     // 耗时

char recv_buf[1024];


// "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n"
// "Accept-Encoding:gzip, deflate\r\n"
// "Accept-Language: zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7\r\n"
// "Cache-Control: max-age=0\r\n"
// "Connection: keep-alive\r\n"
// "Content-Length: 67\r\n"
// "Content-Type: application/x-www-form-urlencoded\r\n"
// "Cookie: JSESSIONID=8166CA185A2D3E197370FC0B6B4852DD; UM_distinctid=166167048ea18a-0c681cdffbfd1-9393265-144000-166167048eb5bf; yunsuo_session_verify=1649c2fee6397754b2ff79c214ab3a70; ARRAffinity=6fa7b13373a5ee8e6661f236243ccce8c95be8601d00a2d65967e5835fbd0d3e; user_id="171840708 1551077278257"\r\n"
// "Host: elite.nju.edu.cn\r\n"
// "Origin: http://elite.nju.edu.cn\r\n"
// "Referer: http://elite.nju.edu.cn/jiaowu/\r\n"
// "Upgrade-Insecure-Requests: 1\r\n"
// "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36\r\n"


// 登录请求(Request Headers)
string request_login =
"POST / jiaowu / login.do HTTP / 1.1\r\n"
"Host: elite.nju.edu.cn\r\n"
"Connection: keep-alive\r\n"
"Content-Length: 67\r\n"
"Cache-Control: max-age=0\r\n"
"Origin: http://elite.nju.edu.cn\r\n"
"Upgrade-Insecure-Requests: 1\r\n"
"Content-Type: application/x-www-form-urlencoded\r\n"
"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36\r\n"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n"
"Referer: http://elite.nju.edu.cn/jiaowu/exit.do\r\n"
"Accept-Encoding: gzip, deflate\r\n"
"Accept-Language: zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7\r\n"
"Cookie: JSESSIONID=273B456DB8E016B1117B54F73D957619; UM_distinctid=166167048ea18a-0c681cdffbfd1-9393265-144000-166167048eb5bf; yunsuo_session_verify=1649c2fee6397754b2ff79c214ab3a70; ARRAffinity=6fa7b13373a5ee8e6661f236243ccce8c95be8601d00a2d65967e5835fbd0d3e; user_id=\"171840708 1551080348234\"\r\n"
"\r\n"
"\r\n"
"userName=171840708&password=Zyk666&returnUrl=null&ValidateCode=";

//// 进入选课界面的请求信息(Request Headers)
//string request_choose_course =
//"GET /jiaowu/student/elective/courseList.do?method=openRenewCourseList HTTP/1.1"
//"Host: elite.nju.edu.cn"
//"Connection: keep-alive"
//"Upgrade-Insecure-Requests: 1"
//"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36"
//"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8"
//"Referer: http://elite.nju.edu.cn/jiaowu/student/select/renewindex.do"
//"Accept-Encoding: gzip, deflate"
//"Accept-Language: zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7"
//"Cookie: JSESSIONID=99DF30261CFD17CEA9D386C2E09AC3A0; UM_distinctid=166167048ea18a-0c681cdffbfd1-9393265-144000-166167048eb5bf; yunsuo_session_verify=1649c2fee6397754b2ff79c214ab3a70; ARRAffinity=6fa7b13373a5ee8e6661f236243ccce8c95be8601d00a2d65967e5835fbd0d3e; user_id=\"171840708 1551080348234\"";

string request_choose_course =
"GET /jiaowu/student/elective/courseList.do?method=openRenewCourse&campus=%E5%85%A8%E9%83%A8%E6%A0%A1%E5%8C%BA&academy=12 HTTP/1.1"
"Host: elite.nju.edu.cn"
"Connection: keep-alive"
"Upgrade-Insecure-Requests: 1"
"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8"
"Referer: http://elite.nju.edu.cn/jiaowu/student/elective/courseList.do?method=openRenewCourseList"
"Accept-Encoding: gzip, deflate"
"Accept-Language: zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7"
"Cookie: JSESSIONID=99DF30261CFD17CEA9D386C2E09AC3A0; UM_distinctid=166167048ea18a-0c681cdffbfd1-9393265-144000-166167048eb5bf; yunsuo_session_verify=1649c2fee6397754b2ff79c214ab3a70; ARRAffinity=6fa7b13373a5ee8e6661f236243ccce8c95be8601d00a2d65967e5835fbd0d3e; user_id=\"171840708 1551080348234\"";

// 要抢的课：编译原理
string request_compilers_principles = "";


// 抢课
void grabCourse(){
	/*启动Winsock*/
	WSADATA wd;
	WSAStartup(MAKEWORD(2, 2), &wd);
	// SOCKET temp = socket(AF_INET, SOCK_STREAM, 0);  

	/*创建socket*/
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET){
		cout << "建立socket失败！ 错误码： " << WSAGetLastError() << endl;
		return;
	}

	/*绑定：将本地地址 附加到 套接字上 以便能够有效地标识套接字*/
	sockaddr_in sa = { AF_INET };    // 套接字地址，AF _!NET ，表示该socket位于Internet域；
	int n = bind(sock, (sockaddr*)&sa, sizeof(sa));
	if (n == SOCKET_ERROR){
		cout << "绑定失败！ 错误码： " << WSAGetLastError() << endl;
		return;
	}

	hostent *p = gethostbyname(host);
	if (p == NULL) {
		cout << "主机无法解析出ip! 错误代码： " << WSAGetLastError() << endl;
		return;
	}
	sa.sin_port = htons(80);
	memcpy(&sa.sin_addr, p->h_addr, 4);//    with some problems ???

	/*连接：当客户机要与网络中的服务器建立连接时，需要调用connect 函数*/
	n = connect(sock, (sockaddr*)&sa, sizeof(sa));
	if (n == SOCKET_ERROR)	{
		cout << "连接失败！ 错误码： " << WSAGetLastError() << endl;
		return;
	}

	if (isLogin == false){
		/*登录教务系统*/
		if (isCookie == false){
			isCookie = true;
		}

		string verification_code = "";                    // 验证码
		cout << "请输入验证码: ";
		cin >> verification_code;

		string request_login_full = request_login + verification_code;

		cout << "开始将登录请求(Request Headers)发送至对方服务器..." << endl;
		if (send(sock, request_login_full.c_str(), request_login_full.size(), 0) == SOCKET_ERROR){
			cout << "发送失败! 错误代码： " << WSAGetLastError() << endl;
			closesocket(sock);
			return;
		}
		else{
			cout << "发送成功!" << endl;
		}

		recv(sock, buf, sizeof(buf)-1, 0);
		cout << "以下是服务器的响应信息(Response Headers)" << endl;
		printf("%s", buf);
		cout << endl;


		/*进入选课系统*/
		cout << "开始将进入选课界面的请求信息(Request Headers)发送至对方服务器..." << endl;
		if (send(sock, request_choose_course.c_str(), request_choose_course.size(), 0) == SOCKET_ERROR){
			cout << "发送失败! 错误代码： " << WSAGetLastError() << endl;
			closesocket(sock);
			return;
		}
		else{
			cout << "发送成功!" << endl;
		}

		if (recv(sock, buf, sizeof(buf)-1, 0) > 0){
			cout << endl << "以下是服务器的响应信息(Response Headers)" << endl;
			printf("%s", buf);
			cout << endl;
		}


		// system("pause");
		isLogin = true;
	}

	// 开始抢课
	init_sec = time(0);   // 计时开始
	int count_num = 0;

	/*循环抢课*/
	while (true){
		// 每一次都重新建立连接
		SOCKET temp = socket(AF_INET, SOCK_STREAM, 0);
		sock = temp;
		if (sock == INVALID_SOCKET){
			cout << "建立socket失败！ 错误代码： " << WSAGetLastError() << endl;
			return;
		}

		sockaddr_in sa = { AF_INET };

		struct hostent *p = gethostbyname(host);
		if (p == NULL){
			cout << "主机无法解析出ip! 错误代码： " << WSAGetLastError() << endl;
			return;
		}
		sa.sin_port = htons(80);
		memcpy(&sa.sin_addr, p->h_addr, 4);

		/*连接：当客户机要与网络中的服务器建立连接时，需要调用connect 函数*/
		n = connect(sock, (sockaddr*)&sa, sizeof(sa));
		if (n == SOCKET_ERROR)	{
			cout << "连接失败！ 错误代码： " << WSAGetLastError() << endl;
			return;
		}

		count_num++;
		tot_sec = time(0) - init_sec;
		tot_sec_main = time(0) - main_time;

		// 抢课：编译原理
		cout << "开始将编译原理选课请求(Request Headers)发送至对方服务器..." << endl;
		if (send(sock, request_compilers_principles.c_str(), request_compilers_principles.size(), 0) == SOCKET_ERROR){
			cout << "发送失败! 错误代码： " << WSAGetLastError() << endl;
			grabCourse();  // 递归

			return;
		}
		else{
			cout << "发送成功" << endl;
		}

		if (count_num % ignoreTimes == 0){
			if (recv(sock, recv_buf, sizeof(recv_buf)-1, 0) > 0){
				cout << endl << "以下是服务器的响应信息(Response Headers)" << endl;
				printf("%s", recv_buf);
			}
		}

		cout << "程序运行总计时长(单位：秒)：" << tot_sec_main << endl;
		cout << "本次循环时长(单位：秒)：" << tot_sec << endl;
		cout << "执行次数：" << count_num << endl;
		cout << "平均每秒执行次数：" << (double)count_num / tot_sec << endl;

		closesocket(temp);
	}
}

int main(){
	main_time = time(0);  // 开始计时
	grabCourse();
	// system("pause");
	return 0;
}
