#include <LoggerAPI.h>
#include "version.h"
#include <ServerAPI.h>
#include <EventAPI.h>
#include "Header.h"
#include <mc/ResourcePackRepository.hpp>

extern Logger logger;

//前置插件检测，如果无法找到Advancements前置插件，则无法正常加载
void RegAdvs() {
    if (ll::getPlugin("Advancements")) {
        InitAdvancements();
    }
    else {
        logger.error("无法加载！ 未找到前置插件 Advancements ！");
        logger.error("请检查前置插件，并且不要随意修改插件名字！");
    }
}

void PluginInit()
{
    InitLanguage();
    Event::ResourcePackInitEvent::subscribe([](const Event::ResourcePackInitEvent& ev) {
        RegAdvs();
        //如需加载资源包图标，请取消下面一行注释，并将路径中的AdvancementsExpansionTemplate改为对应插件文件夹（资源包请自制）
        //ev.mRepo->setCustomResourcePackPath(PackType::PackType_Resources, "./plugins/AdvancementsExpansionTemplate/resource_pack");
        return true;
    });
    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent) {
        Listener();
        return true;
    });
}
