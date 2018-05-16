#include "classes.h"
Account::Account(int _rmb)
{
	rmb = _rmb;
}
void Account::addObserver(Observer *op)
{
	vp.push_back(op);

}
void Account::save(int _sr)
{
	rmb += _sr;
	for (vector<Observer *>::iterator it = vp.begin(); it != vp.end(); it++)
	{
		(*it)->msgs(_sr, rmb);
	}
}
void Account::withdraw(int _wr)
{
	if (_wr>rmb)
	{
		_wr = rmb;
		rmb = 0;
	}
	else
		rmb -= _wr;
	for (vector<Observer *>::iterator it = vp.begin(); it != vp.end(); it++)
	{
		(*it)->msgw(_wr, rmb);
	}
}

void Mobile::msgs(int _ms, int _mr)
{
	cout << "收到短消息：存入" << _ms << "元，" << "余额" << _mr << "元；" << endl;
}
void Mobile::msgw(int _mw, int _mr)
{
	cout << "收到短消息：取出" << _mw << "元，" << "余额" << _mr << "元；" << endl;
}

void QQ::msgs(int _qs, int _qr)
{
	cout << "收到QQ消息：存入" << _qs << "元，" << "余额" << _qr << "元；" << endl;
}
void QQ::msgw(int _qw, int _qr)
{
	cout << "收到QQ消息：取出" << _qw << "元，" << "余额" << _qr << "元；" << endl;
}
