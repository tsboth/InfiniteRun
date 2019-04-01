//
//  SunLight.hpp
//  Game
//
//  Created by Tamas Both - (p) on 29/03/2019.
//

#ifndef SunLight_hpp
#define SunLight_hpp

#include "BasicShape.hpp"
#include "Player.hpp"

class SunLight : BasicShape {
    float xPosition;
    bool direction;
    Player* mPlayer;
    
public:
    SunLight(Player*);
    ~SunLight();
    
    void Update(float);
    void Render();
};

#endif /* Sun_hpp */
