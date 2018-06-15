#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  
	/*****************************************************************************
  *  Initialization
  ****************************************************************************/
  
  // Initialize P, I, D errors
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  // Initialize P, I, D gains/coefficients
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
  
  //
}

void PID::UpdateError(double cte) {
}

double PID::TotalError() {
}

