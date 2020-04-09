// AdapterPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "AdapterPattern.h"

void VlcPlayer::playVlc(const string& fileName)
{
	cout << "Playing vlc file. Name: " << fileName << endl;
}

void VlcPlayer::playMp4(const string& fileName)
{

}

void Mp4Player::playVlc(const string & fileName)
{
}

void Mp4Player::playMp4(const string & fileName)
{
	cout << "Playing mp4 file. Name: " << fileName << endl;
}

MediaAdapter::MediaAdapter(const string& audioType)
{
	if ("vlc" == audioType)
	{
		_AdvancedMediaPlayer = new VlcPlayer();
	}
	else if ("mp4" == audioType)
	{
		_AdvancedMediaPlayer = new Mp4Player();
	}
}

void MediaAdapter::play(const string & audioType, const string & fileName)
{
	if (_AdvancedMediaPlayer)
	{
		if ("vlc" == audioType)
		{
			_AdvancedMediaPlayer->playVlc(fileName);
		} 
		else if("mp4" == audioType)
		{
			_AdvancedMediaPlayer->playMp4(fileName);
		}
	}
}

void AudioPlayer::play(const string & audioType, const string & fileName)
{
	if (audioType == "mp3")
	{
		cout << "Playing mp3 file. Name: " << fileName << endl;
	}
	else if(audioType == "vlc" || audioType == "mp4")
	{
		_MediaAdapter = new MediaAdapter(audioType);
		if (_MediaAdapter)
		{
			_MediaAdapter->play(audioType,fileName);
		}
	}
}



int main()
{
	AudioPlayer _AudioPlayer;
	_AudioPlayer.play("mp3", "beyond the horizon.mp3");
	_AudioPlayer.play("vlc", "far far away.vlc");
	_AudioPlayer.play("mp4", "alone.mp4");
	_AudioPlayer.play("mp3", "beyond the horizon.mp3");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
