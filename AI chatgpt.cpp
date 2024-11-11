#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Polynomial {
private:
    vector<double> coeffs; // Store coefficients of the polynomial
public:
    Polynomial() : coeffs(1, 0.0) {} // Default to 0
    Polynomial(const vector<double>& coefficients) : coeffs(coefficients) {
        while (coeffs.size() > 1 && coeffs.back() == 0) {
            coeffs.pop_back();
        }
    }

    Polynomial(const Polynomial& other) : coeffs(other.coeffs) {}
    ~Polynomial() {}

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            coeffs = other.coeffs;
        }
        return *this;
    }

    Polynomial operator+(const Polynomial& other) const {
        vector<double> result(max(coeffs.size(), other.coeffs.size()), 0.0);
        for (size_t i = 0; i < result.size(); ++i) {
            if (i < coeffs.size()) result[i] += coeffs[i];
            if (i < other.coeffs.size()) result[i] += other.coeffs[i];
        }
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<double> result(max(coeffs.size(), other.coeffs.size()), 0.0);
        for (size_t i = 0; i < result.size(); ++i) {
            if (i < coeffs.size()) result[i] += coeffs[i];
            if (i < other.coeffs.size()) result[i] -= other.coeffs[i];
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<double> result(coeffs.size() + other.coeffs.size() - 1, 0.0);
        for (size_t i = 0; i < coeffs.size(); ++i) {
            for (size_t j = 0; j < other.coeffs.size(); ++j) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return Polynomial(result);
    }

    bool operator==(const Polynomial& other) const {
        return coeffs == other.coeffs;
    }

    friend ostream& operator<<(ostream& out, const Polynomial& poly) {
        for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
            if (poly.coeffs[i] != 0) {
                out << (poly.coeffs[i] > 0 && i < poly.coeffs.size() - 1 ? "+" : "")
                    << poly.coeffs[i] << "x^" << i << " ";
            }
        }
        return out;
    }

    int degree() const {
        return coeffs.size() - 1;
    }

    double evaluate(double x) const {
        double result = 0;
        for (int i = degree(); i >= 0; --i) {
            result = result * x + coeffs[i];
        }
        return result;
    }

    Polynomial derivative() const {
        vector<double> deriv_coeffs(degree());
        for (int i = 1; i < coeffs.size(); ++i) {
            deriv_coeffs[i - 1] = coeffs[i] * i;
        }
        return Polynomial(deriv_coeffs);
    }

    Polynomial integral() const {
        vector<double> integral_coeffs(coeffs.size() + 1);
        integral_coeffs[0] = 0; // Constant of integration is ignored
        for (int i = 0; i < coeffs.size(); ++i) {
            integral_coeffs[i + 1] = coeffs[i] / (i + 1);
        }
        return Polynomial(integral_coeffs);
    }

    double getRoot(double guess = 1, double tolerance = 1e-6, int maxIter = 100) {
        for (int i = 0; i < maxIter; ++i) {
            double f_val = evaluate(guess);
            double f_prime = derivative().evaluate(guess);
            if (fabs(f_prime) < tolerance) {
                throw runtime_error("Derivative too small; no solution found.");
            }
            double new_guess = guess - f_val / f_prime;
            if (fabs(new_guess - guess) < tolerance) {
                return new_guess;
            }
            guess = new_guess;
        }
        throw runtime_error("Max iterations reached; no solution found.");
    }

    Polynomial compose(const Polynomial& q) const {
        Polynomial result; // Start with zero polynomial using default constructor
        for (int i = degree(); i >= 0; --i) {
            result = result * q + Polynomial({coeffs[i]});
        }
        return result;
    }
};

void inputPolynomial(Polynomial& poly) {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    vector<double> coefficients(degree + 1);
    cout << "Enter the coefficients (from constant term to highest degree): ";
    for (int i = 0; i <= degree; ++i) {
        cin >> coefficients[i];
    }
    poly = Polynomial(coefficients);
}

int main() {
    Polynomial p1, p2;

    // Input for the first polynomial
    inputPolynomial(p1);
    cout << "Polynomial p1: " << p1 << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Polynomials\n";
        cout << "2. Subtract Polynomials\n";
        cout << "3. Multiply Polynomials\n";
        cout << "4. Evaluate Polynomial\n";
        cout << "5. Derivative\n";
        cout << "6. Integral\n";
        cout << "7. Find Root\n";
        cout << "8. Input Second Polynomial\n";
        cout << "9. Compose Polynomials\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "p1 + p2: " << (p1 + p2) << endl;
                break;
            case 2:
                cout << "p1 - p2: " << (p1 - p2) << endl;
                break;
            case 3:
                cout << "p1 * p2: " << (p1 * p2) << endl;
                break;
            case 4: {
                double x;
                cout << "Enter a value to evaluate p1 at: ";
                cin >> x;
                cout << "p1 evaluated at x = " << x << ": " << p1.evaluate(x) << endl;
                break;
            }
            case 5:
                cout << "Derivative of p1: " << p1.derivative() << endl;
                break;
            case 6:
                cout << "Integral of p1: " << p1.integral() << endl;
                break;
            case 7:
                try {
                    double root = p1.getRoot();
                    cout << "Root of p1: " << root << endl;
                } catch (const exception& e) {
                    cout << "Exception: " << e.what() << endl;
                }
                break;
            case 8:
                inputPolynomial(p2);
                cout << "Polynomial p2: " << p2 << endl;
                break;
            case 9:
                cout << "p1 composed with p2: " << p1.compose(p2) << endl;
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
