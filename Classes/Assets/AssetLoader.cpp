//
//  AssetLoader.cpp
//  ResMgr
//
//  Created by leafsoar on 02/12/2013.
//
//

#include "AssetLoader.h"
#include "editor-support/cocostudio/CSContentJsonDictionary.h"
#include "editor-support/cocostudio/DictionaryHelper.h"

#include "Resources.h"

using namespace cocostudio;

Sprite* AssetLoader::createSprite(const std::string& name){
    if (AssetLoader::getInstance()->fileExists(name)){
        return Sprite::create(name);
    }
    log("create sprite: %s", name.c_str());
    std::string plistfile = AssetLoader::getInstance()->getTexturePlist(name);
    std::string imagefile = AssetLoader::getInstance()->getTextureImage(name);
    log("plist: %s, image: %s", plistfile.c_str(), imagefile.c_str());
    if (plistfile != "" && imagefile != ""){
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistfile, imagefile);
        return Sprite::createWithSpriteFrameName(name);
    }
    return nullptr;
}

AssetLoader* AssetLoader::getInstance(){
    static AssetLoader* m_assetLoader = nullptr;
    if (m_assetLoader == nullptr){
        m_assetLoader = new AssetLoader();
        m_assetLoader->init();
    }
    return m_assetLoader;
}

bool AssetLoader::init(){
    // 初始化 文件字典
    JsonDictionary *jsonDict = new JsonDictionary();
    String* fileContent = String::createWithContentsOfFile(sjs_file_list);
    jsonDict->initWithDescription(fileContent->getCString());
    
    DictionaryHelper* dicHelper = DICTOOL;
    
    _fileDict = Dictionary::create();
    int file_idx = dicHelper->getArrayCount_json(jsonDict, file_name);
    for (int i = 0; i < file_idx; i++){
        std::string name = dicHelper->getStringValueFromArray_json(jsonDict, file_name, i);
        std::string index = dicHelper->getStringValueFromArray_json(jsonDict, file_index, i);
        _fileDict->setObject(String::create(index), name);
    }
    log("file count: %d", file_idx);
    
    _texturePlistDict = Dictionary::create();
    int texture_idx = dicHelper->getArrayCount_json(jsonDict, texture_name);
    for (int i = 0; i < texture_idx; i++){
        std::string name = dicHelper->getStringValueFromArray_json(jsonDict, texture_name, i);
        std::string plist = dicHelper->getStringValueFromArray_json(jsonDict, texture_plist, i);
        _texturePlistDict->setObject(String::create(plist), name);
    }
    log("texture count: %d", texture_idx);
    
    _textureImageDict = Dictionary::create();
    for (int i = 0; i < texture_idx; i++){
        std::string name = dicHelper->getStringValueFromArray_json(jsonDict, texture_name, i);
        std::string image = dicHelper->getStringValueFromArray_json(jsonDict, texture_image, i);
        _textureImageDict->setObject(String::create(image), name);
    }
    
    CC_SAFE_DELETE(jsonDict);
    
    return true;
}

bool AssetLoader::fileExists(const std::string &filename){
    return _fileDict->objectForKey(filename) != nullptr;
}

std::string AssetLoader::getTexturePlist(const std::string &name){
    Object* objPd = _texturePlistDict->objectForKey(name);
    if (objPd != nullptr){
        std::string tt_idx = dynamic_cast<String*>(objPd)->getCString();
        DictElement* de = nullptr;
        CCDICT_FOREACH(_fileDict, de){
            if (de != nullptr){
                String* str = dynamic_cast<String*>(de->getObject());
                if (str->getCString() == tt_idx){
                    return de->getStrKey();
                }
            }
        }
    }
    return "";
}

std::string AssetLoader::getTextureImage(const std::string &name){
    Object* obj = _textureImageDict->objectForKey(name);
    if (obj != nullptr){
        std::string image = dynamic_cast<String*>(obj)->getCString();
        DictElement* de = nullptr;
        CCDICT_FOREACH(_fileDict, de){
            if (de != nullptr){
                String* str = dynamic_cast<String*>(de->getObject());
                if (str->getCString() == image){
                    return de->getStrKey();
                }
            }
        }
    }
    return "";
}
