#ifndef CONWAYS_H
#define CONWAYS_H
#include "display.hpp"

class Conways : public Display {
public:
   Conways(float);
   ~Conways( );
   void calculate_next_display();
   void initialize_display();
   float get_density();
private:
   float density;
};

#endif /* CONWAYS_H */
