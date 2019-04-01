//  Rock.hpp

#ifndef Rock_hpp
#define Rock_hpp

#include "BasicShape.hpp"

#include <IvGame.h>
#include <cmath>

class Rock : public BasicShape {
    bool shadow;
    
public:
    Rock(std::string, bool);
    ~Rock();
    
    void Update(float dt);
    void Render();
};

#endif /* Rock_hpp */
