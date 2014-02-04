#include"opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

Mat img=imread("puzzle.png");

int rv=0;
int gv=0;
int bv=0;

void CallBackFunc(int event,int x,int y,int flags,void* userdata)
{int b,g,r;


if(event == EVENT_RBUTTONDOWN)
{
	cout<<"the right mouse button was clicked at ("<<x<<","<<y<<")"<<endl;
	bv=img.at<cv::Vec3b>(y,x)[0];
	gv=img.at<cv::Vec3b>(y,x)[1];
	rv=img.at<cv::Vec3b>(y,x)[2];
	cout<<"bv"<<bv;
	cout<<"gv"<<gv;
	cout<<"rv"<<rv;
	Mat img2,imgthres;
	img2.create(img.size(),img.type());
	img.copyTo(img2);
	
   Mat_<Vec3b>::iterator it = img2.begin<Vec3b>();
	// obtain end position
	Mat_<Vec3b>::iterator itend = img2.end<Vec3b>();
	// loop over all pixels
	for ( ; it!= itend; ++it) {

		b=(*it)[0];
		g=(*it)[1];
		r=(*it)[2];

		if(b>=(bv-50)&&b<(bv+10)&&g>=(gv-50)&&g<(gv+10)&&r>=(rv-50)&&r<(rv+10))
		{(*it)[0]=255;
		(*it)[1]=255;
		(*it)[2]=255;
		}
		else
		{(*it)[0]=0;
		(*it)[1]=0;
		(*it)[2]=0;}
       } 
	   
	namedWindow("out");
	imshow("out",img2);
	waitKey(0);
}



}



int main()
{
	namedWindow("img",1);
	imshow("img",img);
	setMouseCallback("img",CallBackFunc,NULL);


	waitKey(0);

}