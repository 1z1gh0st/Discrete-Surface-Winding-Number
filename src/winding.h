#ifndef WINDING_H
#define WINDING_H

void MatrixPassing(const Eigen::MatrixXd& V);
// Algorithm 1
// output: w
void SurfaceWindingNumber(
        const Eigen::MatrixXd& V, 
        const Eigen::MatrixXi& E,
        const Eigen::MatrixXi& F);
        const Eigen::VectorXd& l, 
        const Eigen::MatrixXd& theta, 
        const Eigen::VectorXi& Gamma, 
        const float eps, 
        Eigen::VectorXf& w);

// Algorithm 2
// output: c
void ComputeReducedCoordinates(
        const Eigen::MatrixXd& V, 
        const Eigen::MatrixXi& F, 
        const Eigen::VectorXi& Gamma, 
        Eigen::MatrixXi& c);

// Algorithm 3
// output: u
void SolveJumpEquation(
        const Eigen::MatrixXd& V, 
        const Eigen::MatrixXi& F, 
        const Eigen::MatrixXd& theta, 
        const Eigen::VectorXi& Gamma, 
        const Eigen::MatrixXi& c, 
        Eigen::MatrixXd& u);

// Algorithm 4
// output: omega
void DarbouxDerivative(
        const Eigen::MatrixXd& V, 
        const Eigen::MatrixXi& F, 
        const Eigen::VectorXi& Gamma, 
        Eigen::MatrixXd& u);

// Algorithm 5
// output: omega
//void BuildLaplacian(const MatrixXd& V, const MatrixXi& F, const MatrixXd& theta, const VectorXi& Gamma, MatrixXf& L);

// Algorithm 6
// output: b
//void BuildJumpLaplaceRHS(const MatrixXd& V, const MatrixXi& F, const MatrixXd& theta, const VectorXi& Gamma, const MatrixXd& c, VectorXd& b);
#endif
