#include <igl/opengl/glfw/Viewer.h>
#include <igl/readPLY.h>
#include <iostream>

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


    std::cout << "Opening mesh viewer..." << std::endl;
    igl::opengl::glfw::Viewer viewer;
    viewer.data().set_mesh(V, F);
    viewer.data().set_face_based(true);
    viewer.data().show_lines = false;
    viewer.launch();

    return 0;
}
