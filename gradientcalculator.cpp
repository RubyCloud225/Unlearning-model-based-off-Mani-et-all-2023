#include "gradientcalculator.hpp"

#include <vector>
#include <cmath>
#include <iostream>

GradientCalculator::GradientCalculator() {

}

std::vector<double> GradientCalculator::calculateGradient(const std::vector<double>& input, const std::vector<double>& weights) {
    // Internal state
    std::vector<double> SetEta = LeanringRate; // both of these are undefined
    std::vector<double> Setalpha = Momentum; // currently undefined
    // each parameter would need to be calculated
    std::vector<void> updateInputWeights(Layer &prevLayer) {
        // weights to be updated are in Connection Container (will need to be added)
        for(unsigned n = 0; n < prevLayer.size(); ++n)
        {
            Neuron &neuron = prevLayer[n];
            double oldDeltaWeight = neuron.M_outputWeights[m_myIndex].deltaWeight;
            double newDeltaWeight = eta * neuron.getOutputVal() * m_gradient + alpha * oldDeltaWeight;
            neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
            neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
        }
    }
    std::vector<double> SumDOW(const Layer &nextLayer) const{
        double sum = 0.0;
        for(unsigned n = 0; n < nextLayer.size(); ++n)
        {
            sum += nextLayer[n].m_outputWeights[m_myIndex].deltaWeight * nextLayer[n].m_gradient;
        }
        return sum;
    }
}

