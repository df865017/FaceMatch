
#include"eyebrow.h"
#include"picture.h"
#include"nose.h"
#include"eye.h"
#include"mouth.h"
char* FileData::file_filename=".//face//001//01//04_1//001_01_01_041_00.txt";
char* FileData::file_picturename=".//face//001//01//04_1//001_01_01_041_00.png";
Mat FileData::file_src = imread( file_picturename, 1 );
Mat FileData::file_dst=  imread(file_picturename, 1 );
void Write(Mat & image, char* picturename)
{
  imwrite(picturename,image);
}

int main()
{
	        //1.0 give the first price to picture
				Picture picture;              //定义样本图片数据结构
				picture.PreFileData();        //修改样本图片路径
			//1.1 eyebrow 
				EyeBrow eyebrow;             //定义眉毛的数据结构
				eyebrow.InputFile();         //输入样本图片特征点信息
				//eyebrow.LMousePoint();     //创建左眉毛特征点信息
				//eyebrow.RMousePoint();     //创建右眉毛特征点信息
				eyebrow.LInFileEyebrow();    //输入左眉毛特征点信息
				eyebrow.RInFileEyebrow();    //输入右眉毛特征点信息
				eyebrow.LMask();             //制作左眉毛的Mask
				eyebrow.RMask();             //制作右眉毛的Mask
				eyebrow.LAffain();           //左眉毛的仿射变换贴图
				eyebrow.RAffain();           //右眉毛的仿射变换贴图
				//eyebrow.ShowFace();

			//1.2 nose 
				Nose nose;                   //定义鼻子的数据结构
				nose.InputFile();            //输入样本图片特征点信息
				//nose.MousePoint();        //创建鼻子特征点信息
				nose.InFileNose();			//输入鼻子特征点信息
				nose.Mask();				//制作鼻子的Mask
				nose.Affain();				//鼻子的仿射变换贴图
				//nose.ShowFace();
			//1.3 eye						//定义眼睛的数据结构
				Eye eye;
				eye.InputFile();			//输入样本图片特征点信息
				//eye.LMousePoint();		//创建左眼特征点信息
				//eye.RMousePoint();       //创建右眼特征点信息
				eye.LInFileEye();          //输入左眼特征点信息
				eye.RInFileEye();          //输入右眼特征点信息
				eye.LMask();               //制作左眼的Mask
				eye.RMask();               //制作右眼的Mask
				eye.LAffain();             //左眼的仿射变换贴图
				eye.RAffain();             //右眼的仿射变换贴图
				//eye.ShowFace();

			//1.4 mouth                    //定义鼻子的数据结构
				Mouth mouth;
				mouth.InputFile();         //输入样本图片特征点信息
				//mouth.MousePoint();      //创建鼻子特征点信息
				mouth.InFileMouth();       //输入鼻子特征点信息
				mouth.Mask();              //制作鼻子的Mask
				mouth.Affain();           //鼻子的仿射变换贴图
				mouth.ShowFace();		  //显示匹配后的图片效果

				//Write(mouth.file_dst,"output1.png");
return 0;
}