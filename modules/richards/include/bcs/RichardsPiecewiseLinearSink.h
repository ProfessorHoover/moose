/*****************************************/
/* Written by andrew.wilkins@csiro.au    */
/* Please contact me if you make changes */
/*****************************************/

#ifndef RICHARDSPIECEWISELINEARSINK
#define RICHARDSPIECEWISELINEARSINK

#include "IntegratedBC.h"
#include "LinearInterpolation.h"

// Forward Declarations
class RichardsPiecewiseLinearSink;

template<>
InputParameters validParams<RichardsPiecewiseLinearSink>();

class RichardsPiecewiseLinearSink : public IntegratedBC
{
public:

  RichardsPiecewiseLinearSink(const std::string & name,
                        InputParameters parameters);

protected:
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

  bool _use_mobility;
  bool _use_relperm;
  LinearInterpolation _sink_func;
};

#endif //RichardsPiecewiseLinearSink
