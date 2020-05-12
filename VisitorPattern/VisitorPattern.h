#pragma once

#include <iostream>
#include <vector>

using namespace std;

class ComputerPartVisitor;

class ComputerPart
{
public:
	virtual void accept(ComputerPartVisitor* _ComputerPartVisitor) = 0;
};

class Keyboard : public ComputerPart
{
public:
	virtual void accept(ComputerPartVisitor* _ComputerPartVisitor);
};

class Mouse : public ComputerPart
{
public:
	virtual void accept(ComputerPartVisitor* _ComputerPartVisitor);
};

class Monitor : public ComputerPart
{
public:
	virtual void accept(ComputerPartVisitor* _ComputerPartVisitor);
};

class Computer : public ComputerPart
{
public:
	Computer();
	virtual void accept(ComputerPartVisitor* _ComputerPartVisitor);
private:
	vector<ComputerPart*> m_parts;
};




class ComputerPartVisitor
{
public:
	virtual void visit(Keyboard *keyboard) = 0;
	virtual void visit(Mouse *mouse) = 0;
	virtual void visit(Monitor *monitor) = 0;
	virtual void visit(Computer *computer) = 0;
};

class ComputerPartDisplayVisitor : public ComputerPartVisitor
{
public:
	ComputerPartDisplayVisitor() {};
	virtual void visit(Keyboard *keyboard);
	virtual void visit(Mouse *mouse);
	virtual void visit(Monitor *monitor);
	virtual void visit(Computer *computer);
};