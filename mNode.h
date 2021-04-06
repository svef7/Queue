#pragma once
template <typename obj_type =int>
class mNode
{
public:
	obj_type data;
	mNode* next;
	mNode<obj_type>(obj_type _data, mNode* next=nullptr)
		: data(_data), next(_next) {}
};