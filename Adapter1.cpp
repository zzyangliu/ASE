#include <iostream>
using namespace std;

//步骤一：Adaptee 原有的类 提供3接头 
class ThreePhaseOutlet
{
public:
	void doThreePhasePlugin()
	{
		cout<<"三插头插入两个接口的插槽！"<<endl;
	}
};
//步骤二：Target 目标类  能插入2个接口，是抽象类 
class TwoPhaseOutlet 
{
	 /*
	 *
     * 两插头 
     */
public:
	virtual void doPlugin() = 0;

};	
//
////步骤三：类适配器，转换类 Adapter，使用多继承
//class OutletConvertor: public TwoPhaseOutlet,public ThreePhaseOutlet
//{
//public:
//	void doPlugin()
//	{
//		doConvertor();
//		doThreePhasePlugin();
//	}	
//        void doConvertor()
//	{
//		cout<<"借助继承适配器转化,三接口转为两接口！"<<endl;
//	}
//};

//步骤三：对象适配器，转换类 Adapter
class OutletConvertor : public TwoPhaseOutlet  //继承Target 
{
public:
	OutletConvertor(ThreePhaseOutlet out) // 再定义一个带参数的构造器用来为对象赋值
	{
		m_out = out;
	}
	void doPlugin()
	{
		doConvertor();
		m_out.doThreePhasePlugin();  
	}
	void doConvertor()
	{
		cout<<"借助对象适配器转化,三接口转为两接口！"<<endl;
	}
	ThreePhaseOutlet m_out;  // 适配器中定义需要适配的适配对象
};
 
void work() {
        cout<<"笔记本电脑开始工作!"<<endl;
    }
//void recharge() {
//        // 使用2插头 
//        TwoPhaseOutlet* outlet = new OutletConvertor();  // 现在只有二插头 
//        outlet->doPlugin();
//    }
void recharge() {
        // 使用2插头 
        ThreePhaseOutlet tp;
        TwoPhaseOutlet* outlet = new OutletConvertor(tp);  // 现在只有二插头 
        outlet->doPlugin();
    }
int main() {
	work() ;
    recharge();
    
	return 0;
}
