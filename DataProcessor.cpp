#include "DataProcessor.hpp"
#include <cmath> 

DataProcessor::DataProcessor() {
    //Contructor can initalize any member variables if needed
}

std::vector<double> DataProcessor::calculateWeights(const std::vector<double>& data) {
    std::vector<double> weights;
    for (double value : data) {
        weights.push_back(calculateWeight(value));
    }
    return weights;
}
double DataProcessor::calculateWeight(double value) {
    return std::exp(value);
}