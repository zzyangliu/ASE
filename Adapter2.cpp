#include<iostream>
using namespace std;
 
//����һ�� Target
class Target { 
public:
	virtual void f1(){}; 
	virtual void f2(){}; 
	virtual void f3(){};   
};
 
// ���������������ɫ 
class DefaultAdapter : public Target 
{ 
public:
    void f1() { 
    } 
 
    void f2() { 
    } 
 
    void f3() { 
    } 
};
 
class MyInteresting :public DefaultAdapter
{ 
public:
     void f3(){       
		cout<<"ֻҪf3()������"<<endl;
    } 
};
 
int main()
{
	// Create adapter and place a request
	Target *t = new MyInteresting();
	t->f3();
 
	return 0;
}
