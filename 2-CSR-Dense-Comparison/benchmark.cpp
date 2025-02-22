#include "benchmark.h"
#include "DenseMatrix.h"
#include "CSRMatrix.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

void benchmark() {
    std::ofstream file("benchmark_results.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    file << "Size,Dense_Time,Size,CSR_Time\n";

    for (size_t n = 100; n <= 2500; n += 100) {
        std::vector<double> x(n, 1.0);
        DenseMatrix A(n, n);
        CSRMatrix B(n, n);
        
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                A(i, j) = 1.0;
            }
        }

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (i == j) {
                    B.addElement(i, j, 1.0);
                }
            }
        }
        B.finalize();

        auto start = std::chrono::high_resolution_clock::now();
        std::vector<double> resultA = A * x;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dense_duration = end - start;

        start = std::chrono::high_resolution_clock::now();
        std::vector<double> resultB = B * x;
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> csr_duration = end - start;

        file << n << "," << dense_duration.count() << "," << n << "," << csr_duration.count() << "\n";
        std::cout << "Size: " << n << " | Dense: " << dense_duration.count() << "s | CSR: " << csr_duration.count() << "s\n";
    }

    file.close();
    std::cout << "Benchmark results saved to benchmark_results.csv\n";
}