//
//  Sun.cpp
//  Game
//
//  Created by Tamas Both - (p) on 29/03/2019.
//

#include "SunLight.hpp"

SunLight::SunLight(Player* mPlayer) {
    xPosition = 0;
    direction = true;
    mVertices.resize(4);
    this->mPlayer = mPlayer;
    
    mVertices[0].position = {-0.58f, -1.0f, 0.0f};
    mVertices[1].position = {0.58f, -1.0f, 0.0f};
    mVertices[2].position = {-0.58f, 1.0f, 0.0f};
    mVertices[3].position = {0.58f, 1.0f, 0.0f};
    
    mVertices[0].texturecoord = {0.0f, 0.0f};
    mVertices[1].texturecoord = {1.0f, 0.0f};
    mVertices[2].texturecoord = {0.0f, 1.0f};
    mVertices[3].texturecoord = {1.0f, 1.0f};
    
    mVertices[0].color = {255, 0, 0, 0};
    mVertices[1].color = {0, 255, 0, 0};
    mVertices[2].color = {0, 0, 255, 0};
    mVertices[3].color = {255, 255, 0, 0};
    
    initializeVertexBuffer();
    initializeShader("shaders/sun/sunLightShader");
}

SunLight::~SunLight() {
    
}

void SunLight::Update(float dt) {
    xPosition = mPlayer->getXPosition() / 220. + 0.0488;
}

void SunLight::Render() {
    IvRenderer::mRenderer->SetShaderProgram(mShader);
    IvUniform* posUniform = mShader->GetUniform("xPosition");
    posUniform->SetValue(xPosition, 0);
    
    IvRenderer::mRenderer->Draw(kTriangleStripPrim, mVertexBuffer, 4);
}

