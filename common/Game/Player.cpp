// Player.cpp

#include "Player.hpp"
#include <iostream>

Player::Player(std::string shader, bool shadow)
{
    textureIndex = 0;
    textureUpdateRate = 0;
    xPosition = -10;
    yPosition = -3.5;
    isJumping = false;
    deadtexture = false;
    this->shadow = shadow;
    
    mVertices.resize(4);
    
    if (!shadow) {
        mVertices[0].position = {-10.0f, -3.5f, 0.0f};
        mVertices[1].position = {-8.0f, -3.5f, 0.0f};
        mVertices[2].position = {-10.0f, -1.0f, 0.0f};
        mVertices[3].position = {-8.0f, -1.0f, 0.0f};
        
        mVertices[0].texturecoord = {0.0f, 0.0f};
        mVertices[1].texturecoord = {1.0f, 0.0f};
        mVertices[2].texturecoord = {0.0f, 1.0f};
        mVertices[3].texturecoord = {1.0f, 1.0f};
    }
    else {
        mVertices[0].position = {-10.0f, -3.35f, 3.5f};
        mVertices[1].position = {-8.0f, -3.35f, 3.5f};
        mVertices[2].position = {-10.0f, -3.35f, 0.0f};
        mVertices[3].position = {-8.0f, -3.35f, 0.0f};
        
        mVertices[0].texturecoord = {0.0f, 1.0f};
        mVertices[1].texturecoord = {1.0f, 1.0f};
        mVertices[2].texturecoord = {0.0f, 0.0f};
        mVertices[3].texturecoord = {1.0f, 0.0f};
    }
    
    mVertices[0].color = {255, 0, 0, 0};
    mVertices[1].color = {0, 255, 0, 0};
    mVertices[2].color = {0, 0, 255, 0};
    mVertices[3].color = {255, 255, 0, 0};
    
    initializeVertexBuffer();
    initializeShader(shader.c_str());
    
    loadTexture("textures/player/Run__000.tga");
    loadTexture("textures/player/Run__001.tga");
    loadTexture("textures/player/Run__002.tga");
    loadTexture("textures/player/Run__003.tga");
    loadTexture("textures/player/Run__004.tga");
    loadTexture("textures/player/Run__005.tga");
    loadTexture("textures/player/Run__006.tga");
    loadTexture("textures/player/Run__007.tga");
    loadTexture("textures/player/Run__008.tga");
    loadTexture("textures/player/Run__009.tga");
    loadTexture("textures/player/Slide__000.tga");
    loadTexture("textures/player/Jump__000.tga");
    loadTexture("textures/player/Jump__001.tga");
    loadTexture("textures/player/Jump__002.tga");
    loadTexture("textures/player/Jump__003.tga");
    loadTexture("textures/player/Jump__004.tga");
    loadTexture("textures/player/Jump__005.tga");
    loadTexture("textures/player/Jump__006.tga");
    loadTexture("textures/player/Jump__007.tga");
    loadTexture("textures/player/Jump__008.tga");
    loadTexture("textures/player/Jump__009.tga");
    loadTexture("textures/player/Dead__000.tga");
    loadTexture("textures/player/Dead__001.tga");
    loadTexture("textures/player/Dead__002.tga");
    loadTexture("textures/player/Dead__003.tga");
    loadTexture("textures/player/Dead__004.tga");
    loadTexture("textures/player/Dead__005.tga");
    loadTexture("textures/player/Dead__006.tga");
    loadTexture("textures/player/Dead__007.tga");
    loadTexture("textures/player/Dead__008.tga");
    loadTexture("textures/player/Dead__009.tga");
}

Player::~Player() {
    
}

