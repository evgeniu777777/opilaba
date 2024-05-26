#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <fstream>
#include "../tablo/Input.cpp"
#include "../tablo/View.h"
#include "../tablo/Model.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TabloUnitTests
{
	
	TEST_CLASS(TabloUnitTests)
	{
		const char* name_file= ".test";
		
		char tablo[10000];
		char image[10000];
		int N, M;
		inline void write(const std::string& str) {
			std::ofstream f(name_file);
			f << str;
		}
		inline void Test(char error,int n,int m,bool res) {
			Assert::AreEqual((int)getInput(name_file,N,M,tablo,image),(int)error);
			if (error != ERR_SUCCESS)return;
			Assert::AreEqual(n, N);
			Assert::AreEqual(m, M);
			Assert::AreEqual(res, IsDislplayable(n, m, tablo, image));
		}
	public:
		TEST_METHOD(Yes)
		{
			int n = 3, m = 3; bool res = 1;
			write(std::to_string(n) + ' ' + std::to_string(m) + " R G B G . R B R G 7 7 7 7 7 7 7 7 7");
			Test(ERR_SUCCESS, n, m, res);
		}
		TEST_METHOD(No)
		{
			int n = 3, m = 3; bool res = 0;
			write(std::to_string(n) + ' ' + std::to_string(m) + " R G B G . R B R G 1 1 1 1 0 1 1 1 1");
			Test(ERR_SUCCESS, n, m, res);
		}
		TEST_METHOD(Min_NM)
		{
			int n = 1, m = 1; bool res = 1;
			write(std::to_string(n) + ' ' + std::to_string(m) + " G6");
			Test(ERR_SUCCESS, n, m, res);
		}
		TEST_METHOD(Max_NM)
		{
			int n = 100, m = 100; bool res = 1;
			std::string buffer;
			buffer.resize(2*n*m);
			for (int i = 0; i < n * m; ++i)buffer[i] = '.';
			for (int i = n * m; i < n*m*2; ++i)buffer[i] = '0';
			write(std::to_string(n) + ' ' + std::to_string(m) +' '+ buffer);
			Test(ERR_SUCCESS, n, m, res);
		}
		TEST_METHOD(Out_1_100_NM)
		{
			int n = 100, m = 101; bool res = 1;
			std::string buffer;
			buffer.resize(2 * n * m);
			for (int i = 0; i < n * m; ++i)buffer[i] = '.';
			for (int i = n * m; i < n * m * 2; ++i)buffer[i] = '0';
			write(std::to_string(n) + ' ' + std::to_string(m) + ' ' + buffer);
			Test(ERR_INCORRECT_SIZES, n, m, res);
		}
		TEST_METHOD(Float_NM)
		{
			int n = 3, m = 3; bool res = 0;
			write("3.001 1.1 R G B G . R B Z G 1 1 1 1 0 1 1 1 1");
			Test(ERR_INCORRECT_SIZES, n, m, res);
		}
		TEST_METHOD(Incorrect_input_img)
		{
			int n = 3, m = 3; bool res = 0;
			write(std::to_string(n) + ' ' + std::to_string(m) + " R G B G . R B Z G 1 1 1 1 0 1 1 1 1");
			Test(ERR_INCORRECT_INPUT, n, m, res);
		}
		TEST_METHOD(Incorrect_input_tablo)
		{
			int n = 3, m = 3; bool res = 0;
			write(std::to_string(n) + ' ' + std::to_string(m) + " R G B G . R B R G 1 1 1 8 0 1 1 1 1");
			Test(ERR_INCORRECT_INPUT, n, m, res);
		}
		TEST_METHOD(Incomplete_data)
		{
			int n = 3, m = 3; bool res = 0;
			write(std::to_string(n) + ' ' + std::to_string(m) + " R G B G . R B R 1 1 1 8 0 1 1 1");
			Test(ERR_INCORRECT_INPUT, n, m, res);
		}
		TEST_METHOD(File_not_exist)
		{
			Assert::AreEqual((int)getInput("non-existen.txt", N, M, tablo, image), (int)ERR_OPEN_FILE_FAIL);
		}
		
	};
}