#include <iostream>
#include <vector>

using namespace std;

class Perceptron {
private:
    int input_size;
    float learning_rate;
    vector<double> weights;

    void train_weights(vector<int> inputs, double error) {
        for (int id = 0; id < inputs.size(); id++) {
            this->weights[id] += this->learning_rate * error * inputs[id];
        }
    }

public:
    Perceptron(int input_size, float learning_rate) {
        this->input_size = input_size;
        this->learning_rate = learning_rate;
        for (int i = 0; i < input_size; i++) {
            this->weights.push_back(((double)rand()) / RAND_MAX);
        }
    }

    double predict(vector<int> inputs) {
        double weighted_sum = 0;
        for (int i = 0; i < input_size; i++) {
            weighted_sum += inputs[i] * this->weights[i];
        }
        return weighted_sum;
    }

    void train(vector<vector<int>> training_inputs, vector<int> labels, int epochs) {
        for (int i = 0; i < epochs; i++) {
            for (int id = 0; id < training_inputs.size(); id++) {
                double prediction = this->predict(training_inputs[id]);
                double error = labels[id] - prediction;
                train_weights(training_inputs[id], error);
            }
        }
    }
};


int main()
{
    Perceptron prcp(3, 0.1);

    vector<vector<int>> training_inputs = { {0, 0, 0},
                                            {1, 0, 0},
                                            {0, 1, 0},
                                            {0, 0, 1} };
    vector<int> labels = { 0, 0, 1, 0 };
    prcp.train(training_inputs, labels, 50);



    vector<vector<int>> new_data = { {0, 0, 1},
                                     {1, 1, 0},
                                     {1, 1, 1},
                                     {1, 0, 1} };

    for (auto data : new_data) {
        cout << prcp.predict(data) << endl;
    }
}
