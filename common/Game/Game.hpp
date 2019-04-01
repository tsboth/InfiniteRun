// Game.hpp

#ifndef __GameDefs__
#define __GameDefs__

#include <IvGame.h>
#include <IvRendererHelp.h>

#include "Player.hpp"
#include "Background.hpp"
#include "Rock.hpp"
#include "BasicShape.hpp"
#include "Fog.hpp"
#include "Sun.hpp"
#include "SunLight.hpp"

class Player;
class Background;
class Rock;
class Fog;
class Sun;
class SunLight;

class Game : public IvGame {
public:
    Game();
    ~Game();
    bool PostRendererInitialize();
    
    Player*         mPlayer;
    Player*         mPlayersShadow;
    Background*     mBackground;
    Rock*           mRock;
    Rock*           mRockShadow;
    Fog*            mFog;
    Sun*            mSun;
    SunLight*       mSunLight;
    
protected:
    virtual void UpdateObjects(float dt);
    virtual void Render();
    
private:
    Game( const Game& other );
    Game& operator=( const Game& other );
    
    bool isCollision();
};

#endif
