/*
* Copyright (c) 2018 Intel Corporation.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <inference_engine.hpp>
#include <ext_list.hpp>
#include <opencv2/imgproc.hpp>


extern std::string myTargetDevice;
extern std::string conf_modelLayers;
extern std::string conf_modelWeights;

class Network
{
    size_t modelWidth;
    size_t modelHeight;
    size_t conf_batchSize;
    InferenceEngine::InferRequest::Ptr currInfReq;
    InferenceEngine::InferRequest::Ptr nextInfReq;
 
    public:
        int maxProposalCount;
        InferenceEngine::InputsDataMap *inputInfo;
        std::string outputName;
        int objectSize;
        InferenceEngine::StatusCode stsCd;
        InferenceEngine::StatusCode statusCodeOK;
        Network();
        int loadNetwork();
        template <typename T> void cvMatToBlob (const cv::Mat &img, InferenceEngine::Blob::Ptr &blob);
        size_t getModelHeight();
        size_t getModelWidth();
        void fillInputBlob(cv::Mat img);
        void inferenceRequest();
        void swapInferenceRequest();
        float *inference();

};