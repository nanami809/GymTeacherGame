#include <iostream>
#include <string>

using namespace std;

void main()
{
	int x, y, z;	
	int i;
	int num;//学生报数
	bool allright;
	do{
		cout << "请输入三个特殊数：" << endl<<"要求为3个不相等的个位数"<<endl<<"如果不符合要求会要求您重新输入"<<endl;
		cin >> x >> y >> z;
		allright = 1;
		if (x<0 || x>9 || y<0 || y>9|| z<0 || z>9)//如果x y z不是10以内单数
		{
			allright = 0;
		}
		if (x == y || x == z || y == z)//x y z 不是相同的数
		{
			allright = 0;
		}
	} while (!allright);
	string r[100];//用字符串存储答案

	for (num =1; num < 101; num++)
	{
		char buff[3];
		char b[1];
		bool includex=0;
		bool  xm = 0, ym = 0, zm = 0;
		itoa(num, buff, 10);
		string temp = buff;
		int len = temp.length();
		for (i = 0; i < len; i++)
		{
			itoa(x, b, 10);
			string t = b;
			if (temp[i] == t[0])
			{
				r[num - 1] = "Fizz";
				cout << r[num - 1] << endl;
				includex = 1;
				break;
			}
		}
		if (!includex)
		{
			if (num / x > 0 && num%x == 0) xm = 1;
			if (num / y > 0 && num%y == 0) ym = 1;
			if (num / z > 0 && num%z == 0) zm = 1;

			if (xm&&ym&&zm){
				r[num - 1] = "FizzBuzzWhizz";
				cout << r[num - 1] << endl;
			}
			else if (xm&&ym&&!zm){
				r[num - 1] = "FizzBuzz";
				cout << r[num - 1] << endl;
			}
			else if (xm&&!ym&&zm){
				r[num - 1] = "FizzWhizz";
				cout << r[num - 1] << endl;
			}
			else if (xm&&!ym&&!zm){
				r[num - 1] = "Fizz";
				cout << r[num - 1] << endl;
			}
			else if (!xm&&ym&&!zm){
				r[num - 1] = "Buzz";
				cout << r[num - 1] << endl;
			}
			else if (!xm&&ym&&zm){
				r[num - 1] = "BuzzWhizz";
				cout << r[num - 1] << endl;
			}
			else if (!xm&&!ym&&zm){
				r[num - 1] = "Whizz";
				cout << r[num - 1] << endl;
			}
			else if (!xm&&!ym&&!zm){
				r[num - 1] = temp;
				cout << r[num - 1] << endl;
			}
		}
	}
	cout << "谢谢参与！";
	cin >> num;
}
