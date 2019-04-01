//
//  Fog.cpp
//  Game
//
//  Created by Tamas Both - (p) on 28/03/2019.
//

#include "Fog.hpp"

Fog::Fog() {
    updateRate = 0;
    
    mVertices.resize(4);
    
    mVertices[0].position = {-11.0f, -2.8f, 0.0f};
    mVertices[1].position = {22.0f, -2.8f, 0.0f};
    mVertices[2].position = {-11.0f, -1.2f, 0.0f};
    mVertices[3].position = {22.0f, -1.2f, 0.0f};
    
    mVertices[0].texturecoord = {0.0f, 0.0f};
    mVertices[1].texturecoord = {1.0f, 0.0f};
    mVertices[2].texturecoord = {0.0f, 1.0f};
    mVertices[3].texturecoord = {1.0f, 1.0f};
    
    mVertices[0].color = {255, 0, 0, 0};
    mVertices[1].color = {0, 255, 0, 0};
    mVertices[2].color = {0, 0, 255, 0};
    mVertices[3].color = {255, 255, 0, 0};
    
    initializeVertexBuffer();
    initializeShader("shaders/fog/fogShader");
}

Fog::~Fog() {
    
}

void Fog::Update(float dt) {
    updateRate += 0.1;
}

void Fog::Render() {
    IvRenderer::mRenderer->SetWorldMatrix(mTransform);
    IvRenderer::mRenderer->SetShaderProgram(mShader);
    
    IvUniform* resolution = mShader->GetUniform("u_resolution3");
    IvUniform* time = mShader->GetUniform("u_time");
    IvUniform* time2 = mShader->GetUniform("u_time2");
    
    resolution->SetValue({256, 256, 0}, 0);
    time->SetValue(updateRate, 0);
    
    if (!isDead)
        updateRate2 = updateRate;
    
    time2->SetValue(updateRate2, 0);
    
    IvRenderer::mRenderer->Draw(kTriangleStripPrim, mVertexBuffer, 4);
}
