#ifndef FACEREC_H
#define FACEREC_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

class FaceRec
{
public:
    FaceRec();

    int predictLabel(string imgPath);
    static void read_csv(const string& filename);
    void save_model();
    bool check_model();
    void load_model(string model_path);
};

#endif // FACEREC_H
