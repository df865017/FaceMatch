#include"mouth.h"
Mouth* Mouth::Pmouth=NULL;   //give the first the price to Pmouth

//1.1
void Mouth::MousePoint()
{
	mouth_window="Mouth Image";
	face_filename=".//face_part//txt//mouth.txt";
			CopyImage(mat_mouth,mat_public);
			public_window=mouth_window;
	//define the file
	face_fout.open(face_filename,ios::out|ios::app);
	if(!face_fout) 
	{
	cout<<"error in open the file!"<<endl;
	system("pause");
	face_fout.close();
	return ;
	}
	//show the point
	cv::namedWindow(public_window,CV_WINDOW_AUTOSIZE); 
	cvMoveWindow(public_window,0,0);
	cv::setMouseCallback(public_window,on_mouse,0);//
	cv::imshow(public_window,mat_public);
	cv::waitKey(0); 
	face_fout.close();
}

//1.2
void Mouth::on_mouse(int event,int x,int y,int flags,void *ustc)
{
	      if ( Pmouth == NULL )
            return;
		            // �ص������е��÷Ǿ�̬����
		static Point pre_pt = (-1,-1);//��ʼ����  
		static Point cur_pt = (-1,-1);//ʵʱ����  
		char temp[16];  


		if (event == CV_EVENT_LBUTTONDOWN)//������£���ȡ��ʼ���꣬����ͼ���ϸõ㴦��Բ  
		{  
			sprintf(temp,"(%d,%d)",y,x);  
			//sprintf(temp,"(%d,%d,%d)",image.at<Vec3b>(x,y)[0],image.at<Vec3b>(x,y)[1],image.at<Vec3b>(x,y)[2]); 
			pre_pt = Point(x,y);  
			putText(Pmouth->mat_public,temp,pre_pt,FONT_HERSHEY_SIMPLEX,0.3,Scalar(0,0,255,255),1,8,false);//�ڴ�������ʾ����  
			circle(Pmouth->mat_public,pre_pt,2,Scalar(255,0,0,0),CV_FILLED,CV_AA,0);						//����  
			//write the ordinate in the file
			Pmouth->face_fout<<(double)x<<'\t'<<(double)y<<endl;

			imshow(Pmouth->public_window,Pmouth->mat_public);  
			cv::waitKey(0); 
		}  


}

//2.1
void Mouth::InFileMouth()
{
		//define the file
	face_filename=".//face_part//txt//mouth.txt";
	face_fin.open(face_filename,ios::in|ios::out);
	if(!face_fin) 
	{
	cout<<"error in open the file!"<<endl;
	system("pause");
	face_fin.close();
	return ;
	}
	
		//1.mouth
		double x=0,y=0;
	for(int i=0;i<face_data.GetMouthRows();i++)
	{
		face_fin>>x>>y;
		face_data.SetMouth(x,i,0 ); face_data.SetMouth(y,i,1 );
		
		//cout<<face_data.GetMouth(i,0)<<"\t"<<face_data.GetMouth(i,1)<<endl;
	}

		face_fin.close();

}
//3.1
void  Mouth::Mask()
{
	GrayThreshold(mat_mouth,200);
}

