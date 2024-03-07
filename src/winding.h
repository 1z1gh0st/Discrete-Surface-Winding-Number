#ifndef WINDING_H
#define WINDING_H

#include <Eigen/Core>

namespace winding {
    template <typename DerivedV, typename DerivedF, typename Index>
    void SurfaceWindingNumber(
            const Eigen::MatrixBase<DerivedV> &V,           // IN:  Vertices
            const Eigen::MatrixBase<DerivedF> &F,           // IN:  Faces
            const Eigen::MatrixBase<Derivedl> &l,           // IN:  Edge lengths
            const Eigen::MatrixBase<Derivedtheta> &theta,   // IN:  Corner angles
            const Eigen::VectorBase<DerivedGamma> &Gamma,   // IN:  1-Chain on mesh
            const double epsilon,                           // IN:  Linear prgrm param
            Eigen::MatrixBase<Derivedw> &w                  // OUT: winding number fn
    );                                                      //   on corners
}
                                                            
#endif
