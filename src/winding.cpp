#include <Eigen/Dense>
using namespace Eigen;

#include <iostream>

void MatrixPassing(const MatrixXd& V) {
    std::cout << "Hello I passed a matrix!" << std::endl;
}

void SurfaceWindingNumber(
        const Eigen::MatrixXd& V, 
        const Eigen::MatrixXi& E,
        const Eigen::MatrixXi& F
        const Eigen::VectorXd& l, 
        const Eigen::MatrixXd& theta, 
        const Eigen::VectorXi& Gamma, 
        const float eps, 
        Eigen::VectorXf& w) {
    return;
}
