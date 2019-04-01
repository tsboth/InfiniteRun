//  BasicShape.hpp

#ifndef BasicShape_hpp
#define BasicShape_hpp

#include <IvMatrix44.h>
#include <IvMatrix33.h>
#include <IvShaderProgram.h>
#include <IvResourceManager.h>
#include <IvRenderer.h>
#include <IvRendererOGL.h>
#include <IvEventHandler.h>
#include <IvMath.h>
#include <IvVector3.h>
#include <IvRendererHelp.h>
#include <IvTexture.h>
#include <IvImage.h>
#include <IvShaderProgram.h>
#include <IvFragmentShader.h>
#include <IvUniform.h>
#include <IvVertexShader.h>
#include <IvIndexBuffer.h>
#include <IvTexture.h>
#include <IvVertexBuffer.h>
#include <IvStackAllocator.h>

#include <cstdlib>
#include <vector>
#include <string>

class BasicShape {
    
protected:
    std::vector<IvTCPVertex> mVertices;
    std::vector<IvTexture*> mTextures;
    IvVertexBuffer* mVertexBuffer;
    IvShaderProgram* mShader;
    IvUniform* texUniform;
    IvMatrix44 mTransform;
    float xPosition;
    float yPosition;
    bool isDead;
    
    void initializeVertexBuffer();
    void initializeShader(std::string);
    void loadTexture(const char*);
    
public:
    BasicShape();
    ~BasicShape();
    
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    
    std::vector<float> getPositions();
    void setIsDead(bool);
};


#endif /* BasicShape_hpp */
