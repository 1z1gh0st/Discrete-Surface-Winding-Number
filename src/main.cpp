#include <igl/opengl/glfw/Viewer.h>
#include <igl/readPLY.h>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

#include "winding.h"

using namespace Eigen;

int main(int argc, char *argv[]) {

    // Error check
    if (argc < 2) {
        std::cerr << "Please include a filename!\nThat is,\n> " << argv[0] << " YOUR_FILE.ply" << std::endl;
        return 1;
    }

    // Get filename
    std::string fname = argv[1];
    std::cout << "Loading file '" << fname << "' into program..." << std::endl; 

    // Initialize matrices
    MatrixXd V;
    MatrixXi F;
    MatrixXi E;

    // Read PLY file
    if (!(igl::readPLY(fname, V, F, E))) {
        std::cerr << "Loading PLY file failed!" << std::endl;
        return -1;
    }
    else {
        std::cout << "File loaded." << std::endl;
    }

    // What do we need?
    //     - Loop Gamma
    //     - edge lengths l
    //     - corner angles theta
    //     - linear program parm eps
    VectorXi Gamma(0, 1, 2, 3);
    VectorXd l;
    MatrixXd theta;
    float eps = 0.001;

    // Output: w
    VectorXd w;

    SurfaceWindingNumber(
        V, 
        E,
        F, 
        l, 
        theta, 
        Gamma, 
        eps, 
        w);

    std::cout << "Opening mesh viewer..." << std::endl;
    igl::opengl::glfw::Viewer viewer;
    viewer.data().set_mesh(V, F);
    viewer.data().set_face_based(true);
    viewer.data().show_lines = false;
    viewer.launch();

    return 0;
}
