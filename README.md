# C++ and Python Image Processing Interop

This repository demonstrates interoperability between C++ and Python for the purpose of image processing. It includes an example where an image is loaded in C++ using OpenCV, passed to Python for processing (image mirroring), and then passed back to C++ to be saved to disk.

## Prerequisites

Before running the example code, ensure you have the following installed:
- C++ compiler (e.g., GCC or Clang)
- Python 3.x
- OpenCV (C++ and Python versions)
- Boost.Python
- NumPy

## Setup

Clone the repository using:

```bash
git clone https://github.com/supershmup/image-processing-interop.git
cd image-processing-interope
```

Make sure to install all the required Python dependencies:

```bash
pip install numpy opencv-python
```

## Building the C++ Code

To build the C++ application, run the following command (ensure you update the include and library paths according to your environment):

```bash
g++ -o image_processing_interop main.cpp -I/usr/include/python3.x -lboost_python3x -lpython3.x `pkg-config --cflags --libs opencv4`
```

## Running the Application

After building the application, you can run it using:

```bash
./image_processing_interop
```

Make sure that the `mirror_image.py` file is in the same directory as the executable or in a location specified by the `PYTHONPATH` environment variable.

## File Structure

- `main.cpp`: Contains the C++ code to handle image loading and saving.
- `mirror_image.py`: Contains the Python code to mirror the image.

## Contributing

Contributions are welcome! For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

