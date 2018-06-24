# CarND-Term2-P4-PID-Control  
## Overview  
In this project you will implement a PID controller in C++ to maneuver the vehicle in the previous lake race track from the Behavioral cloning Project. Your PID controller will be provided cross track error (CTE) and the velocity (mph) by the simulator then compute the appropriate steering angle and feed it back to the simulator to steer the vehicle.  
There is a simulator provided by Udacity ([Term 2 Simulator Release](https://github.com/udacity/self-driving-car-sim/releases/)) which can generate cross track error (CTE) and the velocity (mph). And you will be using those data to update the cross track error (CTE) and calculate the appropriate control inputs then feed it back to the simulator to steer the vehicle.   
Here is the link to the [orginal repository](https://github.com/udacity/CarND-PID-Control-Project) provided by Udaciy. This repository contains all the code needed to complete the final project for the PID controller course in Udacity's Self-Driving Car Nanodegree.
## Prerequisites/Dependencies  
* cmake >= 3.5
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.  
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.  

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)
## Setup Instructions (abbreviated)  
1. Meet the `Prerequisites/Dependencies`  
2. Intall `uWebSocketIO ` on your system  
  2.1 Windows Installation  
  2.1.1 Use latest version of Ubuntu Bash 16.04 on Windows 10, here is the [step-by-step guide](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/) for setting up the utility.  
  2.1.2 (Optional) Check your version of Ubuntu Bash [here](https://www.howtogeek.com/278152/how-to-update-the-windows-bash-shell/).  
3. Open Ubuntu Bash and clone the project repository  
4. On the command line execute `./install-ubuntu.sh`  
5. Build and run your code.  
Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)  
## Project Description  
- [main.cpp](./src/main.cpp):Reads in data, calls a function to initialize and run the PID controller on steering angle with tuned PD hyperparameters.  
- [PID.cpp](./src/ukf.cpp): Initializes the PID controller, calls the error update and total error calculation functions, defines the  `Init()`, `UpdateError()` and `TotalError()` functions.  
- [README.md](./README.md): Writeup for this project, including setup, running instructions and project rubric addressing.  
- [CMakeLists.txt](./CMakeLists.txt): `CMakeLists.txt` file that will be used when compiling your code (you do not need to change this file)
## Run the project  
* Clone this respository
* At the top level of the project repository, create a build directory: `mkdir build && cd build`
* In `/build` directory, compile yoru code with `cmake .. && make`
* Launch the simulator from Windows
* Execute the run command for the project `./pid` (Make sure you also run the simulator on the Windows host machine) If you see * * this message, it is working `Listening to port 4567 Connected!!!`
## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Rubric  
### 1. Compilation  
#### 1.1 Your code should compile.  
Yes, it does.  
### 2. Implementation  
#### 2.1 The PID procedure follows what was taught in the lessons.  
Yes, it does.
### 3. Reflection  
#### 3.1 Describe the effect each of the P, I, D components had in your implementation.  
P gain is proportional to the cross track error (CTE). It helps to compensate the error quickly.  
I gain is the integral/sum of all the CTE. It helps to compensate the consistent bias.  
D gain is the temporal derivative of the CTE. It helps to smooth the change.  
#### 3.2 Describe how the final hyperparameters were chosen.  
Firstly, I decided to try with PD controller. It works but fail eventually.  
Then I tried with PID controller. And it continues fail and fail rapidly.  
Therefore, I went back to PD controller and try more different PD parameters.  
I noticed the steering angle changed like a spike which I should lower my P gain and increase my D gain to smooth the change.  
After several try and error, I finally get the vehicle running smoothly in the autonomous mode in the simulater.  
### 4. Simulation  
#### 4.1 The vehicle must successfully drive a lap around the track.  
Yes, it does. Please see the video below.  
## Videos
Video recordings for success cases.  
Success case for running my particle filter code.  
![Successful running](./videos/CarND-Term2-P3-self_driving_car_nanodegree_program_6_21_2018_10_28_42_PM.gif)  
