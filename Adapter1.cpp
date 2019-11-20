#include <iostream>
using namespace std;

//����һ��Adaptee ԭ�е��� �ṩ3��ͷ 
class ThreePhaseOutlet
{
public:
	void doThreePhasePlugin()
	{
		cout<<"����ͷ���������ӿڵĲ�ۣ�"<<endl;
	}
};
//�������Target Ŀ����  �ܲ���2���ӿڣ��ǳ����� 
class TwoPhaseOutlet 
{
	 /*
	 *
     * ����ͷ 
     */
public:
	virtual void doPlugin() = 0;

};	
//
////������������������ת���� Adapter��ʹ�ö�̳�
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
//		cout<<"�����̳�������ת��,���ӿ�תΪ���ӿڣ�"<<endl;
//	}
//};

//��������������������ת���� Adapter
class OutletConvertor : public TwoPhaseOutlet  //�̳�Target 
{
public:
	OutletConvertor(ThreePhaseOutlet out) // �ٶ���һ���������Ĺ���������Ϊ����ֵ
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
		cout<<"��������������ת��,���ӿ�תΪ���ӿڣ�"<<endl;
	}
	ThreePhaseOutlet m_out;  // �������ж�����Ҫ������������
};
 
void work() {
        cout<<"�ʼǱ����Կ�ʼ����!"<<endl;
    }
//void recharge() {
//        // ʹ��2��ͷ 
//        TwoPhaseOutlet* outlet = new OutletConvertor();  // ����ֻ�ж���ͷ 
//        outlet->doPlugin();
//    }
void recharge() {
        // ʹ��2��ͷ 
        ThreePhaseOutlet tp;
        TwoPhaseOutlet* outlet = new OutletConvertor(tp);  // ����ֻ�ж���ͷ 
        outlet->doPlugin();
    }
int main() {
	work() ;
    recharge();
    
	return 0;
}
