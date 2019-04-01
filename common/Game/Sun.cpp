//
//  Sun.cpp
//  Game
//
//  Created by Tamas Both - (p) on 29/03/2019.
//

#include "Sun.hpp"

Sun::Sun() {
    mVertices.resize(4);
    
    mVertices[0].position = {-3.0f, 1.5f, 0.0f};
    mVertices[1].position = {3.0f, 1.5f, 0.0f};
    mVertices[2].position = {-3.0f, 7.5f, 0.0f};
    mVertices[3].position = {3.0f, 7.5f, 0.0f};
    
    mVertices[0].texturecoord = {0.0f, 0.0f};
    mVertices[1].texturecoord = {1.0f, 0.0f};
    mVertices[2].texturecoord = {0.0f, 1.0f};
    mVertices[3].texturecoord = {1.0f, 1.0f};
    
    mVertices[0].color = {255, 0, 0, 0};
    mVertices[1].color = {0, 255, 0, 0};
    mVertices[2].color = {0, 0, 255, 0};
    mVertices[3].color = {255, 255, 0, 0};
    
    initializeVertexBuffer();
    initializeShader("shaders/sun/sunShader");
}

Sun::~Sun() {
    
}

void Sun::Update(float dt) {
    
}

void Sun::Render() {
    IvRenderer::mRenderer->SetWorldMatrix(mTransform);
    IvRenderer::mRenderer->SetShaderProgram(mShader);
    
    IvRenderer::mRenderer->Draw(kTriangleStripPrim, mVertexBuffer, 4);
}

