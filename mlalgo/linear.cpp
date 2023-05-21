#include <iostream>
#include <vector>

// Gradient Descent hyperparameters
const double learningRate = 0.01;
const int numIterations = 1000;

// Function to perform gradient descent and train the model
void gradientDescent(const std::vector<double>& x, const std::vector<double>& y, double& theta0, double& theta1) {
    const int n = x.size();
    double cost;

    for (int iteration = 0; iteration < numIterations; ++iteration) {
        double theta0Gradient = 0.0;
        double theta1Gradient = 0.0;

        for (int i = 0; i < n; ++i) {
            double prediction = theta0 + theta1 * x[i];
            double error = prediction - y[i];
            theta0Gradient += error;
            theta1Gradient += error * x[i];
        }

        theta0 -= (learningRate / n) * theta0Gradient;
        theta1 -= (learningRate / n) * theta1Gradient;

        // Calculate the cost function
        cost = 0.0;
        for (int i = 0; i < n; ++i) {
            double prediction = theta0 + theta1 * x[i];
            double error = prediction - y[i];
            cost += error * error;
        }
        cost /= (2 * n);

        // Print cost for every 100 iterations
        if (iteration % 100 == 0) {
            std::cout << "Iteration: " << iteration << " Cost: " << cost << std::endl;
        }
    }

    std::cout << "Training completed. Final cost: " << cost << std::endl;
}

int main() {
    // Sample data
    std::vector<double> x = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    std::vector<double> y = { 2.0, 4.0, 5.0, 7.0, 8.0 };

    // Initialize model parameters
    double theta0 = 0.0;  // Intercept
    double theta1 = 0.0;  // Slope

    // Train the model
    gradientDescent(x, y, theta0, theta1);

    // Print the learned parameters
    std::cout << "Learned parameters: theta0 = " << theta0 << ", theta1 = " << theta1 << std::endl;

    // Use the learned model to make predictions
    double input = 6.0;
    double prediction = theta0 + theta1 * input;
    std::cout << "Prediction for input " << input << ": " << prediction << std::endl;

    return 0;
}
