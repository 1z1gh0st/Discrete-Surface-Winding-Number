#include <Eigen/Core>
using namespace Eigen;
template <typename DerivedV, typename DerivedF, typename Index>
void SurfaceWindingNumber(
        const MatrixBase<DerivedV> &V,           // IN:  Vertices
        const MatrixBase<DerivedF> &F,           // IN:  Faces
        const MatrixBase<Derivedl> &l,           // IN:  Edge lengths
        const MatrixBase<Derivedtheta> &theta,   // IN:  Corner angles
        const VectorBase<DerivedGamma> &Gamma,   // IN:  1-Chain on mesh
        const double epsilon,                    // IN:  Linear prgrm param
        MatrixBase<Derivedw> &w                  // OUT: winding number fn
) {
    // Compute Reduced Coordinates

    // c <- 0^(|F| x 3) = 0^|C|
    MatrixXi c(F.rows(), 3);
    c.setZero();

    // TODO:
    int interiorVerts[5] = {1,2,3,4,5}

    // Get matrix to determine vertex-wise manifoldness
    Vector<bool, V.rows()> is_manifold;
    igl::is_vertex_manifold(&F, is_manifold);
    
    // for (i in InteriorVertices(M, Gamma))
    for (int i : interiorVerts) {
        if (is_manifold[i] == false) {
            continue;
        }
        else {
        }

    }
    return;
}
