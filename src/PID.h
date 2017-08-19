#ifndef PID_H
#define PID_H

class PID {
private:
  double l_limit_ = -1;
  double u_limit_ = 1;

public:
  double result_, delta_cte_, intgrl_cte_ = 0, last_cte_ = 0;

public:
  /*
   * Errors
   */
  double p_error;
  double i_error;
  double d_error;

  /*
   * Coefficients
   */
  double Kp;
  double Ki;
  double Kd;

  /*
   * Constructor
   */
  PID(double kp, double ki, double kd);
  /*
   * Destructor.
   */
  virtual ~PID();

  /*
   * Initialize PID.
   */
  // void Init(double Kp, double Ki, double Kd);

  /*
   * Update the PID error variables given cross track error.
   */
  void update(double cte);
    
  inline double getResult(){
        return result_;
    }

  /*
   * Calculate the total PID error.
   */
  double TotalError();
};

#endif /* PID_H */
