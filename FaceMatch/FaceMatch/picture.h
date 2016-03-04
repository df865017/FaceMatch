#ifndef Picture_H
#define Picture_H
#include"filedata.h"
class Picture:public FileData
{
public:
	Picture()
	{
	}
	~Picture()
	{
	}	
	void PreFileData();
	void ChangePicture(char* range, int order);
    void ReadPicture();
};

#endif
