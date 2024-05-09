#include <iostream>

// Simulated functions to get current price, moving average, RSI, and momentum
double getCurrentPrice() {
    // Simulated current price
    return 100.0;
}

double getMovingAverage() {
    // Simulated 50-day moving average
    return 95.0;
}

double getRSI() {
    // Simulated Relative Strength Index
    return 60.0;
}

bool hasPositiveMomentum() {
    // Simulated momentum (positive if true, negative if false)
    return true;
}

void suggestAction() {
    double currentPrice = getCurrentPrice();
    double movingAverage = getMovingAverage();
    double rsi = getRSI();
    bool momentumPositive = hasPositiveMomentum();

    std::cout << "Current Price: " << currentPrice << std::endl;
    std::cout << "Moving Average: " << movingAverage << std::endl;
    std::cout << "RSI: " << rsi << std::endl;

    if (currentPrice > movingAverage) {
        std::cout << "Consider buying." << std::endl;
    } else {
        std::cout << "Consider selling." << std::endl;
    }

    if (rsi > 70) {
        std::cout << "Consider selling." << std::endl;
    } else if (rsi < 30) {
        std::cout << "Consider buying." << std::endl;
    }

    if (momentumPositive) {
        std::cout << "Consider buying." << std::endl;
    } else {
        std::cout << "Consider selling." << std::endl;
    }
}

int main() {
    suggestAction();
    return 0;
}
