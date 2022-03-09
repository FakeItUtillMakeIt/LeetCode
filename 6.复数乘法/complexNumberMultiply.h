#include <iostream>


using namespace std;

class Solution {
public:
	string complexNumberMultiply(string num1, string num2) {
		char** data1=new char*[2];
		char** data2 = new char* [2];
		char** pch1 = new char* [2];
		char** pch2 = new char* [2];
		pch1[0] = strtok_s((char*)num1.c_str(), "+ i",data1);
		pch2[0] = strtok_s((char*)num2.c_str(), "+ i", data2);
		int i = 0;
		cout << pch1[i] << "\t\t" << pch2[i] << endl;
		i++;
		pch1[1] = strtok_s(data1[0], "i", data1);
		pch2[1] = strtok_s(data2[0], "i", data2);
		cout << pch1[i] << "\t\t" << pch2[i] << endl;
		
		int truth = 0;
		int comple = 0;
		truth = atoi(pch1[0]) * atoi(pch2[0]) -( atoi(pch1[1]) * atoi(pch2[1]));
		comple = atoi(pch1[0]) * atoi(pch2[1]) + atoi(pch1[1]) * atoi(pch2[0]);

		char* truthBuf = new char[10];
		char* compleBuf = new char[10];
		/*_itoa_s(truth, truthBuf,10, 10);
		_itoa_s(comple, compleBuf, 10,10);*/
		sprintf_s(truthBuf,10, "%d", truth);
		sprintf_s(compleBuf, 10,"%d", comple);

		string num = "";
		num.append(truthBuf);
		num.append("+");
		num.append(compleBuf);
		num.append("i");
		return num;
	}
};