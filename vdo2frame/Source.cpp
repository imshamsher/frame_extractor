#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\video.hpp>
#include<Windows.h>
#include<regex>
#include <direct.h>  


using namespace cv;
using namespace std;

#define _MAX_PATH 600
#define _MAX_DRIVE 10
#define _MAX_DIR 300
#define _MAX_FNAME 200
#define _MAX_EXT 10

char path[_MAX_PATH];
char drive[_MAX_DRIVE];
char dir[_MAX_DIR];
char fname[_MAX_FNAME];
char ext[_MAX_EXT];

void helper() {

	std::cout << "Incorrect arguments, enter the video file name with path in quotes\n";
}

void stripext(std::string videofile) {

	//size_t sizeInCharacters = 100;
	_splitpath_s(videofile.c_str(), drive, dir, fname, ext);
	_makepath_s(path, drive, dir, fname, "");
	std::cout << "DRIVE\t" << drive << "\n";
	std::cout << "dir\t" << dir << "\n";
	std::cout << "fname\t" << fname << "\n";
	std::cout << "ext\t" << ext << "\n";
	std::cout << "PATH\t" << path << "\n";
	_mkdir(path);
	//return(videofile);

}

int main(int argc, char **argv)
{
	VideoCapture cap;
	Mat frame;
	std::string outputpath;
	uint count = 0;
	std::string videofile;
	/*cout << "give the video file path\t";
	getline(cin, videofile);*/
	videofile = argv[1];

	if (argc < 2)
	{
		helper();
		exit(1);
	}

	stripext(videofile);
	cap.open(videofile);
	std::cout << "TOTAL FRAMES =" << cap.get(CAP_PROP_FRAME_COUNT) << "\n";
	outputpath = std::string(path);
	uint c = (uint)cap.get(CAP_PROP_FRAME_COUNT);
	cout << endl << c;
	//here we go
	while (count < c) {

		for (int i = 0; i <6; i++) {
			count++;
			cap.grab();
		}
		/*count++;*/
		cap.retrieve(frame);
		imwrite(outputpath + "\\" + std::string(fname) + "__FRAME__" + std::to_string(count) + ".jpg", frame);
		//exit(-1);
		cout << "no. of images extracted out of " << c << " frames till now are" << count << endl;
	}
	cout << endl << "Extraction Done............";
	cout << endl << "wait For next session...........\n";
	return 0;

}