#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boost/uuid/uuid.hpp"            // uuid class
#include "boost/uuid/uuid_generators.hpp" // generators
#include "boost/uuid/uuid_io.hpp"         // streaming operators etc.

#include <iostream>
#include <string>

int main (int argc, char *argv[])
{
  if (argc < 2)
    {
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
  double inputValue = atof(argv[1]);
  double outputValue = sqrt(inputValue);
  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);

  boost::uuids::string_generator gen;
  boost::uuids::uuid uuid = gen( std::string("00000000-0123-0123-0123-0123456789AB") );
  std::cout << uuid << std::endl;

  return 0;
}
