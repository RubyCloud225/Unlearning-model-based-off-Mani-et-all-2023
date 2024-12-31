#ifndef DATA_PROCESSOR_HPP
#define DATA_PROCESSOR_HPP

#include <vector>

class DataProcessor {
public:
DataProcessor(); //Contructor
//Function to calculate the weights based on input data
std::vector<double> calculateWeights(const std::vector<double>& data);
private:
double calculateWeight(double value); //Helper to calculate weight for a single data point
};
#endif // DATA_PROCESSOR_HPP