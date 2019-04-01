// BasicShape.cpp

#include "BasicShape.hpp"

BasicShape::BasicShape() {
    isDead = false;
}

BasicShape::~BasicShape() {
    IvRenderer::mRenderer->GetResourceManager()->Destroy(mVertexBuffer);
    IvRenderer::mRenderer->GetResourceManager()->Destroy(mShader);
    
    for (IvTexture* i : mTextures)
        IvRenderer::mRenderer->GetResourceManager()->Destroy(i);
}

void BasicShape::initializeVertexBuffer() {
    // sets up the vertexbuffer
    size_t currentOffset = IvStackAllocator::mScratchAllocator->GetCurrentOffset();
    IvTCPVertex* dataPtr = (IvTCPVertex*)IvStackAllocator::mScratchAllocator->Allocate(kIvVFSize[kTCPFormat] * 4);
    
    for (unsigned int i = 0; i < 4; i++) {
        dataPtr[i].position = mVertices[i].position;
        dataPtr[i].color = mVertices[i].color;
        dataPtr[i].texturecoord = mVertices[i].texturecoord;
    }
    
    mVertexBuffer = IvRenderer::mRenderer->GetResourceManager()->CreateVertexBuffer(kTCPFormat, 4, dataPtr, kImmutableUsage);
    IvStackAllocator::mScratchAllocator->Reset(currentOffset);
}

void BasicShape::initializeShader(std::string shaderName) {
    // sets up the shaders
    mShader = IvRenderer::mRenderer->GetResourceManager()->CreateShaderProgram(
        IvRenderer::mRenderer->GetResourceManager()->CreateVertexShaderFromFile(shaderName.c_str()),
        IvRenderer::mRenderer->GetResourceManager()->CreateFragmentShaderFromFile(shaderName.c_str()));
}

void BasicShape::loadTexture(const char* filename) {
    IvImage* image = IvImage::CreateFromFile(filename);
    
    if (image)
    {
        mTextures.push_back(IvRenderer::mRenderer->GetResourceManager()->CreateTexture((
            image->GetBytesPerPixel() == 4) ? kRGBA32TexFmt : kRGB24TexFmt,
            image->GetWidth(), image->GetHeight(), image->GetPixels(), kImmutableUsage));
        
        delete image;
        image = 0;
    }
}

std::vector<float> BasicShape::getPositions() {
    std::vector<float> positions;
    
    positions.push_back(xPosition);
    positions.push_back(xPosition + abs(mVertices[0].position[0] - mVertices[1].position[0]));
    positions.push_back(yPosition);
    positions.push_back(yPosition + abs(mVertices[0].position[1] - mVertices[2].position[1]));
    
    return positions;
}

void BasicShape::setIsDead(bool t) {
    isDead = t;
}
