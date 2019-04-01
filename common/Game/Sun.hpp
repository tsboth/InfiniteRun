//
//  Sun.hpp
//  Game
//
//  Created by Tamas Both - (p) on 29/03/2019.
//

#ifndef Sun_hpp
#define Sun_hpp

#include "BasicShape.hpp"

class Sun : BasicShape {
public:
    Sun();
    ~Sun();
    
    void Update(float);
    void Render();
};

#endif /* Sun_hpp */
