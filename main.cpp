#include<iostream>
#include"AMGraph.h"
using namespace std;
int main()
{
	cout << "构造无向图" << endl;
	AMGraph udGraphy(8, UDG);
	udGraphy.Create();
	udGraphy.Display();
	return 0;
}