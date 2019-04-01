// Player.h

#ifndef __PlayerDefs__
#define __PlayerDefs__

#include "BasicShape.hpp"

#include <IvGame.h>
#include <cmath>

class Player : public BasicShape {
    int textureIndex;
    int textureUpdateRate;
    bool isJumping;
    bool isSliding;
    bool shadow;
    bool deadtexture;
    int jumpRate;
    int runRate;

public:
    Player(std::string, bool);
    ~Player();
    
    void Update(float dt);
    void Render();
    
    float getXPosition();
};

#endif
