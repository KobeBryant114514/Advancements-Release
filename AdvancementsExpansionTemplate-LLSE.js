/**
 * 本插件为Advancements插件自定义进度的模板插件。
 * 你可以使用本模板来注册更多进度，为Advancements写扩展包。
 * 
 * 
 */

ll.registerPlugin(     //注册插件
    "CustomAdvancements-Template",
    "自定义进度模板",
    [1, 1, 0],
    {"Author": "Tsubasa6848"}
);

const AdvancementsAPI = {                      //API导入
    RegNewAdvancementClass:ll.import("Advancements", "RegNewAdvancementClass"),
    RegNewAdvancement:ll.import("Advancements", "RegNewAdvancement"),
    GrantAdvancement:ll.import("Advancements", "GrantAdvancement"),
    RevokeAdvancemnet:ll.import("Advancements", "RevokeAdvancemnet"),
    CheckAdvancement:ll.import("Advancements", "CheckAdvancement"),
    GetPlayerFinishedAdvancements:ll.import("Advancements", "GetPlayerFinishedAdvancements"),
    GetLoadedAdvancements:ll.import("Advancements", "GetLoadedAdvancements"),
}

/**
 * 函数原型  AdvancementsAPI.RegNewAdvancementClass(advclass, advclassname, advclassdesc, advclassicon)
 * @param advclass 进度分类（命名空间）
 * @param advclassname 分类名称
 * @param advclassdesc 分类描述
 * @param advclassicon 分类图标(填""则为无图标)
 */
AdvancementsAPI.RegNewAdvancementClass("test", "测试分类", "一个用于测试进度的分类", "textures/blocks/crying_obsidian");
//注册一个新的进度分类。


/**
 * 函数原型  AdvancementsAPI.RegNewAdvancement(advid, advname, advdesc, iconpath, type, isHidden, exp)
 * @param advid 进度命名空间ID
 * 命名空间id格式为 xxx:yyy（例如"test:test1"）
 * 其中xxx必须为已注册的进度分类【内置了"story","nether","end","adventure","husbandry"】，你可以自定义注册新的分类
 * yyy为任意字符串，但是命名空间id（xxx:yyy）不能重复
 * @param advname 进度名称
 * @param advdesc 进度描述
 * @param iconpath1 未完成时进度图标(填""则为无图标)
 * @param iconpath2 完成后进度图标(填""则为无图标)
 * @param type 进度类型（0为普通进度， 1为目标进度， 2为挑战进度）
 * @param isHidden 是否为隐藏进度
 * @param exp 进度经验奖励（这只是描述中的奖励值（仅挑战进度有此描述），不代表实际值，实际值需要后续给予进度时设置）
 */
AdvancementsAPI.RegNewAdvancement("test:player_die", "首次暴毙", "第一次暴毙","textures/blocks/crying_obsidian", "textures/items/ghast_tear", 0, false, 0);
//注册一个进度

mc.listen("onPlayerDie", (pl, source) => {
    AdvancementsAPI.GrantAdvancement(pl, "test:player_die", 0);
    //给予玩家进度"test:player_die"，奖励经验为0 （此处为实际奖励经验）
    //你只需要监听某个行为即可，触发某行为给予进度。
    //无论该行为触发多少次，进度只会给予一次
});

//AdvancementsAPI.RevokeAdvancemnet(player, advid);
//撤销玩家进度

//AdvancementsAPI.CheckAdvancement(player, advid);
//检查玩家是否已获得某个进度
//给予进度不需要检查，此API提供用于类似Java版MOD，提供通过进度解锁区域或者解锁更多功能的作用。
//正常情况下无需使用

//AdvancementsAPI.GetPlayerFinishedAdvancements(uuid);
//获取一个玩家已完成的进度列表（通过玩家uuid）

//AdvancementsAPI.GetLoadedAdvancements();
//获取已加载的进度列表
