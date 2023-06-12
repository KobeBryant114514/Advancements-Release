/*
* 此文件为全局使用的API头文件
* 一般情况下不需要需改此文件
*/

#include <LoggerAPI.h>
#include <mc/Player.hpp>
#include <RemoteCallAPI.h>

extern Logger logger;
extern nlohmann::json LanguageJson;

extern void InitLanguage();
extern void InitAdvancements();
extern void Listener();

extern std::vector<std::string> AllAdvancements;
extern std::unordered_set<std::string> GoalAdvancements;
extern std::unordered_set<std::string> ChallengeAdvancements;
extern std::unordered_set<std::string> HiddenAdvancements;
extern nlohmann::json ExpRewardJson;
extern std::unordered_set<std::string> RidingList;

extern bool GrantAdvancement(Player* pl, string advid, int exp = 0);
extern bool CheckAdvancement(Player* pl, string advid);
extern void RegNewAdvancementClass(std::string advclass, std::string advclassname, std::string advclassdesc, std::string advicon = "");
extern void RegNewAdvancement(std::string advid, std::string advname, std::string advdesc, std::string iconpath1, std::string iconpath2, int type, bool isHidden, int exp);
extern bool CheckAdvancement(Player* pl, string advid);