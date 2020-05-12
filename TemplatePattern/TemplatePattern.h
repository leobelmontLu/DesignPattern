#pragma once

#include <iostream>


using namespace std;


class Game
{
public:
	void play();

public:
	virtual void initialize() {};
	virtual void startPlay() {};
	virtual void endPlay() {};
};

class Cricket : public Game
{
public:
	virtual void initialize();
	virtual void startPlay();
	virtual void endPlay();
};

class Football : public Game
{
public:
	virtual void initialize();
	virtual void startPlay();
	virtual void endPlay();
};