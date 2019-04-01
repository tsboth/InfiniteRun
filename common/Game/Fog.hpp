//
//  Fog.hpp
//  Game
//
//  Created by Tamas Both - (p) on 28/03/2019.
//

#ifndef Fog_hpp
#define Fog_hpp

#include "BasicShape.hpp"

class Fog : public BasicShape {
    float updateRate;
    float updateRate2;
    
public:
    Fog();
    ~Fog();
    
    void Update(float);
    void Render();
};

#endif /* Fog_hpp */
