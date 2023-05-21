# C++ Machine Learning Algorithm - Linear Regression

This project demonstrates a simple machine learning algorithm implemented in C++. The algorithm used is linear regression, which is a basic regression model. The implementation includes a gradient descent optimization method for training the model.

## Prerequisites

To run this project, you need to have a C++ compiler installed on your machine.

## Usage

1. Clone the repository to your local machine or download the source code.

2. Open a terminal or command prompt and navigate to the project directory.

3. Compile the source code using the following command:

    ```shell
    g++ -o linear_regression linear_regression.cpp
    ```

4. Run the compiled program:

    ```shell
    ./linear_regression
    ```

5. The program will train the linear regression model using the provided sample data and print the learned parameters. It will also make a prediction for a new input value.

## Configuration

The algorithm has two hyperparameters that can be configured:

- `learningRate` - The learning rate determines the step size in the gradient descent algorithm. Modify the `learningRate` constant in the source code to adjust the learning rate. Default value: 0.01.

- `numIterations` - The number of iterations specifies the number of times the algorithm iterates over the training data during the gradient descent process. Modify the `numIterations` constant in the source code to change the number of iterations. Default value: 1000.

Feel free to experiment with different hyperparameter values to observe their impact on the training process and the resulting model.

## Sample Data

The project includes a sample dataset consisting of input (`x`) and target (`y`) values. The provided sample data represents a simple linear relationship. You can modify the `x` and `y` vectors in the `main` function of the source code to use your own data.

## License

This project is licensed under the [MIT License](LICENSE).

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvement, please open an issue or submit a pull request.

## Acknowledgments

The implementation of this machine learning algorithm was inspired by the concepts covered in various machine learning courses and resources.

---