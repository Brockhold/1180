/*
 Name : Pi Estimator
 Author: Ben Rockhold
 Date: 03/22/15
 Description: This program has two major functions; estimating Pi based on a fixed count of
    random number iterations, and finding how long it takes to calcualte a fixed precision of pi.
    The method used to calculate Pi is simple; given a unit circle inscribed within a square,
    generate random points in the range [-1,1]. The ratio of the points that fall inside the square
    (all of them) to the ratio of the points which fall inside only the circle (x^2 + y^2 <= 1)
    is approximately Pi.
    
    The program will first calculate Pi once by this method, and print a report of the iterations and time taken.
    It will then calculate Pi 50 additional times, and report the average iterations and time.
    It then asks the user for a number of random points, and returns the value it calculates based on these points.
 */

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

// Return a random value between -1 and 1
double ranged_rand(){
    return ((float)rand() / RAND_MAX)*2-1;
}

// Given a set number of iterations, calculate pi by way of a Monte Carlo method.
// Returns its estimation when done iterating.
double pi_guesstimator(int random_count){
    int hits;
    double x(0), y(0);
    for(int i=0; i < random_count; i++){
        x = ranged_rand();
        y = ranged_rand();
        if(pow(x, 2) + pow(y, 2) <= 1){ //
            hits += 1;
        }
    }
    return 4.0*hits/random_count;
}

// Brute-force solver for a set length/precision of pi.
// Returns the number of iterations taken
double pi_brute(){
    int hits(0), iterations(0);
    double x(0), y(0), pi_guess(0), pseudo_pi(3.1415);
    while(true){
        iterations += 1;
        x = ranged_rand();
        y = ranged_rand();
        if(pow(x, 2) + pow(y, 2) <= 1){
            hits += 1;
            pi_guess = 4.0*hits/iterations;
        }
        if(abs(pi_guess-pseudo_pi) < 0.00001){
            break;
        }
    }
    return iterations;
}

// Clock how long pi_brute takes on the current computer and print out a measuremnet in seconds.
void pi_clock(){
    clock_t time_taken;
    time_taken = clock();
    int iterations = pi_brute();
    time_taken = clock() - time_taken;
    cout << "Found 3.1415 in " << (float)time_taken/CLOCKS_PER_SEC << " seconds and " << iterations << " iterations." << endl;
}

// Run pi_brute a given number of times and print the averge iterations required
void evaluator(int test_iterations){
    int average_iterations = 0;
    double average_clock = 0;
    clock_t instance_clock;
    for(int i = 0; i <= test_iterations; i++){
        instance_clock = clock();
        average_iterations += pi_brute();
        average_clock += clock() - instance_clock;;
    }
    average_clock = average_clock/test_iterations;
    cout << "Average Iterations: " << (float)average_iterations/test_iterations << endl;
    cout << "Average time: " << (float)average_clock/CLOCKS_PER_SEC << " seconds" << endl;
}

// Clock the time taken by pi_brute, then calculate pi given a user defined number of iterations.
int main() {
    int iteration_limit;
    sranddev(); // Seed the random number generator
    cout << "Finding Pi..." << endl;
    pi_clock();
    evaluator(50);
    cout << "Please enter the number of random values to generate: ";
    cin >> iteration_limit;
    cout << "Calulating..." << endl;
    cout << "Found a value of " << pi_guesstimator(iteration_limit) << " in " << iteration_limit << " iterations." << endl;
    return 0;
}
