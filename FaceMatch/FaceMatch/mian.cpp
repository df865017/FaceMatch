
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
				Picture picture;              //��������ͼƬ���ݽṹ
				picture.PreFileData();        //�޸�����ͼƬ·��
			//1.1 eyebrow 
				EyeBrow eyebrow;             //����üë�����ݽṹ
				eyebrow.InputFile();         //��������ͼƬ��������Ϣ
				//eyebrow.LMousePoint();     //������üë��������Ϣ
				//eyebrow.RMousePoint();     //������üë��������Ϣ
				eyebrow.LInFileEyebrow();    //������üë��������Ϣ
				eyebrow.RInFileEyebrow();    //������üë��������Ϣ
				eyebrow.LMask();             //������üë��Mask
				eyebrow.RMask();             //������üë��Mask
				eyebrow.LAffain();           //��üë�ķ���任��ͼ
				eyebrow.RAffain();           //��üë�ķ���任��ͼ
				//eyebrow.ShowFace();

			//1.2 nose 
				Nose nose;                   //������ӵ����ݽṹ
				nose.InputFile();            //��������ͼƬ��������Ϣ
				//nose.MousePoint();        //����������������Ϣ
				nose.InFileNose();			//���������������Ϣ
				nose.Mask();				//�������ӵ�Mask
				nose.Affain();				//���ӵķ���任��ͼ
				//nose.ShowFace();
			//1.3 eye						//�����۾������ݽṹ
				Eye eye;
				eye.InputFile();			//��������ͼƬ��������Ϣ
				//eye.LMousePoint();		//����������������Ϣ
				//eye.RMousePoint();       //����������������Ϣ
				eye.LInFileEye();          //����������������Ϣ
				eye.RInFileEye();          //����������������Ϣ
				eye.LMask();               //�������۵�Mask
				eye.RMask();               //�������۵�Mask
				eye.LAffain();             //���۵ķ���任��ͼ
				eye.RAffain();             //���۵ķ���任��ͼ
				//eye.ShowFace();

			//1.4 mouth                    //������ӵ����ݽṹ
				Mouth mouth;
				mouth.InputFile();         //��������ͼƬ��������Ϣ
				//mouth.MousePoint();      //����������������Ϣ
				mouth.InFileMouth();       //���������������Ϣ
				mouth.Mask();              //�������ӵ�Mask
				mouth.Affain();           //���ӵķ���任��ͼ
				mouth.ShowFace();		  //��ʾƥ����ͼƬЧ��

				//Write(mouth.file_dst,"output1.png");
return 0;
}