#include "Header.h"

//需要添加的进度
std::vector<std::string> AllAdvancements = {
    "add:root",
	"add:hello_world",
    "add:test1",
    "add:test2"
};

//目标进度
std::unordered_set<std::string> GoalAdvancements = {
    "add:test1"
};

//挑战进度
std::unordered_set<std::string> ChallengeAdvancements = {
    "add:test2"
};

//隐藏进度
std::unordered_set<std::string> HiddenAdvancements = {
    "add:test2"
};

//进度的经验奖励（不写默认0经验）
nlohmann::json ExpRewardJson = {
    {"add:hello_world", 100}
};