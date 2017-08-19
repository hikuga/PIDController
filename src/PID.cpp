#include "PID.h"
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * TODO: Complete the PID class.
 */

PID::PID(double kp, double ki, double kd) : Kp(kp), Ki(ki), Kd(kd) {}

PID::~PID() {}

void PID::update(double cte) {
  // update values
  delta_cte_ = cte - last_cte_;
  last_cte_ = cte;
  intgrl_cte_ += cte;

  result_ = Kp * last_cte_ + Kd * delta_cte_ + Ki * intgrl_cte_;
  // keep this between the bounds
  result_ = max(l_limit_, result_);
  result_ = min(u_limit_, result_);
}


double PID::TotalError() {

    return 0;
}
