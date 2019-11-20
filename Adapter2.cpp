#include<iostream>
using namespace std;
 
//步骤一： Target
class Target { 
public:
	virtual void f1(){}; 
	virtual void f2(){}; 
	virtual void f3(){};   
};
 
// 步骤二：适配器角色 
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
		cout<<"只要f3()方法！"<<endl;
    } 
};
 
int main()
{
	// Create adapter and place a request
	Target *t = new MyInteresting();
	t->f3();
 
	return 0;
}
