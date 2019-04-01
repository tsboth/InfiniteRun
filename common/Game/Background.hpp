// Background.hpp

#ifndef Background_hpp
#define Background_hpp

#include "BasicShape.hpp"
#include "Fog.hpp"
#include "Sun.hpp"

class Background : public BasicShape {
    IvUniform* speedUniform;
    Fog* mFog;
    Sun* mSun;
    float speed;
    
    void drawParallax(int);
    
public:
    Background(Fog*, Sun*);
    ~Background();
    
    void Update( float dt );
    void Render();
};

#endif /* Background_hpp */
