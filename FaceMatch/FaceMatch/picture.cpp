#include"picture.h"
//1.0
//1.1 FileData Operate
void Picture::PreFileData()
{
    //1.  "0104_1"
	//2.  "0105_0"
	//3.  "0105_1"
	//4.  "0113_0"
	//5.  "0114_0"

	ChangePicture("0114_0",12);
	ReadPicture();
}

//1.2 Change the picture
void  Picture::ChangePicture(char* range, int order)
{
	//0104_1
	if( strcmp(range,"0104_1")  ==0)
	{
			if(order==1)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_00.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_00.png";

			}
			else if(order==2)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_05.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_05.png";

			}
			else if(order==3)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_06.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_06.png";

			}
			else if(order==4)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_08.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_08.png";
	
			}
			else if(order==5)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_09.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_09.png";

			}
			else if(order==6)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_12.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_12.png";

			}
			else if(order==7)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_13.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_13.png";

			}

			else if(order==8)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_15.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_15.png";


			}
			else if(order==9)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_16.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_16.png";

			}
			else if(order==10)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_17.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_17.png";

			}
			else if(order==11)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_18.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_18.png";

			}
			else if(order==12)
			{
			 file_filename=".//face//001//01//04_1//001_01_01_041_19.txt";
			 file_picturename=".//face//001//01//04_1//001_01_01_041_19.png";

			}

	}

//0105_0 前12项
	if( strcmp(range,"0105_0")  ==0)
	{
			if(order==1)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_00.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_00.png";

			}
			else if(order==2)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_01.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_01.png";

			}
			else if(order==3)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_02.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_02.png";

			}
			else if(order==4)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_03.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_03.png";
	
			}
			else if(order==5)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_04.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_04.png";

			}
			else if(order==6)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_05.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_05.png";

			}
			else if(order==7)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_06.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_06.png";

			}

			else if(order==8)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_07.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_07.png";



			}
			else if(order==9)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_08.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_08.png";

			}
			else if(order==10)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_09.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_09.png";

			}
			else if(order==11)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_10.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_10.png";

			}
			else if(order==12)
			{
			 file_filename=".//face//001//01//05_0//001_01_01_050_11.txt";
			 file_picturename=".//face//001//01//05_0//001_01_01_050_11.png";

			}
	}
//0105_1 前12项
	if( strcmp(range,"0105_1")  ==0)
	{
			if(order==1)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_00.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_00.png";

			}
			else if(order==2)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_01.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_01.png";

			}
			else if(order==3)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_02.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_02.png";

			}
			else if(order==4)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_03.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_03.png";
	
			}
			else if(order==5)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_04.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_04.png";

			}
			else if(order==6)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_05.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_05.png";

			}
			else if(order==7)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_06.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_06.png";

			}

			else if(order==8)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_07.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_07.png";


			}
			else if(order==9)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_08.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_08.png";

			}
			else if(order==10)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_09.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_09.png";

			}
			else if(order==11)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_10.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_10.png";

			}
			else if(order==12)
			{
			 file_filename=".//face//001//01//05_1//001_01_01_051_11.txt";
			 file_picturename=".//face//001//01//05_1//001_01_01_051_11.png";

			}

	
	}

//0113_0 前12项
	if( strcmp(range,"0113_0")  ==0)
	{
			if(order==1)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_00.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_00.png";

			}
			else if(order==2)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_01.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_01.png";

			}
			else if(order==3)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_02.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_02.png";

			}
			else if(order==4)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_03.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_03.png";
	
			}
			else if(order==5)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_04.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_04.png";

			}
			else if(order==6)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_05.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_05.png";

			}
			else if(order==7)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_06.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_06.png";

			}

			else if(order==8)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_07.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_07.png";


			}
			else if(order==9)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_08.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_08.png";

			}
			else if(order==10)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_09.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_09.png";

			}
			else if(order==11)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_10.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_10.png";

			}
			else if(order==12)
			{
			 file_filename=".//face//001//01//13_0//001_01_01_130_11.txt";
			 file_picturename=".//face//001//01//13_0//001_01_01_130_11.png";

			}
	}
//0114_0 前12项
	if( strcmp(range,"0114_0")  ==0)
	{
			if(order==1)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_00.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_00.png";

			}
			else if(order==2)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_01.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_01.png";

			}
			else if(order==3)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_02.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_02.png";

			}
			else if(order==4)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_03.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_03.png";
	
			}
			else if(order==5)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_04.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_04.png";

			}
			else if(order==6)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_05.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_05.png";

			}
			else if(order==7)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_06.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_06.png";

			}

			else if(order==8)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_07.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_07.png";


			}
			else if(order==9)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_08.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_08.png";

			}
			else if(order==10)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_09.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_09.png";

			}
			else if(order==11)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_10.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_10.png";

			}
			else if(order==12)
			{
			 file_filename=".//face//001//01//14_0//001_01_01_140_11.txt";
			 file_picturename=".//face//001//01//14_0//001_01_01_140_11.png";

			}
	}
}


//1.3 Input the picture
void  Picture::ReadPicture()
{
	if(file_picturename!="")
	{
	file_src = imread( file_picturename, 1 );
	file_dst= Mat::zeros(file_src.rows,file_src.cols,file_src.type() );
	file_src.copyTo(file_dst);
	}

}