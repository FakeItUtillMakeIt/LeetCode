#pragma once

#include <thread>

#include <iostream>
#include <mutex>


using namespace std;

class Solution
{
public:
	

	static void print_block(int n, char c) {
		mtx.lock();
		for (int i = 0; i < n; i++)
		{
			cout << c;
		}
		cout << endl;
		mtx.unlock();
	}

	void do1() {
		std::thread th1(print_block,10,'1');
		std::thread th2(print_block, 10, '2');
		th1.join();
		th2.join();

	}

	static mutex mtx;
private:
};

mutex Solution::mtx;