#ifndef NEURON_HPP
#define NEURON_HPP

class neuron {
    public:
    neuron(unsigned numOutputs, unsigned numInputs, double learningRate, double threshold);
    void setOutputVal(double val) { m_outputVal = val; }
    double getOutputVal(void) { return m_outputVal; }
    void feedForward(const Layer &prevLayer);
    void calcDelta(const Layer &nextLayer);
    void backProp(const Layer &nextLayer);
    void calcOutputGradients(double targetVals);
    void calcHiddenGradients(const Layer &nextLayer);
    void updateInputWeights(Layer &prevLayer);
    private:
    static double eta; //net training rate
    static double alpha; // multiplier of last weight change [momentum]
    static double hiddenBiasGrads; // gradient on hidden bias
    static double outputBiasGrads; // gradient on output bias
    static double randomWeight(void) { return rand() / double(RAND_MAX); }
    double sumDow(const Layer &nextLayer) const;
    double m_outputVal;
    double m_outputGrads;
    double m_hiddenGrads;
    double m_delta;
    double m_outputBias;
    unsigned m_myIndex;
    double m_gradient;
};

#endif