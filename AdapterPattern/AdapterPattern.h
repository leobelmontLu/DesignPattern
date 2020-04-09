#pragma once
#include <string>
#include <iostream>

using namespace std;


class MediaPlayer
{
public:
	virtual void play(const string& audioType, const string& fileName) = 0;
};

class AdvancedMediaPlayer
{
public:
	virtual void playVlc(const string& fileName) = 0;
	virtual void playMp4(const string& fileName) = 0;
};

class VlcPlayer : public AdvancedMediaPlayer
{
public:
	virtual void playVlc(const string& fileName);
	virtual void playMp4(const string& fileName);
};

class Mp4Player : public AdvancedMediaPlayer
{
public:
	virtual void playVlc(const string& fileName);
	virtual void playMp4(const string& fileName);
};

class MediaAdapter : public MediaPlayer
{
public:
	MediaAdapter(const string& audioType);
	virtual void play(const string& audioType, const string& fileName);
private:
	AdvancedMediaPlayer* _AdvancedMediaPlayer;
};

class AudioPlayer : public MediaPlayer
{
public:
	virtual void play(const string& audioType, const string& fileName);
private:
	MediaAdapter* _MediaAdapter;
};