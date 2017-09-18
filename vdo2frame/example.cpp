//#include <opencv2\core.hpp>
//#include <opencv2\videoio.hpp>
//#include <opencv2\imgcodecs.hpp>
#include <opencv2\opencv.hpp>

#include "iostream"

using namespace cv;
using namespace std;



int main(int argc, char** argv) {

	int num, i = 0;
	VideoCapture cap(argv[1]);

	if (!cap.isOpened())
	{
		cout << "ERRO: O Video não pode ser aberto! ";
		return -1;
	}

	int nframes = cap.get(CAP_PROP_FRAME_COUNT);
	cout << "Total de frames: " << nframes << endl;

	int ini = atoi(argv[2]);
	int fim = atoi(argv[3]);

	if (ini < 0 || fim < 1 || ini + fim > nframes) {
		cout << "Inicio e fim invalidos para o video." << endl;
		return -1;
	}


	for (int i = 0; i < ini; i++)
	{
		Mat frame;
		cap >> frame;
	}

	for (int i = ini; i < ini + fim; i++)
	{
		Mat frame;
		cap >> frame;

		stringstream ss;
		ss << argv[1] << "-frame-" << i << ".png";

		cout << ss.str() << endl;
		imwrite(ss.str(), frame);

	}

	cout << "Concluido." << endl;
	return 0;
}