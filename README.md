# donut_renderer
 
 The code renders a spinning donut on the terminal.

 To compile the code (with gcc): g++ main.cpp -o main
 To run the code (powershell): ./main

 The parameters of the donut can be changed by altering the #define values in main.cpp.
    - WIDTH: Number of characters per line 
    - LENGTH: Total number of lines per frame
    - FOCAL: Distance of the viewer from the donut (doesn't really do much tbh)
    - X_ROTATION: Rotation of the donut in the x-axis each frame (in radians)
    - Y_ROTATION: Rotation of the donut in the y-axis each frame (in radians)
    - INC_THETA, INC_PHI: Responsible for drawing the donut (decrease if drawing a larger donut, setting a value too low will make the code run slower)
    - TIME_PER_FRAME: Time delay (in milliseconds) between each frame
