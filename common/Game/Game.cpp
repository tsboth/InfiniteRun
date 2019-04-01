// Game.cpp

#include "Game.hpp"
#include <iostream>

bool IvGame::Create() {
    IvGame::mGame = new Game();
    return ( IvGame::mGame != 0 );
}

Game::Game() : IvGame() {
    mPlayer = 0;
    mBackground = 0;
    mRock = 0;
    mPlayersShadow = 0;
    mRockShadow = 0;
    mFog = 0;
    mSun = 0;
    mSunLight = 0;
}

Game::~Game() {
    delete mPlayer;
    mPlayer = 0;
    
    delete mBackground;
    mBackground = 0;
    
    delete mRock;
    mRock = 0;
    
    delete mPlayersShadow;
    mPlayersShadow= 0;
    
    delete mRockShadow;
    mRockShadow = 0;
    
    delete mFog;
    mFog = 0;
    
    delete mSun;
    mSun = 0;
    
    delete mSunLight;
    mSunLight = 0;
}

bool Game::PostRendererInitialize() {
    if (!IvGame::PostRendererInitialize())
        return false;
    
    mPlayer = new Player("shaders/player/playerShader", false);
    if (!mPlayer)
        return false;
    
    mFog = new Fog();
    if (!mFog)
        return false;
    
    mSun = new Sun();
    if (!mSun)
        return false;
    
    mSunLight = new SunLight(mPlayer);
    if (!mSunLight)
        return false;
    
    mBackground = new Background(mFog, mSun);
    if (!mBackground)
        return false;
    
    mRock = new Rock("shaders/rock/rockShader", false);
    if (!mRock)
        return false;
    
    mRockShadow = new Rock("shaders/shadow/shadowShader", true);
    if (!mRockShadow)
        return false;
    
    mPlayersShadow = new Player("shaders/shadow/shadowShader", true);
    if (!mPlayersShadow)
        return false;
    
    ::IvSetDefaultLighting();
    IvRendererOGL::mRenderer->SetBlendFunc(kSrcAlphaBlendFunc, kOneMinusSrcAlphaBlendFunc, kAddBlendOp);
    
    return true;
}

void Game::UpdateObjects(float dt) {
    mBackground->Update(dt);
    mRockShadow->Update(dt);
    mPlayersShadow->Update(dt);
    mRock->Update(dt);
    mPlayer->Update(dt);
    mFog->Update(dt);
    mSun->Update(dt);
    mSunLight->Update(dt);
    
    if (isCollision()) {
        mBackground->setIsDead(true);
        mPlayer->setIsDead(true);
        mPlayersShadow->setIsDead(true);
        mBackground->setIsDead(true);
        mRock->setIsDead(true);
        mRockShadow->setIsDead(true);
        mFog->setIsDead(true);
    }
}

void Game::Render() {
    IvSetDefaultViewer(0.0f, 0.0f, 14.0f);
    
    mBackground->Render();
    mRockShadow->Render();
    mRock->Render();
    mPlayer->Render();
    mPlayersShadow->Render();
    mSunLight->Render();
}

bool Game::isCollision() {
    std::vector<float> playerPositions = mPlayer->getPositions();
    std::vector<float> rockPositions = mRock->getPositions();
    
    if ((playerPositions[1] - 0.9 > rockPositions[0] && playerPositions[1] - 0.9 < rockPositions[1]) ||
        (playerPositions[0] + 0.9 > rockPositions[0] && playerPositions[0] + 0.9 < rockPositions[1]))
        if (!(playerPositions[2] + 2.4 > rockPositions[3]))
            return true;
    
    return false;
}
