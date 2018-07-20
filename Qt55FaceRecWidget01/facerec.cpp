#include "facerec.h"

vector<Mat> Images;
vector<int> Labels;
Ptr<FaceRecognizer> model = createLBPHFaceRecognizer();
bool model_loaded = false;

FaceRec::FaceRec()
{

}

int FaceRec::predictLabel(string imgPath)
{
    int predictedLabel;

    if(model_loaded) {

        // sample image to match
        Mat testSample = imread(imgPath, 0);

        predictedLabel = model->predict(testSample);
    }
    // the model is not loaded, return 999 to handle
    else {
        predictedLabel = 999;
    }
    return predictedLabel;
}

void FaceRec::read_csv(const string &filename)
{
    char separator = ',';

    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);
    }
    string line, path, classlabel;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if(!path.empty() && !classlabel.empty()) {
            Images.push_back(imread(path, 0));
            Labels.push_back(atoi(classlabel.c_str()));
        }
    }

    model->train(Images, Labels); // train the model so that its not needed everytime
    cout << "model actually trained" << endl;
    model_loaded = true;
}

void FaceRec::save_model()
{
    if(check_model()){
        model->save("D:\\Softs\\OpenCV\\Resources\\att_faces\\faces.yml");
    }
}

bool FaceRec::check_model()
{
    if (model_loaded){
        return true;
    }
    else {
        return false;
    }
}

void FaceRec::load_model(string model_path)
{
    model->load(model_path);
    model_loaded = true;
}


