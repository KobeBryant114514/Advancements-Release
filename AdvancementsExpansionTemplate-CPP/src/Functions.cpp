#include "Header.h"

/*
* API导入
* 一般不建议修改此处内容
*/
auto RegNewAdvClass = RemoteCall::importAs<void(std::string advclass, std::string advclassname, std::string advclassdesc, std::string advicon)>("Advancements", "RegNewAdvancementClass");
auto RegNewAdv = RemoteCall::importAs<void(std::string advid, std::string advname, std::string advdesc, std::string iconpath1, std::string iconpath2, int type, bool isHidden, int exp)>("Advancements", "RegNewAdvancement");
auto GrantAdv = RemoteCall::importAs<bool(Player* pl, string advid, int exp)>("Advancements", "GrantAdvancement");
auto RevokeAdv = RemoteCall::importAs<bool(Player* pl, string advid)>("Advancements", "RevokeAdvancemnet");
auto CheckAdv = RemoteCall::importAs<bool(Player* pl, string advid)>("Advancements", "CheckAdvancement");
bool GrantAdvancement(Player* pl, string advid, int exp) {
	return GrantAdv(pl, advid, exp);
}
bool CheckAdvancement(Player* pl, string advid) {
	return CheckAdv(pl, advid);
}
void RegNewAdvancementClass(std::string advclass, std::string advclassname, std::string advclassdesc, std::string advicon) {
	return RegNewAdvClass(advclass, advclassname, advclassdesc, advicon);
}
void RegNewAdvancement(std::string advid, std::string advname, std::string advdesc, std::string iconpath1, std::string iconpath2, int type, bool isHidden, int exp) {
	return RegNewAdv(advid, advname, advdesc, iconpath1, iconpath2, type, isHidden, exp);
}
bool RevokeAdvancement(Player* pl, string advid) {
	return RevokeAdv(pl, advid);
}

//初始化语言文件，加载语言文件，此函数必须最先加载(仅需修改加载路径即可)
nlohmann::json LanguageJson;
void InitLanguage() {
	try {
		std::ifstream jsonfile("plugins/AdvancementsExpansionTemplate/Language.json"); //修改此处路径即可
		if (jsonfile) {
			jsonfile >> LanguageJson;
            jsonfile.close();
            return;
		}
		else {
            logger.error("无法初始化语言文件！ 请检查插件文件是否完整。");
			return;
		}
	}
    catch (...) {
        logger.error("初始化语言文件时发生错误！ 请检查插件文件是否完整。");
		return;
    }
}

//翻译语言文件（一般不建议修改此函数）
string GetLanguage(string oristr) {
	try {
		return LanguageJson[oristr].get<string>();
	}
    catch (...) {
		return oristr;
    }
}

//注册进度分类（如需注册新分类，内容示例添加新分类）
void RegClass() {
	//添加一个分类，命名空间前缀为 add
	RegNewAdvancementClass("add", GetLanguage("advancement.class.add"), GetLanguage("advancement.class.add.desc"));
}

//获取进度名称（一般不建议修改此函数）
string GetAdvName(string adv) {
	ReplaceStr(adv, ":", ".");
	auto jsonname = "advancement." + adv;
	return GetLanguage(jsonname);
}

//获取进度描述（一般不建议修改此函数）
string GetAdvDescription(string adv) {
    ReplaceStr(adv, ":", ".");
	auto jsonname = "advancement." + adv + ".desc";
	return GetLanguage(jsonname);
}

//获取进度图标（仅需修改图标路径即可）
string GetAdvIcon(string adv) {
    ReplaceStr(adv, "add:", "");
	return "textures/advancements/add/" + adv + ".png";
}

//获取进度类型（一般不建议修改此函数）
int GetAdvType(string adv) {
	if (ChallengeAdvancements.count(adv)) {
		return 2;
	}
	else if (GoalAdvancements.count(adv)) {
		return 1;
	}
	return 0;
}

//进度是否为隐藏进度（一般不建议修改此函数）
bool GetIsHidden(string adv) {
	if (HiddenAdvancements.count(adv)) {
		return true;
	}
	return false;
}

//获取进度经验奖励（一般不建议修改此函数）
int GetExpReward(string adv) {
	try {
		return ExpRewardJson[adv].get<int>();
	}
	catch (...) {
		return 0;
	}
}

//注册进度（一般不建议修改此函数）
void RegAdvancements() {
	for (auto adv : AllAdvancements) {
		RegNewAdvancement(adv, GetAdvName(adv), GetAdvDescription(adv), GetAdvIcon(adv), GetAdvIcon(adv), GetAdvType(adv), GetIsHidden(adv), GetExpReward(adv));
	}
}

//初始化进度系统（一般不建议修改此函数）
void InitAdvancements() {
	RegClass();
	RegAdvancements();
	LanguageJson.clear();
}