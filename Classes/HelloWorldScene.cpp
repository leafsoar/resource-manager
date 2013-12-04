#include "HelloWorldScene.h"

#include "Resources.h"
#include "Assets/AssetLoader.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(si_CloseNormal,
                                           si_CloseSelected,
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);

    auto sprite = Sprite::create(si_HelloWorld);

    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(sprite, 0);
    
    // 添加新的图片
//    auto jungle = Sprite::create(si_JungleLeft);
    auto jungle = AssetLoader::createSprite(si_JungleLeft);
    jungle->setAnchorPoint(Point(0, 0));
    addChild(jungle);
    
//    auto hello = Sprite::create(si_HelloWorld);
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(sp_grossini_family, si_grossini_family);
    auto father = Sprite::createWithSpriteFrameName(si_grossinis_sister1);
//    auto father = AssetLoader::createSprite(si_sister2);
    father->setPosition(Point(80, 80));
    addChild(father);
    
    return true;
}

void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