void Player::Update(float dt) {
    textureUpdateRate++;
    
    if (isDead) {
        if (!shadow) {
            mVertices[0].position = {-10.5f, -3.9f, 0.0f};
            mVertices[1].position = {-7.5f, -3.9f, 0.0f};
            mVertices[2].position = {-10.5f, -1.15f, 0.0f};
            mVertices[3].position = {-7.5f, -1.15f, 0.0f};
            
            mTransform(1, 3) = 0;
        }
        else {
            mVertices[0].position = {-10.5f, -3.4f, 3.9f};
            mVertices[1].position = {-7.5f, -3.4f, 3.9f};
            mVertices[2].position = {-10.5f, -3.4f, 0.0f};
            mVertices[3].position = {-7.5f, -3.4f, 0.0f};
            
            mTransform(2, 3) = 0;
        }
        initializeVertexBuffer();
        
        if (!deadtexture) {
            textureIndex = 21;
            deadtexture = true;
        }
        textureUpdateRate = textureUpdateRate % 3;
        if(textureUpdateRate == 0) {
            textureIndex++;
            if (textureIndex > 30)
                textureIndex = 30;
        }
    }
    else {
        IvMatrix44 xlate;
        float x = 0.0f, y = 0.0f;
        
        runRate = 3;
        isSliding = false;
        
        if (IvGame::mGame->mEventHandler->IsKeyDown('a')) {
            if (mTransform(0, 3) > -0.3) {
                x -= 10.0f*dt;
                xPosition -= 10.0f*dt;
                runRate = 4;
            }
        }
        if (IvGame::mGame->mEventHandler->IsKeyDown('d')) {
            if (mTransform(0, 3) < 18.0) {
                x += 10.0f*dt;
                xPosition += 10.0f*dt;
                runRate = 2;
            }
        }
        
        if (IvGame::mGame->mEventHandler->IsKeyDown('s')) {
            if (!isJumping) {
                isSliding = true;
                textureIndex = 10;
                
                if (!shadow) {
                    mVertices[2].position = {-10.0f, -1.70f, 0.0f};
                    mVertices[3].position = {-8.0f, -1.70f, 0.0f};
                }
                else {
                    mVertices[0].position = {-10.0f, -3.5f, 1.7f};
                    mVertices[1].position = {-8.0f, -3.5f, 1.7f};
                }
                initializeVertexBuffer();
            }
        }
        
        if (IvGame::mGame->mEventHandler->IsKeyReleased('s')) {
            if (!shadow) {
                mVertices[2].position = {-10.0f, -1.0f, 0.0f};
                mVertices[3].position = {-8.0f, -1.0f, 0.0f};
            }
            else {
                mVertices[0].position = {-10.0f, -3.5f, 3.5f};
                mVertices[1].position = {-8.0f, -3.5f, 3.5f};
            }
            initializeVertexBuffer();
        }
        
        if (IvGame::mGame->mEventHandler->IsKeyPressed('w')) {
            if (!isJumping && !isSliding) {
                jumpRate = 30;
                textureIndex = 11;
                isJumping = true;
            }
        }
        
        if (isJumping) {
            jumpRate--;
            isJumping = jumpRate != 0;
            if (jumpRate >= 15) {
                y += pow((float)jumpRate / 7.0, 2.0) * dt;
                yPosition += pow((float)jumpRate / 7.0, 2.0) * dt;
            }
            else {
                y -= pow(((float)(29 - jumpRate)) / 7.0, 2.0) * dt;
                yPosition -= pow(((float)(29 - jumpRate)) / 7.0, 2.0) * dt;
            }
            textureUpdateRate = textureUpdateRate % 3;
            if (textureUpdateRate == 0) {
                textureIndex++;
                if (textureIndex > 20)
                    textureIndex = 11;
            }
        }
        else if (!isSliding) {
            textureUpdateRate = textureUpdateRate % runRate;
            if(textureUpdateRate == 0) {
                textureIndex++;
                textureIndex = textureIndex % 10;
            }
        }
        
        if (shadow) {
            IvVector3 xlatevector(x, 0, y);
            xlate.Translation(xlatevector);
        }
        else {
            IvVector3 xlatevector(x, y, 0);
            xlate.Translation(xlatevector);
        }
            
        mTransform = xlate * mTransform;
    }
}

void Player::Render() {
    IvRenderer::mRenderer->SetWorldMatrix(mTransform);
    IvRenderer::mRenderer->SetShaderProgram(mShader);
    texUniform = mShader->GetUniform("Texture");
    texUniform->SetValue(mTextures[textureIndex]);
    
    IvRenderer::mRenderer->Draw(kTriangleStripPrim, mVertexBuffer, 4);
}

float Player::getXPosition() {
    return xPosition;
}
