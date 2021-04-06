#pragma once
#include "mNode.h"
#include <iostream>
using namespace std;
template <typename obj_type = int >
class mQueue
{
	typedef  mNode<obj_type> sNode;
	typedef  mNode<obj_type>* pNode;
	pNode mFirst = nullptr, mLast = nullptr;
public:
	mQueue() {}
	mQueue(const mQueue& obj)
	{
		if (this != obj)
		{
			if (obj.empty())
			{
				mFirst = nullptr;
				mLast = nullptr;
			}
			else
			{
				mFirst = mLast = new sNode(obj.front());
				pNode curr = obj.mFirst->next;
				while (curr != nullptr)
				{
					mLast->next = new sNode(curr->data);
					mLast = mLast->next;
					curr = curr->next;
				}
			}
		}
	}

	~mQueue()
	{
		pNode first = mFirst, last;
		do
		{
			last = first->next;
			delete first;
			first = last;
		} while (last != nullptr)

	}
	bool empty() const
	{
		return mFirst == nullptr;
	}
	obj_type front() const
	{
		if (!empty())
		{
			return mFirst->data;
		}
		cout << "Queue is empty!";
		obj_type* ptr = new obj_type;
		obj_typetmp = *ptr;
		delete ptr;
		return tmp;
	}
	void push(const obj_type& val)
	{
		pNode tmp = new sNode(val);
		if (empty())
		{
			mFirst = mLast = tmp;
		}
		else
		{
			mLast->next = tmp;
			mLast = tmp;
		}
		delete tmp;
	}
	void pop()
	{
		if (empty())
		{
			cout << "Queue is empty!";
			return;
		}
		pNode ptr = mFirst;
		mFirst = mFirst->next;
		delete ptr;
		if (mFirst == nullptr)
			mLast = nullptr;
	}
	friend ostream& operator<<(ostream& out, const mQueue& obj)
	{
		if (obj.empty())
			out << "Queue is empty!\n"
		else
		{
			for (pNode ptr = obj.mFirst; ptr != nullptr; ptr=ptr->next)
				out << ptr->data << " ";
		}
		out << endl;
	}
	return out;
};