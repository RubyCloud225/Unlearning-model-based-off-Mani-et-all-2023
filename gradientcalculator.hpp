#ifndef GRADIENTCALCULATOR_HPP
#define GRADIENTCALCULATOR_HPP

#include <vector>

class GradientCalculator {
    public:
    GradientCalculator();

    std::vector<double> calculateGradient(const std::vector<double>& input, const std::vector<double>& weights);
    private:
    double calculateGradient(double weight);
};
#endif // GRADIENTCALCULATOR_HPP