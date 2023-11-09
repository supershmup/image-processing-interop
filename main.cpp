#include <opencv2/opencv.hpp>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>

namespace py = boost::python;
namespace np = boost::python::numpy;

int main() {
    try {
        // Initialize Boost.Python
        Py_Initialize();
        np::initialize();

        // Load the image using OpenCV
        cv::Mat image = cv::imread("original_image.png");
        
        // Convert the OpenCV Mat to a NumPy array
        np::ndarray image_array = np::from_data(
            image.data,
            np::dtype::get_builtin<uint8_t>(),
            py::make_tuple(image.rows, image.cols, image.channels()),
            py::make_tuple(image.step1(), image.channels(), sizeof(uint8_t)),
            py::object()
        );

        // Import the Python module
        py::object mirror_module = py::import("mirror_image");

        // Fetch the Python function
        py::object mirror_func = mirror_module.attr("mirror_image");

        // Call the Python function and get the mirrored image
        np::ndarray mirrored_image_array = py::extract<np::ndarray>(mirror_func(image_array));

        // Convert the NumPy array back to an OpenCV Mat
        cv::Mat mirrored_image(
            mirrored_image_array.shape(0),
            mirrored_image_array.shape(1),
            CV_8UC3,  // Assuming the image has 3 channels (BGR)
            mirrored_image_array.get_data()
        );

        // Save the mirrored image
        cv::imwrite("mirrored_image.jpg", mirrored_image);

    } catch(py::error_already_set const &) {
        PyErr_Print();
    }

    return 0;
}
