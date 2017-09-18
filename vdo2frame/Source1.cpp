//
//#pragma comment(lib, "opencv_highgui310.lib")
//#pragma comment(lib, "opencv_core310.lib")
//
//#include <opencv2\highgui.hpp>
//#include <opencv2\core.hpp>
//#include <iostream>
//#include <direct.h>
//
//using namespace cv;
//using namespace std;
//
//#define _MAX_PATH 600
//#define _MAX_DRIVE 10
//#define _MAX_DIR 300
//#define _MAX_FNAME 200
//#define _MAX_EXT 10
//
//char path[_MAX_PATH];
//char drive[_MAX_DRIVE];
//char dir[_MAX_DIR];
//char fname[_MAX_FNAME];
//char ext[_MAX_EXT];
//
//
//int main()
//
//{
//	int count = 0;
//	string videopath;
//	cout << "give me the video path\t";
//	getline(cin, videopath);
//	
//	_splitpath(videopath.c_str(), drive, dir, fname, ext);
//	_makepath(path, drive, dir, fname, "");
//	//_mkdir(path);
//
//
//	VideoCapture cap(videopath.c_str());
//
//	if (!cap.isOpened())
//	{
//		cout << "invalid video\npress enter to exit....";
//		getchar();
//	}
//	else
//		cout << cap.get(CAP_PROP_FRAME_COUNT)<<endl;
//
//	while (count < 200)
//	{
//		Mat frame;
//		for (int i = 0; i < 12; i++) {
//			cap >> frame;;
//	}
//		count++;
//		imwrite(string(path) + "/" + fname+"_"+to_string(count) + ".jpg", frame);
//
//	}
//	cout << endl << "Extraction Done............";
//	cout << endl << "wait For next session...........\n";
//	return 0;
//
//}