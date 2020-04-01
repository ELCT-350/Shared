#include "Signal/Blocks/Ramp.h"
#include "Signal/Blocks/SinusoidalSource.h"

#include "MNA/Blocks/Ground.h"
#include "MNA/Blocks/IdealVoltageSourceDC.h"
#include "MNA/Blocks/Resistor.h"
#include "MNA/MnaSolver.h"

#include <fstream>

using namespace ELCT350;
using namespace ELCT350::Signal::Blocks;

using namespace ELCT350::MNA;
using namespace ELCT350::MNA::Blocks;

using namespace std;

const double STOP_TIME = 5.0;
const double TIME_STEP = 0.01;

void exampleSignal()
{
  //Create blocks and set parameters
  SinusoidalSource source;
  source.setParameter(SinusoidalSource::Amplitude, 1.0);
  source.setParameter(SinusoidalSource::Frequency, 3.0);

  Ramp ramp;
  ramp.setParameter(Ramp::InitialCondition, 2.0);
  ramp.setParameter(Ramp::Slope, 0.5);

  //Initialize before simulation
  source.init();
  ramp.init();

  ofstream output("outputSignal.csv");
  output << "time,ramp" << endl;
  for (double time = 0.0; time < STOP_TIME; time += TIME_STEP)
  {
    source.step(time, TIME_STEP);
    ramp.setInputPortValue(Ramp::Input, source.getOutputPortValue(SinusoidalSource::Output));
    ramp.step(time, TIME_STEP);

    output << time << ',' << ramp.getOutputPortValue(SinusoidalSource::Output) << endl;
  }
}

void exampleMna()
{
  //Create blocks and set parameters
  IdealVoltageSourceDC vdc;
  vdc.setParameter(IdealVoltageSourceDC::Vdc, 1.0);
  
  Resistor r;
  r.setParameter(Resistor::Resistance, 2.0);

  Ground gnd;

  MnaSolver solver;
  solver.connect(vdc.getPort(IdealVoltageSourceDC::Positive), r.getPort(Resistor::Positive));
  solver.connect(vdc.getPort(IdealVoltageSourceDC::Negative), gnd.getPort(Ground::Reference));
  solver.connect(r.getPort(Resistor::Negative), gnd.getPort(Ground::Reference));

  solver.init();

  ofstream output("outputMNA.csv");
  output << "time,voltage,current" << endl;
  for (double time = 0.0; time < STOP_TIME; time += TIME_STEP)
  {
    solver.step(time, TIME_STEP);

    output << time << ','
           << vdc.getPort(IdealVoltageSourceDC::Positive).getAcross() << ','
           << r.getPort(Resistor::Positive).getThrough()
           << endl;
  }
}

int main()
{
  exampleMna();
  return 0;
}