//4.1
void Mouth::Affain()
{
	//1.1  get the srcImage
	CopyImage(file_dst,face_src);
	//1.2  get the dstImage
	CopyImage(mat_mouth,face_dst);
	//1.3  
	GetAffain();
	//1.4 paste the picture
	PasteMouth();
	//1.5
	CopyImage(face_src,file_dst);

}
//4.2
void Mouth::GetAffain()
{
	int max_i=22;
	int Tpoint[22][3];
	//1.target the point
	for(int i=0;i<max_i;i++)
	{
		if(i==0)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=13;
		  Tpoint[i][2]=2;
		}
		else if(i==1)
		{
		  Tpoint[i][0]=2;
		  Tpoint[i][1]=13;
		  Tpoint[i][2]=3;
		}

		else if(i==2)
		{
		  Tpoint[i][0]=3;
		  Tpoint[i][1]=14;
		  Tpoint[i][2]=4;
		}
		else if(i==3)
		{
		  Tpoint[i][0]=4;
		  Tpoint[i][1]=14;
		  Tpoint[i][2]=5;
		}
		else if(i==4)
		{
		  Tpoint[i][0]=5;
		  Tpoint[i][1]=15;
		  Tpoint[i][2]=6;
		}
		else if(i==5)
		{
		  Tpoint[i][0]=6;
		  Tpoint[i][1]=15;
		  Tpoint[i][2]=7;
		}

		else if(i==6)
		{
		  Tpoint[i][0]=8;
		  Tpoint[i][1]=16;
		  Tpoint[i][2]=7;
		}
		else if(i==7)
		{
		  Tpoint[i][0]=9;
		  Tpoint[i][1]=16;
		  Tpoint[i][2]=8;
		}
		else if(i==8)
		{
		  Tpoint[i][0]=10;
		  Tpoint[i][1]=17;
		  Tpoint[i][2]=9;
		}

		else if(i==9)
		{
		  Tpoint[i][0]=11;
		  Tpoint[i][1]=17;
		  Tpoint[i][2]=10;
		}
		else if(i==10)
		{
		  Tpoint[i][0]=12;
		  Tpoint[i][1]=18;
		  Tpoint[i][2]=11;
		}

		else if(i==11)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=18;
		  Tpoint[i][2]=11;
		}
		else if(i==12)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=13;
		  Tpoint[i][2]=18;
		}
		else if(i==13)
		{
		  Tpoint[i][0]=13;
		  Tpoint[i][1]=17;
		  Tpoint[i][2]=18;
		}
		else if(i==14)
		{
		  Tpoint[i][0]=13;
		  Tpoint[i][1]=14;
		  Tpoint[i][2]=17;
		}
		else if(i==15)
		{
		  Tpoint[i][0]=14;
		  Tpoint[i][1]=16;
		  Tpoint[i][2]=17;
		}
		else if(i==16)
		{
		  Tpoint[i][0]=14;
		  Tpoint[i][1]=15;
		  Tpoint[i][2]=16;
		}
		else if(i==17)
		{
		  Tpoint[i][0]=7;
		  Tpoint[i][1]=15;
		  Tpoint[i][2]=16;
		}
		else if(i==18)
		{
		  Tpoint[i][0]=3;
		  Tpoint[i][1]=13;
		  Tpoint[i][2]=14;
		}

		else if(i==19)
		{
		  Tpoint[i][0]=5;
		  Tpoint[i][1]=14;
		  Tpoint[i][2]=15;
		}
		else if(i==20)
		{
		  Tpoint[i][0]=11;
		  Tpoint[i][1]=17;
		  Tpoint[i][2]=18;
		}
		else if(i==21)
		{
		  Tpoint[i][0]=9;
		  Tpoint[i][1]=16;
		  Tpoint[i][2]=17;
		}

	}

	//2.get the matrix
		   for(int i=0;i<max_i;i++)
		   {
			   	 Point2f srcTri[3];
				 Point2f dstTri[3];
				int pointcount=3;  //three point

				for(int j=0;j<pointcount;j++)
				{
					//1
				double x1=face_data.GetMouth(Tpoint[i][j]-1,0);
				double y1=face_data.GetMouth(Tpoint[i][j]-1,1);
				srcTri[j]= Point2f(x1,y1);
				double x2=file_data.GetMouth(Tpoint[i][j]-1,0);
				double y2=file_data.GetMouth(Tpoint[i][j]-1,1);
				dstTri[j]=	Point2f(x2,y2);
				//cout<<x1<<'\t'<<y1<<endl;
				//cout<<x2<<'\t'<<y2<<endl;
				}
				        /// ��÷���任 (10 matrix)
				warp_mouth[i] = getAffineTransform( srcTri, dstTri );
				//cout<<warp_mouth[i]<<endl;
		   }//for
}


//4.3
void Mouth::PasteMouth()
{
	int max_value=220;
	 for (int y=0;y<face_dst.rows;y++)
	 for(int x=0;x<face_dst.cols;x++)
	 {
			if(mat_mouth_mask.at<Vec3b>(y,x)[0]==0&&mat_mouth_mask .at<Vec3b>(y,x)[1]==0&&mat_mouth_mask .at<Vec3b>(y,x)[2]==0) //face_dst is a mask; mat_mouth_mask  is also a mask
			{
			}
			//10*i 10*i 10*i
			else if(mat_mouth_mask .at<Vec3b>(y,x)[0]<=max_value&&mat_mouth_mask .at<Vec3b>(y,x)[1]<=max_value&&mat_mouth_mask .at<Vec3b>(y,x)[2]<=max_value)
			{
				//
					int order=0;
					int price=(int)mat_mouth_mask .at<Vec3b>(y,x)[0];
					order=( price/10 -1 );


					warp_mouth[order].copyTo(warp_mat);

					face_src.at<Vec3b>( PointY(warp_mat,x,y),PointX(warp_mat,x,y))[0]=face_dst.at<Vec3b>(y,x)[0];
					face_src.at<Vec3b>( PointY(warp_mat,x,y),PointX(warp_mat,x,y))[1]=face_dst.at<Vec3b>(y,x)[1];
					face_src.at<Vec3b>( PointY(warp_mat,x,y),PointX(warp_mat,x,y))[2]=face_dst.at<Vec3b>(y,x)[2];


			}
	}

}