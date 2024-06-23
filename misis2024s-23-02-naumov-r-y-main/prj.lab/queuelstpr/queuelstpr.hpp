#pragma once
#ifndef QUEUELSTPR_HPP
#define QUEUELSTPR_HPP

class QueueLstPr{
private:
	class Node{
	public:
		float val;
		Node* next = nullptr;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	QueueLstPr() = default;//
	QueueLstPr(const QueueLstPr& other);
	QueueLstPr(QueueLstPr&& other) noexcept;
	~QueueLstPr() noexcept;	//
	QueueLstPr& operator=(const QueueLstPr& other);
	QueueLstPr& operator=(QueueLstPr&& other) noexcept;
	bool IsEmpty() noexcept;//
	void Pop() noexcept;//
	void Push(const float& value);//
	float& Top();//
	void Clear() noexcept; //

};
#endif