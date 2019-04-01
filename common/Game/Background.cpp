// Background.cpp

#include "Background.hpp"
#include <iostream>

Background::Background(Fog* mFog, Sun* mSun)
{
    speed = 1;
    this->mFog = mFog;
    this->mSun = mSun;
    
    mVertices.resize(4);
    
    mVertices[0].position = {-1.0f, -1.0f, 0.0f};
    mVertices[1].position = {1.0f, -1.0f, 0.0f};
    mVertices[2].position = {-1.0f, 1.0f, 0.0f};
    mVertices[3].position = {1.0f, 1.0f, 0.0f};
    
    mVertices[0].color = {255, 0, 0, 0};
    mVertices[1].color = {0, 255, 0, 0};
    mVertices[2].color = {0, 0, 255, 0};
    mVertices[3].color = {255, 255, 0, 0};
    
    mVertices[0].texturecoord = {0.0f, 1.0f};
    mVertices[1].texturecoord = {1.0f, 1.0f};
    mVertices[2].texturecoord = {0.0f, 0.0f};
    mVertices[3].texturecoord = {1.0f, 0.0f};
    
    initializeVertexBuffer();
    initializeShader("shaders/background/parallaxShader");
    
    loadTexture("textures/background/_11_background.tga");
    loadTexture("textures/background/_10_distant_clouds.tga");
    loadTexture("textures/background/_09_distant_clouds1.tga");
    loadTexture("textures/background/_08_clouds.tga");
    loadTexture("textures/background/_07_huge_clouds.tga");
    loadTexture("textures/background/_06_hill2.tga");
    loadTexture("textures/background/_05_hill1.tga");
    loadTexture("textures/background/_04_bushes.tga");
    loadTexture("textures/background/_03_distant_trees.tga");
    loadTexture("textures/background/_02_trees_and_bushes.tga");
    loadTexture("textures/background/_01_ground.tga");
}

Background::~Background() {
    
}

void Background::Update(float dt) {
    if (!isDead)
        speed += 0.05 * dt;
}

void Background::Render() {
    // draw geometry
    IvRendererOGL::mRenderer->SetDepthWrite(false);
    IvRendererOGL::mRenderer->SetDepthTest(kDisableDepthTest);
    
    for (int i = 0; i < 11; i++)
        drawParallax(i);
    
    IvRendererOGL::mRenderer->SetDepthWrite(true);
    IvRendererOGL::mRenderer->SetDepthTest(kLessEqualDepthTest);
}

void Background::drawParallax(int index) {
    IvUniform* speedUniform;
    
    IvRenderer::mRenderer->SetShaderProgram(mShader);
    texUniform = mShader->GetUniform("Texture");
    speedUniform = mShader->GetUniform("speed");

    texUniform->SetValue(mTextures[index]);
    speedUniform->SetValue(speed * (float)index, 0);
    
    IvRenderer::mRenderer->Draw(kTriangleStripPrim, mVertexBuffer, 4);
    
    if (index == 7)
        mFog->Render();
    
    if (index == 0)
        mSun->Render();
}
