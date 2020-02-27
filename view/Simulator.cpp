#include <iostream>
#include "../values/MainValues.cpp"
#include "../model/Fibonacciator.cpp"

using namespace std;

class Simulator {

private:

    const string NEW_LINE = "\n";
    const string SEPARATOR = " | ";

    void askUserForRestart() {
        cout << NEW_LINE + RESTART_MESSAGE << endl;
        cout << NEW_LINE + ACCEPT_MESSAGE + SEPARATOR + DECLINE_MESSAGE << endl;
        string inputString;
        getline(cin, inputString);
        checkRestartInput(inputString);
    }

    void checkRestartInput(const string& value) {
        if (value == ACCEPT_MESSAGE) handleUserInput();
        else if (value == DECLINE_MESSAGE) exit();
        else {
            cout << NEW_LINE + UNCORRECT_INPUT_MESSAGE << endl;
            askUserForRestart();
        }
    }

    void handleUserInput() {
        cout << NEW_LINE + INPUT_MESSAGE << endl;
        string inputString;
        getline(cin, inputString);
        try {
            checkSumInput(stoi(inputString));
        } catch (const std::exception& e) {
            retryHandleUserInput();
        }
    }

    void checkSumInput(int value) {
        if (value > MIN_SIMULATION_VALUE) startCalculation(value);
        else retryHandleUserInput();
    }

    void retryHandleUserInput() {
        cout << NEW_LINE + UNCORRECT_INPUT_MESSAGE << endl;
        handleUserInput();
    }

    void startCalculation(int targetSum) {
        auto fibonacciator = new Fibonacciator(targetSum);
        fibonacciator->startFibonacciating();
        askUserForRestart();
    }

    void exit() {
        delete this;
    }

public:

    Simulator() {
        cout << NEW_LINE + SIMULATION_START_MESSAGE << endl;
    }

    ~Simulator() {
        cout << NEW_LINE + SIMULATION_END_MESSAGE << endl;
    }

    void startSimulation() {
        cout << NEW_LINE + SIMULATOR_STARTED << endl;
        handleUserInput();
    }

};

