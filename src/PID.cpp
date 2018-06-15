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
  // TODO: Initialize errors and coefficients
	
  // Initialize P, I, D errors and previous error
  p_error     = 0.0;
  i_error     = 0.0;
  d_error     = 0.0;
  err_pre_cte = 0.0; // Add this to PID.h
  err_total   = 0.0; // Add this to PID.h

  // Initialize P, I, D gains/coefficients
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
}

void PID::UpdateError(double cte) {
  /*****************************************************************************
  *  Update
  ****************************************************************************/
  // TODO: Update errors and coefficients
  // Initialize P, I, D errors and previous error
  p_error     = cte;
  i_error    += cte;
  d_error     = cte - err_pre_cte;
  err_pre_cte = cte; 
}

double PID::TotalError() {
  /*****************************************************************************
  *  Calculate total error
  ****************************************************************************/
  // TODO: Calculate total error
  err_total = Kp * p_error + Ki * i_error + Kd * d_error;
  return err_total;
}

