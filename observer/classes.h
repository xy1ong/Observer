#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
class Observer;
class Account {
public:
	Account(int);
	~Account() {}

	void addObserver(Observer *);
	void save(int);
	void withdraw(int);
private:
	vector<Observer *> vp;
	//vector<Observer *>::iterator it;
	int rmb;

};
class Observer {
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void msgs(int, int) = 0;
	virtual void msgw(int, int) = 0;
};
class Mobile :public Observer {
public:
	Mobile() :Observer() {}
	~Mobile() {}
	void msgs(int, int);
	void msgw(int, int);
};
class QQ :public Observer {
public:
	QQ() :Observer() {}
	~QQ() {}
	void msgs(int, int);
	void msgw(int, int);
};


