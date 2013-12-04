//
//  AssetLoader.h
//  ResMgr
//
//  Created by leafsoar on 02/12/2013.
//
//

#ifndef __ResMgr__AssetLoader__
#define __ResMgr__AssetLoader__

#include "cocos2d.h"

using namespace cocos2d;

class AssetLoader: public Object{
public:
    static Sprite* createSprite(const std::string& name);
    
private:
    static AssetLoader* getInstance();
    bool init();
    
    bool fileExists(const std::string& filename);
    std::string getTexturePlist(const std::string& name);
    std::string getTextureImage(const std::string& name);
    
private:
    Dictionary* _fileDict;              // 文件列表
    Dictionary* _texturePlistDict;           // 打包资源到文件的映射
    Dictionary* _textureImageDict;       // 打包资源plist 到图片的映射
};

#endif /* defined(__ResMgr__AssetLoader__) */
