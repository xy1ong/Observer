// observer.cpp : 定义控制台应用程序的入口点。
//

#include "classes.h"

int main()
{
	Account account(1000);		// 银行开户，并存入1000元
	Mobile mobile;				// 手机对象
	account.addObserver(&mobile);	// 在银行账号中注册手机
	QQ qq;						// QQ对象
	account.addObserver(&qq);	// 在银行账号中注册QQ
	cout << "存入200元->" << endl;
	Sleep(2000);
	account.save(200);			// 存200元
	cout << "取出800元<-" << endl;
	Sleep(2000);
	account.withdraw(800);		// 取800元
	cout << "尝试取出1000元<-" << endl;
	Sleep(2000);
	account.withdraw(1000);		// 尝试取出1000元，因为余额已只有400元，1000>400，则消息提示“取出400元”
	Sleep(1000);
	return 0;
}
