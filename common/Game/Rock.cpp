//  Rock.cpp

#include "Rock.hpp"

Rock::Rock(std::string shader, bool shadow) {
    xPosition = 15.0;
    yPosition = -2.0;
    this->shadow = shadow;
    
    mVertices.resize(4);
    
    if (!shadow) {
        mVertices[0].position = {15.0f, -3.85f, 0.0f};
        mVertices[1].position = {17.0f, -3.85f, 0.0f};
        mVertices[2].position = {15.0f, -2.35f, 0.0f};
        mVertices[3].position = {17.0f, -2.35f, 0.0f};
        
        mVertices[0].texturecoord = {0.0f, 0.0f};
        mVertices[1].texturecoord = {1.0f, 0.0f};
        mVertices[2].texturecoord = {0.0f, 1.0f};
        mVertices[3].texturecoord = {1.0f, 1.0f};
        
        loadTexture("textures/rock/rock.tga");
    }
    else {
        mVertices[0].position = {15.0f, -3.6f, 2.0f};
        mVertices[1].position = {17.0f, -3.6f, 2.0f};
        mVertices[2].position = {15.0f, -3.6f, -0.1f};
        mVertices[3].position = {17.0f, -3.6f, -0.1f};
        
        mVertices[0].texturecoord = {0.0f, 1.0f};
        mVertices[1].texturecoord = {1.0f, 1.0f};
        mVertices[2].texturecoord = {0.0f, 0.0f};
        mVertices[3].texturecoord = {1.0f, 0.0f};
        
        loadTexture("textures/rock/rockShadow.tga");
    }
    
    mVertices[0].color = {255, 0, 0, 0};
    mVertices[1].color = {0, 255, 0, 0};
    mVertices[2].color = {0, 0, 255, 0};
    mVertices[3].color = {255, 255, 0, 0};
    
    initializeVertexBuffer();
    initializeShader(shader.c_str());
}

Rock::~Rock() {
    
}

void Rock::Update(float dt) {
    if (!isDead) {
        IvMatrix44 xlate;
        IvVector3 xlatevector(-0.175, 0, 0);
        xPosition -= 0.175;
        xlate.Translation(xlatevector);
        
        if (mTransform(0, 3) < -40.0) {
            mTransform.Identity();
            xPosition = 15.0;
        }
        
        mTransform = xlate * mTransform;
    }
}

void Rock::Render() {
    IvRenderer::mRenderer->SetWorldMatrix(mTransform);
    IvRenderer::mRenderer->SetShaderProgram(mShader);
    texUniform = mShader->GetUniform("Texture");
    texUniform->SetValue(mTextures[0]);
    
    IvRenderer::mRenderer->Draw(kTriangleStripPrim, mVertexBuffer, 4);
}
