/*
* 使用EventAPI监听游戏内容
*/

#include "Header.h"
#include <EventAPI.h>

void Listener() {

    /*
    * 例如，玩家加入服务器后，取得进度 "add:hello_world"
    */
    Event::PlayerJoinEvent::subscribe([](const Event::PlayerJoinEvent& ev) {
        auto pl = ev.mPlayer;
        GrantAdvancement(pl, "add:hello_world");
        return true;
    });
}