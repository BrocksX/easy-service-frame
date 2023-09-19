#include <string>
#include <iostream>
#include "rpc.h"

struct foo {
	int add(int a, int b) { return a + b; }
};

std::string Strcat(std::string s1, int n) 
{
    return s1 + std::to_string(n);
}

int main()
{
	rpc server;
	server.as_server(5555);
	foo f;
	server.regist("add", &foo::add, &f);  //注册类成员函数
	server.regist("Strcat", Strcat);      //注册普通函数
	server.run();
	return 0;
}