#include <iostream>
#include <fstream>
#include <cstdlib>
#include "DataProcessor.hpp"
#include "fetchapi.hpp"

using namespace std;
void processFile(const string& filename)
{
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }
    //store each line of the file
    string line;
    //read the file line by line
    while (getline(file, line)) {
        cout << line << endl;
    }
    // close the file after processing
    cout << line << endl;
}

int main() {
    // initalise data set
    std::vector<double> dataset = fetchDataFromAPI();
    // instantiate the processor
    DataProcessor processor;
    //Calculate weights
    std::vector<double> weights = processor.calculateWeights(dataset);

    //Display results
    std::cout << "Weights: " << std::endl;
    for (size_t i = 0; i < weights.size(); ++i) {
        std::cout <<"Data: " << dataset[i] << " -> Weights: " << weights[i] << std::endl;
    }
    return 0;
}