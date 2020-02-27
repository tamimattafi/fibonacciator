//
// Created by toxic-dev on 2/27/20.
//
#include <iostream>
#include "../values/FibonacciatorValues.cpp"

using namespace std;



class Fibonacciator {
public:

    explicit Fibonacciator(int targetSum) {
        this->targetSum = targetSum;
    }

    ~Fibonacciator() {
        cout << NEW_LINE + END_MESSAGE << endl;
    }

    void startFibonacciating() {
        cout << NEW_LINE + START_MESSAGE + NEW_LINE << endl;
        prepare();
    }


private:

    const string NEW_LINE = "\n";
    const string LINE_SEPARATOR = "------------------------------------------------";
    const string SPACE = " ";
    const string SEPARATOR = " | ";

    int targetSum, currentSum{}, currentStep{}, lastStep = 1;

    void prepare() {
        displayInfo();
        checkSum();
    }

    void nextStep() {
        calculateCurrentStep();
        calculateNewSum();
        displayInfo();
        checkSum();
    }

    void calculateCurrentStep() {
        int tempLastStep = currentStep;
        currentStep = currentStep + lastStep;
        lastStep = tempLastStep;
    }

    void displayInfo() {
        cout <<
             NEW_LINE + LINE_SEPARATOR + NEW_LINE
             + STEP + SPACE + to_string(currentStep)
             + SEPARATOR
             + SPACE + SUM + SPACE + to_string(currentSum)
             + SEPARATOR
             + SPACE + TARGET_SUM + SPACE + to_string(targetSum)
             << endl;
    }

    void calculateNewSum() {
        currentSum += currentStep;
    }

    void checkSum() {
        if (currentSum < targetSum) nextStep();
        else finish();
    }

    void finish() {
        delete this;
    }

};